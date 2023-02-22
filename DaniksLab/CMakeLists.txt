cmake_minimum_required(VERSION 3.23)
project(DaniksLab C)

set(CMAKE_C_STANDARD 11)

add_executable(DaniksLab main.c sorts.h sorts.c tasks.c goodinputs.h goodinputs.c tasks.h menu.c menu.h)
