FROM ubuntu:20.04

RUN apt-get update && apt-get install -y sudo wget make

# install go
RUN wget https://dl.google.com/go/go1.17.5.linux-amd64.tar.gz
RUN sudo tar -C /usr/local -xzf go1.17.5.linux-amd64.tar.gz
RUN echo export PATH=$PATH:/usr/local/go/bin >> ~/.bashrc && /bin/bash -c "source ~/.bashrc"
RUN sudo apt install -y protobuf-compiler
RUN sudo apt install -y golang-goprotobuf-dev

WORKDIR /workspace
