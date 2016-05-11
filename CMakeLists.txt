cmake_minimum_required(VERSION 3.3)
project(programozas_elso_beadando)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1")

set(SOURCE_FILES main.cpp Set/SET.h)
add_executable(reception ${SOURCE_FILES})

include_directories(DateTime)
include_directories(Entry)
#include_directories(EntryLister)
include_directories(BaseClass)
include_directories(Reception)
include_directories(Set)

add_subdirectory(DateTime)
add_subdirectory(Entry)
#add_subdirectory(EntryLister)
add_subdirectory(BaseClass)
add_subdirectory(Reception)
add_subdirectory(test)

target_link_libraries(reception
        datetime
        entry
#        lister
        reception_lister)