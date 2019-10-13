cmake_minimum_required(VERSION 3.13.4)
project(01_cmake)

include_directories(~/oop_2019_g2/googletest/googletest/include)
link_directories(~/oop_2019_g2/googletest/build/lib)

add_executable(01_cmake main.cpp main.h) #plik wykonywalny dla maina
add_executable(01_cmake_test test.cpp main.h) #plik wykonywalny dla testow

add_library(utiks STATIC main.cpp test.cpp) #dodanie biblioteki statycznej, po tym buduje "utiks" by uzyskac w cmake-build-debug biblioteke libutiks.a

find_library(utiks cmake-build-debug)

target_link_libraries(01_cmake utiks pthread)
target_link_libraries(01_cmake_test gtest gtest_main utiks pthread)

