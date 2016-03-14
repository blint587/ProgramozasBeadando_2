cmake_minimum_required(VERSION 3.3)
project(programozas_elso_beadando)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(loverseny ${SOURCE_FILES} )

include_directories(horse_race_balance)

add_subdirectory(horse_race_balance)
add_subdirectory(test)

target_link_libraries(loverseny horse_race_balance)