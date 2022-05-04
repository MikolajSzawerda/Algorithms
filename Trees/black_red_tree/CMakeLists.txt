cmake_minimum_required(VERSION 3.11.0)
project(rbtree VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
FetchContent_Declare(
   googletest
   GIT_REPOSITORY      https://github.com/google/googletest.git
   GIT_TAG main
)
FetchContent_MakeAvailable(googletest)


# set(SOURCES src/RBTree.h src/RBTree.cpp src/Set.cpp src/Set.h)
set(SOURCES src/RBTree.h)

add_executable(rbtree main.cpp ${SOURCES})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/tests/numbers DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(testApp tests/testTree.cpp ${SOURCES})
target_link_libraries(testApp PUBLIC gtest_main)