cmake_minimum_required(VERSION 3.23)
project(CDataBase C)

set(CMAKE_C_STANDARD 17)

add_executable(CDataBase main.c LinkedList.c goodscanf.c LinkedList.h)
