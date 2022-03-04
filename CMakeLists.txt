cmake_minimum_required(VERSION 3.22)

project(
  msalloc
  VERSION 1.0.0
  LANGUAGES CXX)

include_directories(include)

file(GLOB Dir1_Sources "src/*.cpp")
file(GLOB Dir2_Sources "test/*.cpp")

add_executable(${PROJECT_NAME} ${Dir1_Sources} ${Dir2_Sources})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)