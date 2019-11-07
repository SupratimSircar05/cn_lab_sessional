cmake_minimum_required(VERSION 3.15)
project(cn_sessional C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(cn_sessional_c client.c)
add_executable(cn_sessional_s server.c)
