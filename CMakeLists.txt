cmake_minimum_required(VERSION 3.25)
project(simplexMethod)

set(CMAKE_CXX_STANDARD 17)

add_executable(simplexMethod main.cpp variable.cpp variable.h equation.cpp equation.h Dictionary.cpp Dictionary.h Utils.cpp Utils.h)
