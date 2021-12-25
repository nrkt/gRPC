## How to use
```sh
docker-compose up -d
docker-compose exec grpc bash
cd workspace/
python3 server/server.py # run bash1
python3 client/client.py # run bash2
```