FROM ubuntu:20.04

RUN apt-get update && apt-get install -y sudo wget make

RUN sudo apt update && sudo apt -y upgrade && apt install -y python3-pip

RUN pip install grpcio-tools==1.26.0

WORKDIR /workspace
