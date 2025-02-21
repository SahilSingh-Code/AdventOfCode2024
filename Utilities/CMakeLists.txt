# Create a static library named "Utilities"
add_library(Utilities
    Stopwatch.cpp Stopwatch.h
    PrintUtilities.h PrintUtilities.cpp)

# Make the Utilities include directory available to targets that link against this library.
target_include_directories(Utilities PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
