cmake_minimum_required(VERSION 3.0)

project(example)

include_directories(.)

add_executable(client
    client/main.c
)

add_executable(server
    server/main.c
)