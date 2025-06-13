# Gather all source and header files
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS *.cc)
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS *.hh)

# Define the executable
add_executable(Kockasfulu-mk2 ${SRC_FILES} ${HEADER_FILES})

# Include the external directory for headers like chess.hpp
target_include_directories(Kockasfulu-mk2 PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)
