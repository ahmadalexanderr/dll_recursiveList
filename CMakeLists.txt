cmake_minimum_required(VERSION 3.17)
project(ListLinearRek C)

set(CMAKE_C_STANDARD 99)

add_executable(ListLinearRek mLLR.c LLR.h boolean.h LLR.c)