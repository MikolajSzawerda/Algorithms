#include <gtest/gtest.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "../src/RBTree.h"

class TreeTest : public ::testing::Test
{
protected:
    std::vector<int> nums1;
    std::vector<int> nums2;
    std::vector<int> sum;
    RBTree<int> tree;
    RBTree<int> emptyTree;
    void fillVector(std::string fileName, std::vector<int> & vector){
        std::fstream file;
        file.open(fileName.c_str(), std::ios::in);
        if(!file.is_open()){
            std::cerr<<"Could not open file: "<<fileName<<std::endl;
            return;
        }
        int num;
        while(file>>num){
            vector.push_back(num);
        }
        file.close();
    }
    virtual void SetUp()
    {
        fillVector("numbers/giant/1.txt", nums1);
        fillVector("numbers/giant/2.txt", nums2);
        fillVector("numbers/giant/union.txt", sum);
        for(auto num:nums1)
            tree.insert(num);
    }
};

TEST(RedBlackTree, test_initial_tree){
    RBTree<int> tree;
    ASSERT_EQ(tree.count(), 0);
    ASSERT_TRUE(tree.search(-1)==nullptr);
}

TEST_F(TreeTest, test_tree_insertion){
    ASSERT_EQ(emptyTree.count(), 0);
    for(auto num : nums2)
        emptyTree.insert(num);
    for(auto num:nums2){
        ASSERT_FALSE(emptyTree.search(num)==nullptr);
    }
}

TEST_F(TreeTest, test_tree_insertion_unique){
    for(auto num : nums2)
        tree.insert(num);
    for(auto num:sum){
        ASSERT_FALSE(tree.search(num)==nullptr);
    }
}

TEST(RedBlackTree, test_inorder_tree){
    std::vector<int> nums {1,2,3,4,5,6,7};
    RBTree<int> tree;
    for(auto num : nums)
        tree.insert(num);
    int count = tree.count();
    auto numbers = tree.inOrder();
    ASSERT_EQ(numbers.size(), nums.size());
    for(int i=0;i<nums.size();i++){
        ASSERT_EQ(numbers[i], nums[i]);
    }
}

TEST_F(TreeTest, test_tree_successor){
    auto nums = tree.inOrder();
    for(auto it=nums.begin();it!=nums.end()-1;++it){
        auto succ = tree.successor(*it);
        ASSERT_EQ(succ->key, *(it+1));
    }
    auto max = tree.maximum();
    auto succ = tree.successor(max->key);
    ASSERT_EQ(succ, nullptr);
}

TEST_F(TreeTest, test_tree_predecessor){
    auto nums = tree.inOrder();
    std::reverse(nums.begin(), nums.end());
    for(auto it=nums.begin();it!=nums.end()-1;++it){
        auto pre = tree.predecessor(*it);
        ASSERT_EQ(pre->key, *(it+1));
    }
    auto min = tree.minimum();
    auto succ = tree.predecessor(min->key);
    ASSERT_EQ(succ, nullptr);
}

TEST_F(TreeTest, test_assiging_tree){
    RBTree<int> tree2;
    {
        RBTree<int> tree3;
        for(auto num:nums1){
            tree3.insert(num);
        }
        tree2=tree3;
    }
    ASSERT_EQ(tree2.count(), tree.count());
    for(auto num:nums1)
        ASSERT_FALSE(tree2.search(num)==nullptr);
}

TEST_F(TreeTest, test_copying_tree){
    RBTree tree2(tree);
    ASSERT_EQ(tree2.count(), tree.count());
    for(auto num:nums1)
        ASSERT_FALSE(tree2.search(num)==nullptr);
}

TEST(RedBlackTree, test_tree_deletation){
    std::vector<int> nums {1,2,3,4,5,6,7};
    RBTree<int> tree;
    for(auto num : nums)
        tree.insert(num);
    int countBefore = tree.count();
    tree.deleteNode(1);
    int countAfter = tree.count();
    ASSERT_EQ(countBefore, countAfter+1);
    auto node = tree.search(1);
    ASSERT_EQ(node, nullptr);
}

TEST(RedBlackTree, test_tree_deletation_non_existing){
    std::vector<int> nums {1,2,3,4,5,6,7};
    RBTree<int> tree;
    for(auto num : nums)
        tree.insert(num);
    int countBefore = tree.count();
    tree.deleteNode(10);
    int countAfter = tree.count();
    ASSERT_EQ(countBefore, countAfter);
}


