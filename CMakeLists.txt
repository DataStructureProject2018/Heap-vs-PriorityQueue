cmake_minimum_required(VERSION 3.10)
project(HeapVsPriorityQueue C)

set(CMAKE_C_STANDARD 99)

add_executable(main main.c PriorityQueue/priorityQueue.h)
