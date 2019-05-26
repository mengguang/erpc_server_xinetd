cmake_minimum_required(VERSION 3.10)
project(erpc_server_xinetd C)

set(CMAKE_C_STANDARD 11)

add_executable(erpc_server_xinetd main.c erpc.c erpc.h)