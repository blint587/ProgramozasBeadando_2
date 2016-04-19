include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runBasicUnitTest
        testHorsRaceBalance.cpp testReadin.cpp ../../read_in/ReadIn.h)

target_link_libraries(runBasicUnitTest gtest gtest_main)
target_link_libraries(runBasicUnitTest horse_race_balance)