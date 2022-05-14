#ifndef ANCESTOR_CHART_BINARYTREE_H
#define ANCESTOR_CHART_BINARYTREE_H
#include "Node.h"
#include "Person.h"

template<typename T>
class BinaryTree {
public:
    BinaryTree(T root = nullptr);
    void createNode();

private:
    T* root; // Pointer to root of the tree
    void addLeftNode(T &parent, Person &child);
    void addRightNode(T &parent, Person &child);
    int nodeAmount;

};

template<typename T>
BinaryTree<T>::BinaryTree(T root) {
    root = nullptr;
}

template<typename T>
void createNode(T data) {
}

#endif //ANCESTOR_CHART_BINARYTREE_H