#include <gtest/gtest.h>
#include <vector>
#include "Median.h"
#include <utility>
#include <stdexcept>
#include <time.h>
#include <stdlib.h>



TEST(test_median, test_fiding_minimum){
    std::vector<int> tab = {1, 2, 3, 4, 5, 6};
    int ans = Median::Minimum(tab);
    ASSERT_EQ(ans, 1);
}


TEST(test_median, test_fiding_maxmimum){
    std::vector<int> tab = {1, 2, 3, 4, 5, 6};
    int ans = Median::Maximium(tab);
    ASSERT_EQ(ans, 6);
}


TEST(test_median, test_fiding_min_max_even){
    std::vector<int> tab = {-101, 2, 3, 4, 5, 6};
    auto ans = Median::MinMax(tab);
    ASSERT_EQ(ans.first, -101);
    ASSERT_EQ(ans.second, 6);
}


TEST(test_median, test_fiding_min_max_odd){
    std::vector<int> tab = {-101, -1234, -12344, -8};
    auto ans = Median::MinMax(tab);
    ASSERT_EQ(ans.first, -12344);
    ASSERT_EQ(ans.second, -8);
}


TEST(test_median, test_fiding_min_max_one_element){
    std::vector<int> tab = {2};
    auto ans = Median::MinMax(tab);
    ASSERT_EQ(ans.first, 2);
    ASSERT_EQ(ans.second, 2);
}


TEST(test_median, test_fiding_min_max_one_value){
    std::vector<int> tab = {1,1,1,1,1,1,1,1,1,1,1};
    auto ans = Median::MinMax(tab);
    ASSERT_EQ(ans.first, 1);
    ASSERT_EQ(ans.second, 1);
}


TEST(test_median, test_fiding_min_max_empty){
    std::vector<int> tab = {};
    ASSERT_THROW(Median::MinMax(tab), std::invalid_argument);
}


TEST(test_median, test_fiding_second_minimal_element){
    srand(time(NULL));
    std::vector<int> tab = {6, 8, 12, 40, -1, 4, 5, 1};
    int ans = Median::Select(tab, 0, tab.size()-1, 2);
    ASSERT_EQ(ans, 1);
}
