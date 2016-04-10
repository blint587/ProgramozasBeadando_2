cmake_minimum_required(VERSION 3.3)

project(horse_race_balance)

add_definitions(-std=c++11)

add_library(horse_race_balance SHARED  HorseRaceBalance.cpp HorseRaceBalance.h)