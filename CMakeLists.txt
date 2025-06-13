cmake_minimum_required(VERSION 3.17)
project(Kockasfulu-mk2 VERSION 1.0 LANGUAGES CXX)

# Modern C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Export compile_commands.json for tooling
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Automatically gather all .cpp files in src/
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/src/*.cpp)

# Define the chess INTERFACE target to suppress warnings
add_library(chess INTERFACE)
target_include_directories(chess SYSTEM INTERFACE ${CMAKE_SOURCE_DIR}/include)

# Define your main executable
add_executable(Kockasfulu-mk2 ${SRC_FILES})

# Add include directories (your own headers)
target_include_directories(Kockasfulu-mk2 PRIVATE ${CMAKE_SOURCE_DIR}/src)

# Link chess library as header-only
target_link_libraries(Kockasfulu-mk2 PRIVATE chess)

# Compiler warnings and options (for your code only)
target_compile_options(Kockasfulu-mk2 PRIVATE
    -Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wfloat-equal -Wundef
    -Wpointer-arith -Wcast-align -Wwrite-strings
 -Wcast-qual -Wswitch-default -Wswitch-enum
    -Wunreachable-code -Wformat=2 -Werror
    -Ofast 
    -flto
    # -fsanitize=address -fsanitize=pointer-compare -fsanitize=undefined
    -march=native -mtune=native
    -g
)
