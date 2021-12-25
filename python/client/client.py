from __future__ import print_function
import logging
import os
import sys
sys.path.append(os.path.join(os.path.dirname(__file__), '../proto'))
import grpc

import helloworld_pb2
import helloworld_pb2_grpc


def run():
    with grpc.insecure_channel('localhost:50051') as channel:
        stub = helloworld_pb2_grpc.GreeterStub(channel)
        response = stub.SayHello(helloworld_pb2.HelloRequest(name='hoge'))
        print("Greeter client received: " + response.message)

if __name__ == '__main__':
    logging.basicConfig()
    run()
