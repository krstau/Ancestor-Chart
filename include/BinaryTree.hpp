#ifndef ANCESTOR_CHART_BINARYTREE_HPP
#define ANCESTOR_CHART_BINARYTREE_HPP
#include "Node.hpp"
#include <functional>
#include <iostream>

// Inspiration for BinaryTree code: https://github.com/devos50/BinaryTree

/**
 * BinaryTree class.
 * @tparam T Data input.
 */
template<typename T>
class BinaryTree {
public:
    explicit BinaryTree(const T& data);
    void traverseDepthFirst(std::function<void(Node<T>*)>&) const;
    void insertNode(Node<T> *node, T data);

private:
    Node<T> *root_ = nullptr;
    int size_ = 0;
    void traverseDepthFirst(Node<T> *root, std::function<void(Node<T>*)>&) const;
};

/**
 * BinaryTree default constructor.
 * @tparam T
 */
template<typename T>
BinaryTree<T>::BinaryTree(const T& data) : root_(new Node<T>(data)) {
    size_++;
}

/**
 * Inserts a node into BinaryTree
 * If a left pointer already exists, a right pointer will be set.
 * @tparam T
 */
template<typename T>
void BinaryTree<T>::insertNode(Node<T> *node, T data) {
    if (node->getLeftPtr() == nullptr){
        auto newNode = new Node(data);
        node->setLeftPtr(newNode);
        size_++;
    }
    else {
        auto newNode = new Node(data);
        node->setRightPtr(newNode);
        size_++;
    }
}


/**
* Recursive depth first traversal function.
* @param root node.
* @param nodeFunction.
*/
template<typename T>
void BinaryTree<T>::traverseDepthFirst(Node<T>* root, std::function<void(Node<T>*)>& nodeFunction) const {
    if (root == nullptr) {
        return;
    }
    nodeFunction(root);
    traverseDepthFirst(root->getLeftPtr(), nodeFunction);
    traverseDepthFirst(root->getRightPtr(), nodeFunction);
}

/**
* Depth first traversal function.
* @param root node.
* @param nodeFunction.
*/
template<typename T>
void BinaryTree<T>::traverseDepthFirst(std::function<void(Node<T>*)>& nodeFunction) const {
    traverseDepthFirst(root_, nodeFunction);
}

#endif//ANCESTOR_CHART_BINARYTREE_HPP