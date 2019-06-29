# cmake_example
Example project using CMake as build system. Included executable linking with shared library with some other configurable features of CMake.

It follows along with [cmake-tutorial](https://cmake.org/cmake-tutorial/) on official website of
CMake itself but with modified and improvements.

# Usage

* Create a build directory i.e. `build` or any desired name
* `cd` into such directory, then `cmake ..`
* Now you can inspect `CMakeLists.txt`, `MathFunctions/CMakeLists.txt` and its effect towards the result of the build operation

# Technical Note

* Prevent in-source build thus you can not proceed building at project root directory, only way is to create another directory then call `cmake` from there.
* Use `set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DUSE_MYMATH")` to support CMake's option which is configurable by users `USE_MYMATH`. It doesn't use `#cmakedefine` by choice, but you can still use it.
* remember to add `enable_testing()` after adding test cases, otherwise there will be no `test` target for `Makefile`.

# License
This project licensed under [MIT](https://github.com/haxpor/cmake_example/blob/master/LICENSE), Wasin Thonkaew
