project(comp_math4)

set(CMAKE_CXX_STANDARD 17)

add_executable(comp_math4 main.cpp NewtonMethod.cpp NewtonMethod.h matplotlib.h)
find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})
target_link_libraries(comp_math4 ${PYTHON_LIBRARIES})