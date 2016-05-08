project(unittesting)

include_directories(lib/gtest/include/gtest/internal)

add_subdirectory(lib/gtest)
add_subdirectory(unit_test)