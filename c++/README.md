## How to use
```bash
docker-compose up -d
docker-compose grpc bash
sh tools/grpc_cpp.sh
sh tools/server_build.sh # (bash1)
sh tools/client_build.sh # (bash2) return -> Greeter received: Hello <name>
```