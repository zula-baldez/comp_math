cmake_minimum_required(VERSION 3.22)
project(comp_math2)

set(CMAKE_CXX_STANDARD 20)

add_executable(comp_math2 main.cpp bisection/BisectionMethod.cpp bisection/BisectionMethodImpl.h util/DoubleComparator.h secant/SecantMethod.cpp secant/SecantMethod.h util/AnsStruct.h CompMethodAbstr.h iterations/IterationMethod.cpp iterations/IterationMethod.h)
