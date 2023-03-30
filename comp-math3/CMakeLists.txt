cmake_minimum_required(VERSION 3.22)
project(comp_math3)

set(CMAKE_CXX_STANDARD 14)

add_executable(comp_math3 main.cpp trapezoid/TrapezoidMethod.cpp trapezoid/TrapezoidMethod.h)
