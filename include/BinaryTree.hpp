#ifndef ANCESTOR_CHART_BINARYTREE_HPP
#define ANCESTOR_CHART_BINARYTREE_HPP
#include "Node.hpp"
#include <functional>
#include <iostream>

// Inspiration for code: https://github.com/devos50/BinaryTree

/**
 *
 * @tparam T Data input.
 */
template<typename T>
class BinaryTree {
public:
    explicit BinaryTree(const T& data);
    ~BinaryTree();
    int getSize() const;
    Node<T> *getRoot() const;
    Node<T> *getParent();
    Node<T> *getRightChild();
    Node<T> *getLeftChild();
    void traverseDepthFirst(std::function<void(Node<T>*)>&) const;
    void destroyRecursive(Node<T> *node);
    void insertNode(Node<T> *node, T data);
    bool isEmpty();
    bool isRoot();
    bool hasLeftChild();
    bool hasRightChild();
    bool hasParent();

private:
    Node<T> *root_ = nullptr;
    int size_ = 0;
    void traverseDepthFirst(Node<T> *root, std::function<void(Node<T>*)>&) const;
};

/**
 * BinaryTree destructor.
 * @tparam T
 */
template<typename T>
BinaryTree<T>::~BinaryTree(){
    // destroyRecursive(root_);
}

/**
 *
 * @tparam T
 */
template<typename T>
void BinaryTree<T>::destroyRecursive(Node<T>* node)
{
    if (node)
    {
        destroyRecursive(node->getLeftPtr());
        destroyRecursive(node->getRightPtr());
        delete node;
    }
}

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
 * Gets the amount of nodes in the BinaryTree.
 * @tparam T
 * @return size_ amount of nodes.
 */
template<typename T>
int BinaryTree<T>::getSize() const {
    return size_;
}

/**
 * Checks if BinaryTree does not have any nodes.
 * @tparam T
 * @return true if BinaryTree has no nodes.
 */
template<typename T>
bool BinaryTree<T>::isEmpty() {
    return (size_ == 0);
}

/**
 * Gets the root node of the BinaryTree.
 * @tparam T
 * @return true if BinaryTree has no nodes.
 */
template<typename T>
Node<T> *BinaryTree<T>::getRoot() const {
    if(isEmpty()){
        std::cout << "BinaryTree is empty!" << std::endl;
        return nullptr;
    }
    else {
        return root_;
    }
}

/**
* Recursive depth first traversal function.
* @param rootnode.
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
* @param rootnode.
* @param nodeFunction.
*/
template<typename T>
void BinaryTree<T>::traverseDepthFirst(std::function<void(Node<T>*)>& nodeFunction) const {
    traverseDepthFirst(root_, nodeFunction);
}

#endif//ANCESTOR_CHART_BINARYTREE_HPP