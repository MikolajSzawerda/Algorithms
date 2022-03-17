cmake_minimum_required(VERSION 3.11.0)
project(casino VERSION 0.1.0)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)



include(FetchContent)
FetchContent_Declare(
   googletest
   GIT_REPOSITORY      https://github.com/google/googletest.git
   GIT_TAG main
)
FetchContent_MakeAvailable(googletest)


set(SOURCES Median.h Median.cpp)
add_executable(select main.cpp ${SOURCES})
add_executable(test_select testSelect.cpp ${SOURCES})

target_link_libraries(test_select PUBLIC gtest_main)

