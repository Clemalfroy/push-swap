cmake_minimum_required(VERSION 3.9)
project(checker)

set(CMAKE_CXX_STANDARD 11)
file(GLOB_RECURSE HDRS ${HDRS} include/*.h)
file(GLOB_RECURSE SRCS ${SRCS} src/*.c)
add_executable(checker ${SRCS} ${HDRS})
target_include_directories(checker PUBLIC include)