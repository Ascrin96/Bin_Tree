#include <iostream>
#include "bin_tree.h"
#include <gtest/gtest.h>

TEST(Bin_Tree_Test, addNode){
    //Input
    BinTree<int> binTree;

    //Expected
    size_t expextedSize = binTree.getSize() + 1;

    //Actual
    binTree.add(10);
    size_t actualSize = binTree.getSize();

    //Check
    ASSERT_EQ(expextedSize, actualSize);
}

TEST(Bin_Tree_Test, deleteNode){
    //Input
    BinTree<int> binTree;
    binTree.add(20);
    binTree.add(30);
    binTree.add(10);
    binTree.add(5);
    binTree.add(8);
    binTree.add(1);
    binTree.add(7);
    binTree.add(9);

    //Expected
    size_t expextedSize = binTree.getSize() - 1;

    //Actual
    binTree.remote(10);
    size_t actualSize = binTree.getSize();

    //Check
    ASSERT_EQ(expextedSize, actualSize);
}

int main(int argc, char *argv[]){

    ::testing::InitGoogleTest(&argc, argv);


    return RUN_ALL_TESTS();
}
