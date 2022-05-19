#ifndef ANCESTOR_CHART_BINARYTREE_HPP
#define ANCESTOR_CHART_BINARYTREE_HPP
#include "Node.hpp"
#include <functional>
#include <iostream>

// Inspiration for code: https://github.com/devos50/BinaryTree

template<typename T>
class BinaryTree {
public:
    // Constructors
    explicit BinaryTree(const T& data);

    // Destructor
    ~BinaryTree();

    int getSize();
    Node<T> *getRoot();
    Node<T> *getParent();
    Node<T> *getRightChild();
    Node<T> *getLeftChild();

    void traverseDepthFirst(std::function<void(Node<T>*)>&) const;

    void insertNode(Node<T> *node, T data);
    bool isEmpty();
    bool isRoot();
    bool hasLeftChild();
    bool hasRightChild();
    bool hasParent();

private:
    void traverseDepthFirst(Node<T>* root, std::function<void(Node<T>*)>&) const;
    Node<T> *root_ = nullptr;
    int size_ = 0;
};

template<typename T>
BinaryTree<T>::~BinaryTree(){ //TODO: start from root, delete all nodes

}

template<typename T>
BinaryTree<T>::BinaryTree(const T& data) : root_(new Node<T>(data)) {
    size_++;
}

template<typename T>
void BinaryTree<T>::insertNode(Node<T> *node, T data) {
    if (node->getLeftPtr() == nullptr){
        auto newNode = new Node(data);
        node->setLeftPtr(newNode);
        size_++;
    }
    else if (node->getRightPtr() == nullptr){
        auto newNode = new Node(data);
        node->setRightPtr(newNode);
        size_++;
    }
    else {
        std::cout << "Error: node is full \n";
    }
}

template<typename T>
int BinaryTree<T>::getSize() {
    return size_;
}

template<typename T>
bool BinaryTree<T>::isEmpty() {
    return (size_ == 0);
}

template<typename T>
Node<T> *BinaryTree<T>::getRoot() {
    if(isEmpty()){
        std::cout << "Binarytree is empty!\n";
        return nullptr;
    }
    else {
        return root_;
    }
}

/**
* Depth first traversal function.
*
* @param rootnode.
* @param nodeFunction.
* @return none.
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

template<typename T>
void BinaryTree<T>::traverseDepthFirst(std::function<void(Node<T>*)>& nodeFunction) const {
    traverseDepthFirst(root_, nodeFunction);
}

#endif//ANCESTOR_CHART_BINARYTREE_HPP