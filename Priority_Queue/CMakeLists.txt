cmake_minimum_required(VERSION 3.27)
project(pq)

set(CMAKE_CXX_STANDARD 17)

add_executable(pq main.cpp
        PriorityQueue.h
        Point.h)
