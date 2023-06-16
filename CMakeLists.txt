cmake_minimum_required(VERSION 3.23)
project(Farkle)

set(CMAKE_CXX_STANDARD 14)

add_executable(Farkle main.cpp Turn.cpp Turn.h Option.cpp Option.h Player.cpp Player.h)
