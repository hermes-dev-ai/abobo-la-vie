cmake_minimum_required(VERSION 3.16)
project(AboboLaVie VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find raylib (install with: brew install raylib or apt install libraylib-dev)
find_package(raylib REQUIRED)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(abobo-la-vie ${SOURCES})
target_include_directories(abobo-la-vie PRIVATE src)
target_link_libraries(abobo-la-vie raylib)

# Windows specific
if(WIN32)
  set_target_properties(abobo-la-vie PROPERTIES WIN32_EXECUTABLE TRUE)
endif()