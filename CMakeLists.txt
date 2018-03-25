cmake_minimum_required(VERSION 2.6)
project(LibMinimalWindow)

include_directories(include)
add_library(minimal_window SHARED
    src/lib_window.cpp
)

add_subdirectory(test)
