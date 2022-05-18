#ifndef ANCESTOR_CHART_NODE_HPP
#define ANCESTOR_CHART_NODE_HPP
#include "Person.hpp"
#include <memory>

/**
 * Node class.
 * @tparam T template for input data for node
 */
template<class T>
class Node {
public:
    explicit Node(const T& data);
    Node(const T& data,Node<T> *leftPtr,Node<T> *rightPtr);
    T getData();
    Node<T> *getLeftPtr() const;
    Node<T> *getRightPtr() const;
    void setData(const T& data);
    void setLeftPtr(Node<T> *leftPtr);
    void setRightPtr(Node<T> *RightPtr);
    bool hasSpace();
    bool isLeaf();

private:
    T data_;  /**< Data inside the node. */
    Node<T> *left_ = nullptr; /**< Pointer towards the nodes left child. */
    Node<T> *right_ = nullptr; /**< Pointer towards the nodes right child. */
};
/**
 * Constructor to create node with both pointers set to null.
 * @tparam T class of data
 * @param data data the node holds
 */
template<typename T>
Node<T>::Node(const T& data) : data_(data){}

/**
 * Constructor to create node with data and both pointers set.
 * @tparam T class of data
 * @param data data the node holds
 * @param leftPtr left pointer of the node
 * @param rightPtr right pointer of the node
 */
template<typename T>
Node<T>::Node(const T& data,Node<T>* leftPtr,Node<T>* rightPtr) : data_(data), left_(leftPtr), right_(rightPtr){}

/**
 * Sets the data of the node to data
 * @tparam T class of data
 * @param data data the node holds
 */
template<typename T>
void Node<T>::setData(const T& data){
    data_ = data;
}

/**
 * Gets the data a node is holding
 * @tparam T class of data to be returned
 * @return data the node is holding
 */
template<typename T>
T Node<T>::getData(){
    return data_;
}

/**
 * Checks if a node is a leaf (no children)
 * @return returns true if both pointers are nullpointers
 */
template<typename T>
bool Node<T>::isLeaf(){
    return left_ == nullptr && right_ == nullptr;
}

/**
 * Checks if a node has space for more offspring
 * @return returns true if either of the pointers returns nullpointer
 */
template<typename T>
bool Node<T>::hasSpace(){
    return left_ == nullptr || right_ == nullptr;
}

/**
 * Gets the left pointer of a node
 * @return returns pointer towards the left child of node called on
 */
template<typename T>
Node<T>* Node<T>::getLeftPtr() const{
    return left_;
}
/**
 * Gets the right pointer of a node
 * @return returns pointer towards the right child of node called on
 */
template<typename T>
Node<T>* Node<T>::getRightPtr() const{
    return right_;
}

/**
 * Sets the left pointer of a node to leftPtr
 * @param leftPtr pointer the nodes left pointer will be set to
 */
template<typename T>
void Node<T>::setLeftPtr(Node<T> *leftPtr){
    left_ = leftPtr;
}

/**
 * Sets the right pointer of a node to rightPtr
 * @param rightPtr pointer the nodes right pointer will be set to
 */
template<typename T>
void Node<T>::setRightPtr(Node<T> *rightPtr){
    right_ = rightPtr;
}

#endif//ANCESTOR_CHART_NODE_HPP