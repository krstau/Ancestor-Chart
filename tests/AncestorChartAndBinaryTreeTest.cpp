#define CONFIG_CATCH_MAIN
#include "catch.hpp"
#include "../include/AncestorChart.hpp"

TEST_CASE("Ancestor Chart and Binary Tree work"){
    int data1 = 1;
    int data2 = 2;
    int data3 = 3;
    int data4 = 4;
    int data5 = 5;
    BinaryTree testTree = BinaryTree(data1);
    Node<int>* rootNode = testTree.root_;
    testTree.insertNode(rootNode, data2);
}