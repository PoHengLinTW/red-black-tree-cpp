#ifndef TEST_TRUNK_CPP
#define TEST_TRUNK_CPP
#include "../src/RBTree.h"
#include "../src/TreeNode.h"
#include <gtest/gtest.h>
#include <memory>

TEST(TRUNK, PRINT)
{
    RBTree tree;
    std::shared_ptr<TreeNode> root = std::make_shared<TreeNode>(1, Color::RED);
    root->leftChild = std::make_shared<TreeNode>(2, Color::RED);
    root->rightChild = std::make_shared<TreeNode>(3, Color::RED);
    root->leftChild->leftChild = std::make_shared<TreeNode>(4, Color::RED);
    root->leftChild->rightChild = std::make_shared<TreeNode>(5, Color::RED);
    root->rightChild->leftChild = std::make_shared<TreeNode>(6, Color::RED);
    root->rightChild->rightChild = std::make_shared<TreeNode>(7, Color::RED);
    root->leftChild->leftChild->leftChild = std::make_shared<TreeNode>(8, Color::RED);    
    root->leftChild->leftChild->rightChild = std::make_shared<TreeNode>(9, Color::RED);    
    root->leftChild->rightChild->leftChild = std::make_shared<TreeNode>(10, Color::RED);
    root->leftChild->rightChild->rightChild = std::make_shared<TreeNode>(11, Color::RED);
    root->rightChild->leftChild->leftChild = std::make_shared<TreeNode>(12, Color::RED);
    root->rightChild->leftChild->rightChild = std::make_shared<TreeNode>(13, Color::RED);
    root->rightChild->rightChild->leftChild = std::make_shared<TreeNode>(14, Color::RED);
    root->rightChild->rightChild->rightChild = std::make_shared<TreeNode>(15, Color::RED);
    tree.setRoot(root);
    
    tree.printTree();
}

#endif