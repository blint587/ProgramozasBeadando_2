#include "gtest/gtest.h"
#include <vector>
#include <HorseRaceBalance.h>


class TestHorseRaceBalance : public testing::Test {

};


TEST_F(TestHorseRaceBalance, test_initiating_with_empty_list_1){
    // initializing with empty list
    std::vector<double> s = {};
    HorseRaceBalance hr = HorseRaceBalance(s);
    EXPECT_FALSE(hr.won_affter_loisng_(1));
    EXPECT_EQ(0., hr.balance());
}

TEST_F(TestHorseRaceBalance, test_checking_constructor_equality){
    // by default the constructor initializes the class so that 0 is a loss
    // the test checks this
    std::vector<double> s = {0.,2.,3.};
    HorseRaceBalance hr1 = HorseRaceBalance(s);
    HorseRaceBalance hr2 = HorseRaceBalance(s, true);
    EXPECT_EQ(hr1.balance(), hr2.balance());
    EXPECT_EQ(hr1.won_affter_loisng_(1), hr2.won_affter_loisng_(1));

}

TEST_F(TestHorseRaceBalance, test_checking_constructor_inequality){
    // by default the constructor initializes the class so that 0 is a loss
    // if initializeddifferentlyly it should give a different resault
    std::vector<double> s = {0.,2.,3.};
    HorseRaceBalance hr1 = HorseRaceBalance(s);
    HorseRaceBalance hr2 = HorseRaceBalance(s, false);
    EXPECT_EQ(hr1.balance(), hr2.balance());
    EXPECT_NE(hr2.won_affter_loisng_(1), hr1.won_affter_loisng_(1));



}


// all tests below assumes that zero is a loss
TEST_F(TestHorseRaceBalance, test_initiating_with_empty_list_2){
    //
    std::vector<double> s = {};
    HorseRaceBalance hr = HorseRaceBalance(s, true);
    EXPECT_FALSE(hr.won_affter_loisng_(1));
    EXPECT_EQ(0., hr.balance());
}

TEST_F(TestHorseRaceBalance, test_initiating_with_list_size_of_one_loss_1){
    //
    std::vector<double> s = {-1.};
    HorseRaceBalance hr = HorseRaceBalance(s, true);
    EXPECT_FALSE(hr.won_affter_loisng_(1));
    EXPECT_EQ(-1., hr.balance());
}

TEST_F(TestHorseRaceBalance, test_initiating_with_list_size_of_one_loss_2){
    //
    std::vector<double> s = {0.};
    HorseRaceBalance hr = HorseRaceBalance(s, true);
    EXPECT_FALSE(hr.won_affter_loisng_(1));
    EXPECT_EQ(0., hr.balance());
}

TEST_F(TestHorseRaceBalance, test_won_affter_loisng__always_lost_1){
    //
    std::vector<double> s = {0.,0.,0.,0.};
    HorseRaceBalance hr = HorseRaceBalance(s, true);
    EXPECT_FALSE(hr.won_affter_loisng_(3));

}

TEST_F(TestHorseRaceBalance, test_won_affter_loisng__always_lost_2){
    //
    std::vector<double> s = {-1.,-3.,-5.,-7.};
    HorseRaceBalance hr = HorseRaceBalance(s, true);
    EXPECT_FALSE(hr.won_affter_loisng_(3));

}

TEST_F(TestHorseRaceBalance, test_won_affter_loisng__always_won_1){
    //
    std::vector<double> s = {1.,3.,5.,7.};
    HorseRaceBalance hr = HorseRaceBalance(s, true);
    EXPECT_FALSE(hr.won_affter_loisng_(1));

}

TEST_F(TestHorseRaceBalance, test_won_affter_loisng__always_won_2){
    //
    std::vector<double> s = {1.,3.,5.,7.};
    HorseRaceBalance hr = HorseRaceBalance(s, true);
    EXPECT_FALSE(hr.won_affter_loisng_(4));

}

TEST_F(TestHorseRaceBalance, test_won_affter_loisng_over_indexing_1){
    //
    std::vector<double> s = {1.,3.,5.,7.};
    HorseRaceBalance hr = HorseRaceBalance(s, true);
    EXPECT_FALSE(hr.won_affter_loisng_(5));

}

TEST_F(TestHorseRaceBalance, test_won_affter_loisng_over_indexing_2){
    //
    std::vector<double> s = {-1.,-3.,-5.,-7.};
    HorseRaceBalance hr = HorseRaceBalance(s, true);
    EXPECT_FALSE(hr.won_affter_loisng_(5));

}


TEST_F(TestHorseRaceBalance, test_won_after_lossing_begining_of_the_list_1){
    std::vector<double> s = {-1.,-2., 1., 2.};
    HorseRaceBalance hr = HorseRaceBalance(s, true);
    EXPECT_TRUE(hr.won_affter_loisng_(2));
}

TEST_F(TestHorseRaceBalance, test_won_after_lossing_begining_of_the_list_2){
    std::vector<double> s = {0.,-2., 1., 2.};
    HorseRaceBalance hr = HorseRaceBalance(s, true);
    EXPECT_TRUE(hr.won_affter_loisng_(2));

}

TEST_F(TestHorseRaceBalance, test_won_after_lossing_begining_of_the_list_3){
    std::vector<double> s = {0.,0., 1., 2.};
    HorseRaceBalance hr = HorseRaceBalance(s, true);
    EXPECT_TRUE(hr.won_affter_loisng_(2));
}

TEST_F(TestHorseRaceBalance, test_won_after_lossing_begining_of_the_list_4){
    std::vector<double> s = {-1.,0., 1., 2.};
    HorseRaceBalance hr = HorseRaceBalance(s, true);
    EXPECT_TRUE(hr.won_affter_loisng_(2));
}

TEST_F(TestHorseRaceBalance, test_won_after_lossing_begining_of_the_list_5){
    std::vector<double> s = {-1., 1., 2.};
    HorseRaceBalance hr = HorseRaceBalance(s, true);
    EXPECT_TRUE(hr.won_affter_loisng_(1));
}

TEST_F(TestHorseRaceBalance, test_won_after_lossing_begining_of_the_list_6){
    std::vector<double> s = {0., 1., 2.};
    HorseRaceBalance hr = HorseRaceBalance(s, true);
    EXPECT_TRUE(hr.won_affter_loisng_(1));
}

TEST_F(TestHorseRaceBalance, test_won_after_lossing_begining_of_the_list_short_1){
    std::vector<double> s = {-1., 1.};
    HorseRaceBalance hr = HorseRaceBalance(s, true);
    EXPECT_TRUE(hr.won_affter_loisng_(1));
}

TEST_F(TestHorseRaceBalance, test_won_after_lossing_begining_of_the_list_short_2){
    std::vector<double> s = {0., 1.};
    HorseRaceBalance hr = HorseRaceBalance(s, true);
    EXPECT_TRUE(hr.won_affter_loisng_(1));
}

TEST_F(TestHorseRaceBalance, test_won_after_lossing_end_of_the_list_1){
    std::vector<double> s = {1., 1., 2., 0., 1.};
    HorseRaceBalance hr = HorseRaceBalance(s, true);
    EXPECT_TRUE(hr.won_affter_loisng_(1));
}

TEST_F(TestHorseRaceBalance, test_won_after_lossing_end_of_the_list_2){
    std::vector<double> s = {1., 1., 2., -2., 1.};
    HorseRaceBalance hr = HorseRaceBalance(s, true);
    EXPECT_TRUE(hr.won_affter_loisng_(1));
}

TEST_F(TestHorseRaceBalance, test_won_after_lossing_end_of_the_list_3){
    std::vector<double> s = {1., 1., 2., 0., 0., 1.};
    HorseRaceBalance hr = HorseRaceBalance(s, true);
    EXPECT_TRUE(hr.won_affter_loisng_(2));
}

TEST_F(TestHorseRaceBalance, test_won_after_lossing_end_of_the_list_4){
    std::vector<double> s = {1., 1., 2., -2., -1., 1.};
    HorseRaceBalance hr = HorseRaceBalance(s, true);
    EXPECT_TRUE(hr.won_affter_loisng_(2));
}

TEST_F(TestHorseRaceBalance, test_won_after_lossing_multiple_hit){
    std::vector<double> s = {1., 1., -2., -1., 1., -3., -7., 5};
    HorseRaceBalance hr = HorseRaceBalance(s, true);
    EXPECT_TRUE(hr.won_affter_loisng_(2));
}

TEST_F(TestHorseRaceBalance, test_won_after_lossing_multiple_hit_overfulfil_first){
    std::vector<double> s = {1., 1., -2., -1., -3., 1., -3., -7., 5};
    HorseRaceBalance hr = HorseRaceBalance(s, true);
    EXPECT_TRUE(hr.won_affter_loisng_(2));
}

TEST_F(TestHorseRaceBalance, test_won_after_lossing_multiple_hit_overfulfil_second){
    std::vector<double> s = {1., 1., -2., -1., 1., -3., -7.,-1., 5};
    HorseRaceBalance hr = HorseRaceBalance(s, true);
    EXPECT_TRUE(hr.won_affter_loisng_(2));
}


// all tests below assumes that zero is not a loss
TEST_F(TestHorseRaceBalance, test_won_affter_loisng_always_lost){
    //
    std::vector<double> s = {-1.,-1.,-1,-1};
    HorseRaceBalance hr = HorseRaceBalance(s, false);
    EXPECT_FALSE(hr.won_affter_loisng_(3));

}

