cmake_minimum_required(VERSION 3.10)
project(Main VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_subdirectory(lib)
add_executable(Main main.cpp)
target_link_libraries(Main MyLib)

