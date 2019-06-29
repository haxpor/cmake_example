cmake_minimum_required(VERSION 2.6)
project (MathFunctions)

include_directories("${PROJECT_SOURCE_DIR}/include")

file (GLOB SOURCE_FILES
  ${PROJECT_SOURCE_DIR}/src/MathFunctions.cpp)

add_library(MathFunctions SHARED ${SOURCE_FILES})
