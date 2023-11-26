cmake_minimum_required(VERSION 3.10)
project(set_map)

set(CMAKE_CXX_STANDARD 17)

add_executable(set_map main.cpp
        Trie.h
        BinaryTree.h)
