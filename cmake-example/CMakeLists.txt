cmake_minimum_required(VERSION 3.0)
project(meuProjeto)

include_directories("${CMAKE_SOURCE_DIR}/src")
include_directories("${CMAKE_SOURCE_DIR}/include")

file(GLOB SOURCES "src/*.cpp")

#compile to debug
#set(CMAKE_BUILD_TYPE Debug)

add_executable(programa.out main.cpp ${SOURCES})
#add_executable(programa.out main.cpp src/Matematica.cpp)
