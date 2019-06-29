cmake_minimum_required(VERSION 3.0.2)
project (MathFunctions)

include_directories(include
                    ../include    # include config header TutorialConfig.h
)

file (GLOB SOURCE_FILES
  ${PROJECT_SOURCE_DIR}/src/MathFunctions.cpp)

add_library(MathFunctions SHARED ${SOURCE_FILES})

# add the install targets
install (TARGETS MathFunctions DESTINATION lib)
install (FILES include/MathFunctions.h DESTINATION include)
