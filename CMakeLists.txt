# Minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Project definition
project(SpaceInvaders C)

# Set SDL3 include and library directories
set(SDL3_INCLUDE_DIR "/opt/homebrew/opt/sdl3/include")
set(SDL3_LIBRARY_DIR "/opt/homebrew/opt/sdl3/lib")

# Set SDL3_ttf include and library directories
set(SDL3_TTF_INCLUDE_DIR "/opt/homebrew/opt/sdl3_ttf/include")
set(SDL3_TTF_LIBRARY_DIR "/opt/homebrew/opt/sdl3_ttf/lib")

# Add include directories
include_directories(${SDL3_INCLUDE_DIR})
include_directories(${SDL3_TTF_INCLUDE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/src)

# Define source files
file(GLOB_RECURSE SOURCES 
    "${CMAKE_SOURCE_DIR}/src/*.c"
)

# Add the executable target
add_executable(space_invaders ${SOURCES})

# Link the SDL3 and SDL3_ttf libraries
target_link_libraries(space_invaders 
    ${SDL3_LIBRARY_DIR}/libSDL3.dylib
    ${SDL3_TTF_LIBRARY_DIR}/libSDL3_ttf.dylib
)

# Copy assets to the build directory (uncomment when you have assets)
# file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})

# Set C standard (C11 is recommended for modern C projects)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Add compiler warnings
if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(space_invaders PRIVATE -Wall -Wextra -pedantic)
endif()