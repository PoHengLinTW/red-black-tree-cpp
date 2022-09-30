#ifndef RBTREE__H
#define RBTREE__H
#include <memory.h>
#include "TreeNode.h"
#include "Trunk.h"

// class Tree {
// public:
//     Tree() = default;
//     virtual ~Tree() = default;
//     virtual bool insert(int) = 0;
//     virtual bool erase(int) = 0;
//     virtual bool find(int) = 0;
//     virtual std::shared_ptr<TreeNode> getRoot() {
//         return nullptr;
//     };
// };

class RBTree {
private:
public:
    static void _print(std::shared_ptr<TreeNode>, std::shared_ptr<Trunk>, bool);
    std::shared_ptr<TreeNode> root;
    RBTree() = default;
    ~RBTree() = default;
    bool insert(int);
    bool erase(int);
    bool find(int);
    std::shared_ptr<TreeNode> getRoot() const;
    void setRoot(std::shared_ptr<TreeNode> root);
    void printTree();
};

bool RBTree::insert(int key) {
    return true;
}

bool RBTree::erase(int key) {
    return true;
}

bool RBTree::find(int key) {
    return true;
}

void RBTree::setRoot(std::shared_ptr<TreeNode> root) {
    this->root = root;
}

void RBTree::printTree() {
    _print(root, nullptr, false);
}

void RBTree::_print(
    std::shared_ptr<TreeNode> root, 
    std::shared_ptr<Trunk> prev, 
    bool isLeft) {
    if (root == nullptr)
        return;
    
    std::string prev_str = "    ";
    std::shared_ptr<Trunk> current = make_shared<Trunk>(prev, prev_str);

    _print(root->rightChild, current, true);

    if (prev == nullptr) {
        current->str = "———";
    } else if (isLeft) {
        current->str = ".———";
        prev_str = "   |";
    } else {
        current->str = "`———";
        prev->str = prev_str;
    }

    Trunk::showTrunk(current);
    std::string color = root->color == Color::RED ? "R" : "B";
    std::cout << " " << root->key << "(" << color << ")" << std::endl;

    if (prev != nullptr) {
        prev->str = prev_str;
    }

    current->str = "   |";
    _print(root->leftChild, current, false);
}
#endif