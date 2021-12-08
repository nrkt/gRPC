cmake_minimum_required(VERSION 3.16.3)

project(gprc)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "limited configs" FORCE)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--no-as-needed -lgrpc++_reflection -Wl,--as-needed -ldl")

find_package(Threads)
find_package(Protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)

set(SOURCE_FILES client.cpp ../codegen/helloworld.grpc.pb.h ../codegen/helloworld.grpc.pb.cc ../codegen/helloworld.pb.cc ../codegen/helloworld.pb.h)

add_executable(client ${SOURCE_FILES})

target_link_libraries(client
        Threads::Threads
        protobuf::libprotobuf
        gRPC::grpc++_unsecure
        gRPC::grpc++_reflection
        ${CMAKE_SHARED_LINKER_FLAGS})
set_target_properties(client PROPERTIES OUTPUT_NAME client)
