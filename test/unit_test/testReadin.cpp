#include "gtest/gtest.h"
#include "../../read_in/ReadIn.h"
#include <sstream>
#include <iostream>
#include <vector>

// helper functions

bool correct_int(int);

bool correct_int(int i){
    return true;
};


class TestReadin : public testing::Test {

};

// all tests will us a stringstream as an input
TEST_F(TestReadin, test_read_in_int){
    std::stringstream s;
    s << 1;
    int res = read_in(s, correct_int, "");
    EXPECT_EQ(1, res);
}

TEST_F(TestReadin, test_read_in_on_correct_input){
    std::stringstream s;
    s << "1 2 3 ";
    std::vector<int> resvect;
    std::vector<int> exp = {1, 2, 3};
    read_in_one(s, correct_int, "", resvect);
    read_in_one(s, correct_int, "", resvect);
    read_in_one(s, correct_int, "", resvect);
    EXPECT_EQ(exp, resvect);
}

TEST_F(TestReadin, test_read_in_on_incorrect_input_end){
    // expected to ignore incorrect input
    std::stringstream s;
    s << "1 2 3 a ";
    std::vector<int> resvect;
    std::vector<int> exp = {1, 2, 3};
    read_in_one(s, correct_int, "", resvect);
    read_in_one(s, correct_int, "", resvect);
    read_in_one(s, correct_int, "", resvect);
    read_in_one(s, correct_int, "", resvect);
    EXPECT_EQ(exp, resvect);
}

// not testable because s.clear() the sstream
/*TEST_F(TestReadin, test_read_in_on_incorrect_input_begining){
    // expected to ignore incorrect input
    std::stringstream s;
    s << "a 1 2 3 ";
    std::vector<int> resvect;
    std::vector<int> exp = {1, 2, 3};
    read_in_one(s, correct_int, "", resvect);
    read_in_one(s, correct_int, "", resvect);
    read_in_one(s, correct_int, "", resvect);
    read_in_one(s, correct_int, "", resvect);
    EXPECT_EQ(exp, resvect);
}*/

TEST_F(TestReadin, test_read_in_vector_correct_input){
    std::stringstream s;
    s << "1 2 3 ";
    std::vector<int> resvect = read_in_vector(s, correct_int, "");
    std::vector<int> exp = {1, 2, 3};
    EXPECT_EQ(exp, resvect);
}

TEST_F(TestReadin, test_read_in_vector_incorrect_input_end){
    std::stringstream s;
    s << "1 2 3 a ";
    std::vector<int> resvect = read_in_vector(s, correct_int, "");
    std::vector<int> exp = {1, 2, 3};
    EXPECT_EQ(exp, resvect);
}