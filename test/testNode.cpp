#ifndef TEST_NODE_CPP
#define TEST_NODE_CPP
#include "../src/TreeNode.h"
#include <gtest/gtest.h>
#include <memory>

TEST(TREENODE, INIT)
{
    std::shared_ptr<TreeNode> node1 = std::make_shared<TreeNode>(100, Color::RED);
    EXPECT_EQ(node1->key, 100) << "Constructor fails to initialize the key with 100";
    EXPECT_EQ(node1->color, Color::RED) << "Constructor fails to initialize the color with Color::RED";
    EXPECT_EQ(node1->leftChild, nullptr) << "Constructor fails to initialize the left child with nullptr";
    EXPECT_EQ(node1->rightChild, nullptr) << "Constructor fails to initialize the right child with nullptr";
    EXPECT_EQ(node1->parent, nullptr) << "Constructor fails to initialize the parent with nullptr";
}

TEST(TREENODE, INIT_WITH_CHILDREN)
{
    std::shared_ptr<TreeNode> node1 = std::make_shared<TreeNode>(
        100, Color::RED,
        std::make_shared<TreeNode>(200, Color::BLACK),
        std::make_shared<TreeNode>(300, Color::BLACK));
    
    EXPECT_EQ(node1->key, 100) << "Constructor fails to initialize the key with 100";
    EXPECT_EQ(node1->color, Color::RED) << "Constructor fails to initialize the color with Color::RED";
    EXPECT_NE(node1->leftChild, nullptr) << "Constructor fails to initialize the left child";
    EXPECT_NE(node1->rightChild, nullptr) << "Constructor fails to initialize the right child";
    EXPECT_EQ(node1->parent, nullptr) << "Constructor fails to initialize the parent with nullptr";


    EXPECT_EQ(node1->leftChild->key, 200) << "Left child's key is incorrect";
    EXPECT_EQ(node1->leftChild->color, Color::BLACK) << "Left child's color is incorrect";

    EXPECT_EQ(node1->rightChild->key, 300) << "Right child's key is incorrect";
    EXPECT_EQ(node1->rightChild->color, Color::BLACK) << "Right child's color is incorrect";
}

TEST(TREENODE, INIT_WITH_PARENT)
{
    std::shared_ptr<TreeNode> parent = std::make_shared<TreeNode>(50, Color::RED);
    std::shared_ptr<TreeNode> node1 = std::make_shared<TreeNode>(100, Color::RED,parent);
    
    EXPECT_EQ(node1->key, 100) << "Constructor fails to initialize the key with 100";
    EXPECT_EQ(node1->color, Color::RED) << "Constructor fails to initialize the color with Color::RED";
    EXPECT_EQ(node1->leftChild, nullptr) << "Constructor fails to initialize the left child with nullptr";
    EXPECT_EQ(node1->rightChild, nullptr) << "Constructor fails to initialize the right child with nullptr";
    EXPECT_NE(node1->parent, nullptr) << "Constructor fails to initialize the parent";

    EXPECT_EQ(node1->parent->key, 50) << "Parent's key is incorrect";
    EXPECT_EQ(node1->parent->color, Color::RED) << "Parent's color is incorrect";
}

#endif