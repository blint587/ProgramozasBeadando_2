include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runBasicUnitTest
        test.cpp)

target_link_libraries(runBasicUnitTest gtest gtest_main)
target_link_libraries(runBasicUnitTest horse_race_balance)