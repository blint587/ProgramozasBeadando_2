#include "Reception.h"
#include "gtest/gtest.h"


class TestReception: public testing::Test{

};

TEST_F(TestReception, simple_check){
    std::stringstream f;

    f << "10:30 Gipsz_Jakab 1234567A 10:45\n"
         "08:35 Gyanus_Moric 1x1x1x1x1x\n"
         "08:35 Gyanus_Moric 1x1x1x1x1x 08:10\n"
         "08:35 Gyanus_Moric 1x1x1x1x1x\n"
         "08:35 Gyanus_Moric 1x1x1x1x1x 08:10\n"
         "08:35 Gyanus_Moric 1x1x1x1x1x\n"
         "08:45 Szer_Elek 33332222\n"
         "08:45 Szer_Elek 33332222 09:15\n"
         "08:45 Szer_Elek 33332222 09:15\n"
         "20:15 csak_tavozo 45879 20:15\n"
         "20:15 csak_belepo 45872\n"
         "20:15 csak_belepo 45872\n"
         "14:15 valaki_mas 65465468\n"
         "14:15 valaki_mas 65465468 15:17\n"
         "14:15 valaki_mas 65465468\n"
         "10:15 h_gy 4444444\n"
         "10:15 h_gy 4444444 15:15\n"
         "10:15 h_gy 4444444 15:15";

    Reception r = Reception(f);

    EXPECT_EQ(3,r.nr_people_in());
    EXPECT_EQ("1 10:30 Gipsz_Jakab 1234567A 10:45\n9 8:45 Szer_Elek 33332222 9:15\n10 20:15 csak_tavozo 45879 20:15\n12 20:15 csak_belepo 45872\n18 10:15 h_gy 4444444 15:15\n",
              r.wrong_entrys());
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
