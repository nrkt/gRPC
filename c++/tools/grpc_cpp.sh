#! /bin/bash

DEST_DIR=./codegen

if [ -d $DEST_DIR ]; then
  rm -rf $DEST_DIR
  mkdir $DEST_DIR
else
  mkdir $DEST_DIR
fi

protoc \
 --proto_path=./proto \
 --grpc_out=${DEST_DIR} --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` ./proto/*.proto

protoc \
 --proto_path=./proto \
 --cpp_out=${DEST_DIR} ./proto/*.proto
