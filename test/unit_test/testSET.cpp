#include "gtest/gtest.h"
#include "SET.h"

class TestSET: public testing::Test{

};

TEST_F(TestSET, testing_push){
    SET<int> s;
    s.push(1);
    EXPECT_EQ("[\n1\n]", s.toString());
}

// test set invariant that a set cannot have duplicate elements
TEST_F(TestSET, testing_push_adding_containing_element){

    SET<int> s;
    s.push(1);
    s.push(1);
    EXPECT_EQ("[\n1\n]", s.toString());
}

TEST_F(TestSET, testing_pop_valid_takeout){
    SET<int> s;
    s.push(1);
    s.pop(1);
    EXPECT_EQ("[\n]", s.toString());
}

TEST_F(TestSET, testing_pop_invalid_takeout){
    SET<int> s;
    s.push(1);
    s.pop(2);
    EXPECT_EQ("[\n1\n]", s.toString());
}

TEST_F(TestSET, testing_has_ture){
    SET<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    EXPECT_TRUE(s.has(1)); // begining
    EXPECT_TRUE(s.has(2)); // midle
    EXPECT_TRUE(s.has(3)); // end
}

TEST_F(TestSET, testing_has_false){
    SET<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    EXPECT_FALSE(s.has(4));
}

TEST_F(TestSET, testing_size){
    SET<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    EXPECT_EQ(3, s.size());
}
