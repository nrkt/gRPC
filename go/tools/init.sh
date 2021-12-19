go mod init example.com/nrkt/hello
go get google.golang.org/grpc
go install google.golang.org/protobuf/cmd/protoc-gen-go@v1.26
go install google.golang.org/grpc/cmd/protoc-gen-go-grpc@v1.1
echo export PATH="$PATH:$(go env GOPATH)/bin" >> ~/.bashrc
