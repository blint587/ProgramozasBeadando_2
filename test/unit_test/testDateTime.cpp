#include "gtest/gtest.h"
#include "DateTime.h"

class TestDateTime: public testing::Test{

};
TEST_F(TestDateTime, testing_constructir){
    DateTime d = DateTime("18:45");
    EXPECT_EQ("18:45", d.toString());
}

TEST_F(TestDateTime, testing_constructir_fails){
    EXPECT_THROW(DateTime("1845"), DateTime::DateTimeInitializationException);
}

TEST_F(TestDateTime, testing_lt){
    DateTime d1 = DateTime("18:45");
    DateTime d2 = DateTime("17:45");

    EXPECT_TRUE(d2 < d1);
}

TEST_F(TestDateTime, testing_le_less){
    DateTime d1 = DateTime("18:45");
    DateTime d2 = DateTime("17:45");

    EXPECT_TRUE(d2 <= d1);
}

TEST_F(TestDateTime, testing_le_equal){
    DateTime d1 = DateTime("18:45");
    DateTime d2 = DateTime("18:45");

    EXPECT_TRUE(d2 <= d1);
}

TEST_F(TestDateTime, testing_eq_equal){
    DateTime d1 = DateTime("18:45");
    DateTime d2 = DateTime("18:45");

    EXPECT_TRUE(d2 == d1);
}

TEST_F(TestDateTime, testing_ne){
    DateTime d1 = DateTime("18:45");
    DateTime d2 = DateTime("15:45");

    EXPECT_TRUE(d2 != d1);
}

TEST_F(TestDateTime, testing_gt){
    DateTime d1 = DateTime("18:45");
    DateTime d2 = DateTime("15:45");

    EXPECT_TRUE(d1 > d2);
}

TEST_F(TestDateTime, testing_ge_greater){
    DateTime d1 = DateTime("18:45");
    DateTime d2 = DateTime("15:45");

    EXPECT_TRUE(d1 >= d2);
}

TEST_F(TestDateTime, testing_ge_equal){
    DateTime d1 = DateTime("18:45");
    DateTime d2 = DateTime("18:45");
    EXPECT_TRUE(d1 >= d2);
}

TEST_F(TestDateTime, testing_compare_false){
    DateTime d1 = DateTime("18:45");
    DateTime d2 = DateTime("18:45");
    EXPECT_FALSE(d1 < d2);
}

TEST_F(TestDateTime, testing_type_cast_and_compare){
    DateTime d2 = DateTime("18:45");
    EXPECT_TRUE("19:45" >= d2);
}


