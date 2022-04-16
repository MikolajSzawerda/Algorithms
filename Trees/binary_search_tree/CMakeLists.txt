cmake_minimum_required(VERSION 3.0.0)
project(bst VERSION 0.1.0)

set(SOURCES BSTree.h BSTree.cpp)

add_executable(bst main.cpp ${SOURCES})


