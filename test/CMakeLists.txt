cmake_minimum_required(VERSION 3.0.0)
project(TestApp VERSION 0.0.0)

#set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -O2")

include(CTest)
enable_testing()

find_package(SDL2 REQUIRED)

add_executable(TestApp main.cpp)

include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(TestApp
    ${SDL2_LIBRARIES}
    pthread
)    

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
