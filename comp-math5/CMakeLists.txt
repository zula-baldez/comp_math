cmake_minimum_required(VERSION 3.24)
project(comp_math5)

set(CMAKE_CXX_STANDARD 17)

add_executable(comp_math5 main.cpp MilneMethod.cpp MilneMethod.h matplotlib.h)
find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})
target_link_libraries(comp_math5 ${PYTHON_LIBRARIES})