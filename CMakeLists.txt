if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  message(FATAL_ERROR "Prevented in-tree built. Please create a build directory outside of the project source code and call cmake from there")
endif()

cmake_minimum_required(VERSION 2.6)
project (Tutorial)

# add an option to either use our MathFunctions or standard functions from math.h
option(USE_MYMATH "Use our own implementation of math functions" OFF)

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


# conditionally add MathFunctions library if user needs it
if (USE_MYMATH)
  # source file for mathfunctions library
  include_directories("${MATH_FUNCTIONS_INC_DIR}")

  # include CMakeLists.txt from a library sub-directory
  # let it build for a shared library for us
  add_subdirectory("${MATH_FUNCTIONS}")

  # add MathFunctions to linking library flags
  set(EXTRA_LIBS ${EXTRA_LIBS} ${MATH_FUNCTIONS})

  # append definition to compile flags
  # so we don't have to set/get such value through/from config header
  # but you can do it if you want
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DUSE_MYMATH")
endif (USE_MYMATH)

# build executable
add_executable(Tutorial src/tutorial.cpp)
target_link_libraries(Tutorial ${EXTRA_LIBS})

# install targets
install (TARGETS Tutorial DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/include/TutorialConfig.h"
         DESTINATION include)

# test
# test: does the application run
add_test(Tutorial Tutorial 25)

# test: does it sqrt of 25
add_test(TutorialComp25 Tutorial 25)
set_tests_properties(TutorialComp25 PROPERTIES PASS_REGULAR_EXPRESSION "The square root of 25 is 5")

# test: does it handle negative numbers
add_test(TutorialNegative Tutorial -25)
set_tests_properties(TutorialNegative PROPERTIES PASS_REGULAR_EXPRESSION "The square root of -25 is 0")

# test: does it handle small numbers
add_test(TutorialSmall Tutorial 0.0001)
set_tests_properties(TutorialSmall PROPERTIES PASS_REGULAR_EXPRESSION "The square root of 0.0001 is 0.01")

# test: does the usage message work?
add_test(TutorialUsage Tutorial)
set_tests_properties(TutorialUsage PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*")

enable_testing()
