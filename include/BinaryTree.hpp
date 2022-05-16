#ifndef ANCESTOR_CHART_BINARYTREE_HPP
#define ANCESTOR_CHART_BINARYTREE_HPP
#include "Node.hpp"
#include "Person.hpp"
#include <functional>
#include <iostream>

// Inspiration for code: https://github3.com/devos50/BinaryTree

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

    void traverseDepthFirst(std::function<void(Node<T>*)>&);

    bool isEmpty();
    bool isRoot();
    bool hasLeftChild();
    bool hasRightChild();
    bool hasParent();
    void insertLeft(Node<T> *node, T);
    void insertRight(Node<T> *node, T);

private:
    void traverseDepthFirst(Node<T>* root, std::function<void(Node<T>*)>&);
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
void BinaryTree<T>::insertLeft(Node<T> *node, T data) {
    if (node == nullptr){
        // throw exception; TODO: Guard
    }
    if (node->getLeftPtr() == nullptr){
        auto newNode = std::make_unique<Node<T>>(data);
        node->setLeftPtr(*newNode);
        size_++;
    }
    else {
        std::cout << "Node already has a right node!\n";
    }
}

template<typename T>
void BinaryTree<T>::insertRight(Node<T> *node, T data) {
    if (node == nullptr){
        // throw exception; TODO: Guard
    }
    if (node->getRightPtr() == nullptr){
        auto newNode = new Node<T>(data);
        node->setRightPtr(*newNode);
        size_++;
    }
    else {
        std::cout << "Node already has a right node!\n";
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
void BinaryTree<T>::traverseDepthFirst(Node<T>* root, std::function<void(Node<T>*)>& nodeFunction) {
    if (root == nullptr) {
        return;
    }
    nodeFunction(root);
    traverseDepthFirst(root->getLeftPtr(), nodeFunction);
    traverseDepthFirst(root->getRightPtr(), nodeFunction);
}

template<typename T>
void BinaryTree<T>::traverseDepthFirst(std::function<void(Node<T>*)>& nodeFunction) {
    traverseDepthFirst(root_, nodeFunction);
}

#endif//ANCESTOR_CHART_BINARYTREE_HPP