#!/bin/bash

DEST_DIR=./build_client

if [ -d $DEST_DIR ]; then
  rm -rf $DEST_DIR
  mkdir $DEST_DIR
else
  mkdir $DEST_DIR
fi

cd build_client
cmake ../client
make
./client
