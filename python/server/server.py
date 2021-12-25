import sys
import os
sys.path.append(os.path.join(os.path.dirname(__file__), '../proto'))
from concurrent import futures
import logging

import grpc

import helloworld_pb2
import helloworld_pb2_grpc


class Greeter(helloworld_pb2_grpc.GreeterServicer):

    def SayHello(self, request, context):
        str_out = 'Received %s' % request.name
        sys.stderr.write(str_out + "\n")
        return helloworld_pb2.HelloReply(message=str_out)

def serve():
    sys.stderr.write("Build Server \n")
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    helloworld_pb2_grpc.add_GreeterServicer_to_server(Greeter(), server)
    server.add_insecure_port('[::]:50051')
    server.start()
    server.wait_for_termination()


if __name__ == '__main__':
    logging.basicConfig()
    serve()