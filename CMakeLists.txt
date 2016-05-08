cmake_minimum_required(VERSION 3.3)
project(programozas_elso_beadando)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")

set(SOURCE_FILES main.cpp read_in/ReadIn.h)
add_executable(reception ${SOURCE_FILES})

include_directories(DateTime)

add_subdirectory(DateTime)
add_subdirectory(test)

target_link_libraries(reception datetime)