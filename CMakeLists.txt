cmake_minimum_required(VERSION 3.7)

project(MyProject)

# flags
set(CMAKE_CXX_STANDARD 11)

# source files
set(SOURCE_FILES
    src/source_file.cpp
)

# build the library
include_directories(src/)
add_library(myproject_lib ${SOURCE_FILES})

# build an exe
add_executable(main src/main.cpp)

# link the exe with the library
target_link_libraries(main myproject_lib)