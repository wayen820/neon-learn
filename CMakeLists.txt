cmake_minimum_required(VERSION 3.6.0)
project(myneon VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE release CACHE STRING "Choose the type of build" FORCE)
endif()
#添加android编译选项
add_definitions(-Wall -Wextra -Wno-unused-function)

add_definitions(-fPIC)
if(CMAKE_BUILD_TYPE MATCHES "(Release|RELEASE|release)")
add_definitions(-Ofast)

add_definitions(-ffast-math)
endif()

#添加OpenMP支持
find_package(OpenMP)
if(OpenMP_CXX_FOUND OR OPENMP_FOUND)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

#添加android日志库
find_library( # Sets the name of the path variable.
              log-lib
              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

#message(STATUS -----${CMAKE_MAKE_PROGRAM})
add_executable(test1 test.cpp)
set_property(TARGET test1 PROPERTY LINK_FLAGS "-Wl,--as-needed -Wl,--gc-sections -Wl,--no-undefined -Wl,--strip-all -Wl")

