cmake_minimum_required(VERSION 3.9)
set(BUILD_SHARED_LIBS OFF)
set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_STATIC_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")

set(checker_INC_DIR ${CMAKE_CURRENT_LIST_DIR}/include)
set(checker_SRC_DIR ${CMAKE_CURRENT_LIST_DIR}/src)
set(checker_TEST_DIR ${CMAKE_CURRENT_LIST_DIR}/test)

add_subdirectory(libft)

set(CMAKE_C_FLAGS "")
set(CMAKE_C_FLAGS_DEBUG "")
set(CMAKE_C_FLAGS_RELEASE "")

set(checker_HDR ${checker_INC_DIR})
file(GLOB_RECURSE checker_HDRS ${checker_HDRS} ${checker_INC_DIR}/*.h)
file(GLOB_RECURSE checker_SRCS ${checker_SRCS} ${checker_SRC_DIR}/*.c)
file(GLOB_RECURSE checker_SRCS ${checker_SRCS} ${checker_SRC_DIR}/*.h)

add_executable(checker ${checker_HDR} ${checker_HDRS} ${checker_SRCS})
set_property(TARGET checker PROPERTY C_STANDARD 90)
target_include_directories(checker PUBLIC ${checker_INC_DIR})
target_link_libraries(checker PUBLIC debug ft)

target_compile_definitions(checker
        PRIVATE $<$<CONFIG:Debug>:DEBUG>$<$<CONFIG:Release>:NDEBUG>)
if (MSVC)
    target_compile_options(checker
            PRIVATE /MT$<$<CONFIG:Debug>:d> /Oy /W3
            PRIVATE /D_CRT_SECURE_NO_WARNINGS /Dinline=__inline
            PRIVATE /O$<$<CONFIG:Debug>:d>$<$<CONFIG:Release>:x>)
else ()
    target_compile_options(checker
            PRIVATE -Wall -Werror -Wextra
            PRIVATE -O$<$<CONFIG:Debug>:0 -g3>$<$<CONFIG:Release>:3>)
endif ()
