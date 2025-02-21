cmake_minimum_required(VERSION 3.8)
project("AdventOfCode")

# Include directories
include_directories(${CMAKE_SOURCE_DIR})

# Define the source directory variable for all code so the input files can be read
add_compile_definitions(INPUTS_DIR=\"${CMAKE_SOURCE_DIR}/Inputs\")

# Include the Utilities subdirectory (this will process Utilities/CMakeLists.txt)
add_subdirectory(Utilities)
add_subdirectory(Days)

# Create the Advent_Day1 executable and link it to the Utilities library
add_executable(RunDay1 "Executables/RunDay1.cpp")
target_link_libraries(RunDay1 PRIVATE Day1)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET RunDay1 PROPERTY CXX_STANDARD 20)
endif()