#! /bin/bash

DEST_DIR=./codegen

if [ -d $DEST_DIR ]; then
  rm -rf $DEST_DIR
  mkdir $DEST_DIR
else
  mkdir $DEST_DIR
fi

protoc --go_out=${DEST_DIR} --go_opt=paths=source_relative \
   --go-grpc_out=${DEST_DIR} --go-grpc_opt=paths=source_relative \
   proto/helloworld.proto
 