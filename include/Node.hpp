#ifndef ANCESTOR_CHART_NODE_HPP
#define ANCESTOR_CHART_NODE_HPP
#include "Person.hpp"
#include <memory>

template<class T>
class Node {
public:
    explicit Node(const T& data);
    Node(const T& data,Node<T> *leftPtr,Node<T> *rightPtr);
    T getData();
    Node<T> *getLeftPtr() const;
    Node<T> *getRightPtr() const;
    void setData(const T& data);
    void setLeftPtr(std::unique_ptr<Node<T>> &leftPtr);
    void setRightPtr(std::unique_ptr<Node<T>> &rightPtr);
    bool hasSpace();
    bool isLeaf();

private:
    T data_;
    Node<T> *left_ = nullptr;
    Node<T> *right_ = nullptr;
};

template<typename T>           //Make a node with data attached to it (rootnode)
Node<T>::Node(const T& data) : data_(data){}

template<typename T>           //Make a node with data attached and pointers set
Node<T>::Node(const T& data,Node<T>* leftPtr,Node<T>* rightPtr) : data_(data), left_(leftPtr), right_(rightPtr){}

template<typename T>           //Set the data of a Node
void Node<T>::setData(const T& data){
    data_ = data;
}

template<typename T>           //Returns the data of a Node
T Node<T>::getData(){
    return data_;
}

template<typename T>           //Checks if a node is a leaf => no offspring
bool Node<T>::isLeaf(){
    return left_ == nullptr && right_ == nullptr;
}

template<typename T>           //Checks if a node has room for more offspring
bool Node<T>::hasSpace(){
    return left_ == nullptr || right_ == nullptr;
}

template<typename T>           //Gets the left pointer
Node<T>* Node<T>::getLeftPtr() const{
    return left_;
}

template<typename T>           //Gets the right pointer
Node<T>* Node<T>::getRightPtr() const{
    return right_;
}

//Sets the left pointer
template<typename T>
void Node<T>::setLeftPtr(std::unique_ptr<Node<T>> &leftPtr){
    left_ = std::move(leftPtr);
}

//Sets the right pointer
template<typename T>
void Node<T>::setRightPtr(std::unique_ptr<Node<T>> &rightPtr){
    right_ = std::move(rightPtr);
}

#endif//ANCESTOR_CHART_NODE_HPP