cmake_minimum_required(VERSION 3.22)

project(
  msalloc
  VERSION 1.0.0
  LANGUAGES CXX)

include_directories(include)

file(GLOB Dir1_Sources "src/*.cpp")

add_executable(${PROJECT_NAME} ${Dir1_Sources} )

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)