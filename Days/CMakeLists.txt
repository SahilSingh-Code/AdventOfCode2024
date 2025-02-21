# Create a static library for Day1
add_library(Day1
    Day1.cpp
    Day1.h
)

# Make the current directory available as an include directory for Day1
target_include_directories(Day1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Link the Utilities library to Day1
target_link_libraries(Day1 PUBLIC Utilities)
