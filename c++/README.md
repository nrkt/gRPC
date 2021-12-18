## How to use
```bash
docker-compose up -d
docker-compose exec grpc bash
sh tools/grpc_cpp.sh
mkdir build && cd build
cmake ..
cd server/ && make -j # run bash1
./server              # run bash1
cd client/ && make -j # run bash2
./client              # run bash2
```