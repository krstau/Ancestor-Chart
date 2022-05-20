#ifndef ANCESTOR_CHART_BINARYTREE_HPP
#define ANCESTOR_CHART_BINARYTREE_HPP
#include "Node.hpp"
#include <functional>

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
    void traverseDepthFirst(Node<T> *root, std::function<void(Node<T>*)>&) const;
};

/**
 * BinaryTree default constructor.
 * @tparam T Data input.
 */
template<typename T>
BinaryTree<T>::BinaryTree(const T& data) : root_(new Node<T>(data)) {
}

/**
 * Inserts a node into BinaryTree
 * If a left pointer already exists, a right pointer will be set.
 * @tparam T Data input.
 */
template<typename T>
void BinaryTree<T>::insertNode(Node<T> *node, T data) {
    if (node->getLeftPtr() == nullptr){
        auto newNode = new Node(data);
        node->setLeftPtr(newNode);
    }
    else {
        auto newNode = new Node(data);
        node->setRightPtr(newNode);
    }
}

/**
 * Recursive depth first traversal function.
 * @param root node.
 * @param nodeFunction.
 * @tparam T Data input.
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
 * @tparam T Data input.
 */
template<typename T>
void BinaryTree<T>::traverseDepthFirst(std::function<void(Node<T>*)>& nodeFunction) const {
    traverseDepthFirst(root_, nodeFunction);
}

#endif//ANCESTOR_CHART_BINARYTREE_HPP