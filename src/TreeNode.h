#ifndef TREENODE__H
#define TREENODE__H

#include <memory>

enum Color: bool {
    RED = true, BLACK = false
};

struct TreeNode {
    TreeNode(int _key, Color _color)
         : TreeNode(_key, _color, nullptr, nullptr, nullptr) {}; 
    TreeNode(int _key, Color _color, std::shared_ptr<TreeNode> _parent)
         : TreeNode(_key, _color, nullptr, nullptr, _parent) {}; 
    TreeNode(int _key, Color _color, 
        std::shared_ptr<TreeNode> _leftChild, 
        std::shared_ptr<TreeNode> _rightChild)
         : TreeNode(_key, _color, std::move(_leftChild), std::move(_rightChild), nullptr) {}; 
    TreeNode(int _key, Color _color, 
        std::shared_ptr<TreeNode> _leftChild,
        std::shared_ptr<TreeNode> _rightChild,
        std::shared_ptr<TreeNode> _parent) 
        : key(_key), color(_color) {
            leftChild.swap(_leftChild);
            rightChild.swap(_rightChild);
            parent = _parent;
        }; 

    int key;
    Color color;
    std::shared_ptr<TreeNode> leftChild, rightChild;
    std::shared_ptr<TreeNode> parent;

    /* static functions */
    static Color changeColor(Color color) {
        return color == Color::RED ? 
            Color::BLACK : Color::RED;
    }
};

#endif