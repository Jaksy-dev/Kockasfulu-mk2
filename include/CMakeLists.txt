# Header-only interface library
add_library(chess INTERFACE)

# Mark the include directory as SYSTEM to suppress warnings
target_include_directories(chess SYSTEM INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
