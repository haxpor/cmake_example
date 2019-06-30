# See cross compile information at https://gitlab.kitware.com/cmake/community/wikis/doc/cmake/CrossCompiling#the-toolchain-file

# set the name of the target system to build for
set(CMAKE_SYSTEM_NAME Windows)

# whether build for 32 or 64 bit
# build for 32 bit by default
option(BUILD_64 "Build for 64 bit executable" OFF)

if (BUILD_64)
  # Build for 64 bit
  set(COMPILER_PREFIX "x86_64-w64-mingw32")
  # print message to console
  message(STATUS "Build 64-bit Windows executable")
else ()
  # Build for 32 bit
  # set prefix of cross compiler toolchain
  set(COMPILER_PREFIX "i686-w64-mingw32")
  # print message to console
  message(STATUS "Build 32-bit Windows executable")
endif (BUILD_64)

# specify cross compiler for c, and c++ compiler
set(CMAKE_C_COMPILER ${COMPILER_PREFIX}-gcc)
set(CMAKE_CXX_COMPILER ${COMPILER_PREFIX}-g++)

# set according to what suggested in cross compile guideline
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
