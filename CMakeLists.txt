cmake_minimum_required(VERSION 2.6)
project (Tutorial)

# version number
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

# name of mathfunctions library
set (MATH_FUNCTIONS "MathFunctions")
set (MATH_FUNCTIONS_SRC_DIR "${PROJECT_SOURCE_DIR}/${MATH_FUNCTIONS}/src")
set (MATH_FUNCTIONS_INC_DIR "${PROJECT_SOURCE_DIR}/${MATH_FUNCTIONS}/include")

# configure a header file to pass some of the CMake settings to the source code
# note: PROJECT_SOURCE_DIR is the root directory of the project
configure_file (
  "${PROJECT_SOURCE_DIR}/include/TutorialConfig.h.in"
  "${PROJECT_BINARY_DIR}/include/TutorialConfig.h"
  )

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
# note: PROJECT_BINARY_DIR is the build directory
include_directories("${PROJECT_BINARY_DIR}/include")

# source file for mathfunctions library
include_directories("${MATH_FUNCTIONS_INC_DIR}")

# include CMakeLists.txt from a library sub-directory
# let it build for a shared library for us
add_subdirectory("${MATH_FUNCTIONS}")

# build executable
add_executable(Tutorial src/tutorial.cpp)
target_link_libraries(Tutorial ${MATH_FUNCTIONS})
