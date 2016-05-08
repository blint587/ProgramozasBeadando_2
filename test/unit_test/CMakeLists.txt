include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runBasicUnitTest run_unit_tests.cpp testDateTime.cpp testDateTime.h)

target_link_libraries(runBasicUnitTest gtest gtest_main)
target_link_libraries(runBasicUnitTest datetime)