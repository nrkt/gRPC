#include <iostream>
#include <string>
#include <map>
#include <vector>

#include <grpc/grpc.h>
#include <grpcpp/channel.h>
#include <grpcpp/client_context.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>
#include "../codegen/helloworld.pb.h"
#include "../codegen/helloworld.grpc.pb.h"


class GreeterClient {
 public:
  GreeterClient(std::shared_ptr<grpc::Channel> channel)
      : stub_(helloworld::Greeter::NewStub(channel)) {}

  // Assembles the client's payload, sends it and presents the response back
  // from the server.
  std::string SayHello(const std::string& user) {
    // Data we are sending to the server.
    helloworld::HelloRequest request;
    request.set_name(user);

    // Container for the data we expect from the server.
    helloworld::HelloReply reply;

    // Context for the client. It could be used to convey extra information to
    // the server and/or tweak certain RPC behaviors.
    grpc::ClientContext context;

    // Overwrite the call's compression algorithm to DEFLATE.
    context.set_compression_algorithm(GRPC_COMPRESS_DEFLATE);

    // The actual RPC.
    grpc::Status status = stub_->SayHello(&context, request, &reply);

    // Act upon its status.
    if (status.ok()) {
      return reply.message();
    } else {
      std::cout << status.error_code() << ": " << status.error_message()
                << std::endl;
      return "RPC failed";
    }
  }

 private:
  std::unique_ptr<helloworld::Greeter::Stub> stub_;
};

int main(int argc, char** argv) {
  // Instantiate the client. It requires a channel, out of which the actual RPCs
  // are created. This channel models a connection to an endpoint (in this case,
  // localhost at port 50051). We indicate that the channel isn't authenticated
  // (use of InsecureChannelCredentials()).
  grpc::ChannelArguments args;
  // Set the default compression algorithm for the channel.
  args.SetCompressionAlgorithm(GRPC_COMPRESS_GZIP);
  GreeterClient greeter(grpc::CreateCustomChannel(
      "localhost:50051", grpc::InsecureChannelCredentials(), args));
  std::string user("hoge");
  std::string reply = greeter.SayHello(user);
  std::cout << "Greeter received: " << reply << std::endl;

  return 0;
}
