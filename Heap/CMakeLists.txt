cmake_minimum_required(VERSION 3.0.0)
project(heap VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(PROJECT_SOURCES heap.h heap.cpp)

add_executable(heap main.cpp ${PROJECT_SOURCES} )


# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
