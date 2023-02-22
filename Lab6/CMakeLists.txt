cmake_minimum_required(VERSION 3.23)
project(Lab6 C)

set(CMAKE_C_STANDARD 11)
set(Headers goodinputs.h)

add_executable(Lab6 main.c goodinputs.c diffrent_sorts.c diffrent_sorts.h task1.c task2.c tasks.h all_for_arrays.c all_for_arrays.h menu.c)
