include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runBasicUnitTest testDateTime.cpp testReception.cpp testSET.cpp)

target_link_libraries(runBasicUnitTest gtest gtest_main)
target_link_libraries(runBasicUnitTest datetime)
target_link_libraries(runBasicUnitTest reception_lister)