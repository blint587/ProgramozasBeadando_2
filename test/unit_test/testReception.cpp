#include "Reception.h"
#include "gtest/gtest.h"


class TestReception: public testing::Test{

};

TEST_F(TestReception, midle_of_the_series){
    std::stringstream f;

    f << "10:30 Gipsz_Jakab 1234567A 10:45\n"
         "08:35 Gyanus_Moric 1x1x1x1x1x\n"
         "08:35 Gyanus_Moric 1x1x1x1x1x 08:45\n"
         "08:55 Gyanus_Moric 1x1x1x1x1x\n"
         "08:45 Szer_Elek 33332222\n"
         "08:45 Szer_Elek 33332222 09:15\n";

    Reception r = Reception(f);

    EXPECT_EQ(1,r.nr_people_in());
    EXPECT_EQ("[\n08:55 Gyanus_Moric 1x1x1x1x1x\n]",
              r.wrong_entrys());
}

TEST_F(TestReception, one_element){
    std::stringstream f;

    f << "08:35 Gyanus_Moric 1x1x1x1x1x\n";


    Reception r = Reception(f);

    EXPECT_EQ(1,r.nr_people_in());
    EXPECT_EQ("[\n08:35 Gyanus_Moric 1x1x1x1x1x\n]",
              r.wrong_entrys());
}

TEST_F(TestReception, beginig_of_the_list){
    std::stringstream f;

    f << "08:35 Gyanus_Moric 1x1x1x1x1x\n"
         "08:45 Valaki_Mas aaaaaaa\n"
         "08:45 Valaki_Mas aaaaaaa 17:45\n";


    Reception r = Reception(f);

    EXPECT_EQ(1, r.nr_people_in());
    EXPECT_EQ("[\n08:35 Gyanus_Moric 1x1x1x1x1x\n]",
              r.wrong_entrys());
}

TEST_F(TestReception, end_of_the_list){
    std::stringstream f;


    f <<    "08:45 Valaki_Mas aaaaaaa\n"
            "08:45 Valaki_Mas aaaaaaa 17:45\n"
            "08:35 Gyanus_Moric 1x1x1x1x1x\n";

    Reception r = Reception(f);

    EXPECT_EQ(1, r.nr_people_in());
    EXPECT_EQ("[\n08:35 Gyanus_Moric 1x1x1x1x1x\n]",
              r.wrong_entrys());
}

TEST_F(TestReception, multimple_entries_to_find){
    std::stringstream f;


    f <<    "08:45 Valaki_Mas aaaaaaa\n"
            "08:45 Valaki_Mas aaaaaaa 17:45\n"
            "08:35 Gyanus_Moric 1x1x1x1x1x\n"
            "04:45 Koran_Kelo ccccccccc\n";

    Reception r = Reception(f);

    EXPECT_EQ(2, r.nr_people_in());
    EXPECT_EQ("[\n08:35 Gyanus_Moric 1x1x1x1x1x\n04:45 Koran_Kelo ccccccccc\n]",
              r.wrong_entrys());
}

TEST_F(TestReception, no_entries_to_find){
    std::stringstream f;


    f <<    "08:45 Valaki_Mas aaaaaaa\n"
            "08:45 Valaki_Mas aaaaaaa 17:45\n";

    Reception r = Reception(f);

    EXPECT_EQ(0, r.nr_people_in());
    EXPECT_EQ("[\n]",
              r.wrong_entrys());
}

TEST_F(TestReception, empty_input){
    std::stringstream f;


    f <<  "";

    Reception r = Reception(f);

    EXPECT_EQ(0, r.nr_people_in());
    EXPECT_EQ("[\n]",
              r.wrong_entrys());
}





int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
