#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../include/Node.hpp"

TEST_CASE("Node functionality", "[Node<T>]"){
    int data = 1;
    Node<int> testNode = Node(data);
    SECTION("Getters from Node"){
        REQUIRE(testNode.getData() == 1);
        REQUIRE(testNode.getLeftPtr() == nullptr);
        REQUIRE(testNode.getRightPtr() == nullptr);
    }
    SECTION("Setters in Node") {
        int data2 = 2;
        Node<int> pointerTestNode = Node(data2);
        testNode.setData(2);
        testNode.setLeftPtr(&pointerTestNode);
        testNode.setRightPtr(&pointerTestNode);
        REQUIRE(testNode.getData() == 2);
        REQUIRE(testNode.getLeftPtr()->getData() == 2);
        REQUIRE(testNode.getRightPtr()->getData() == 2);
    }
    SECTION("Check node relationships"){
        REQUIRE(testNode.isLeaf() == true);
        REQUIRE(testNode.hasSpace() == true);

        int data3 = 1;
        Node<int> pointerTestNode = Node(data3);
        testNode.setLeftPtr(&pointerTestNode);

        REQUIRE(testNode.isLeaf() == false);
        REQUIRE(testNode.hasSpace() == true);

        testNode.setRightPtr(&pointerTestNode);

        REQUIRE(testNode.isLeaf() == false);
        REQUIRE(testNode.hasSpace() == false);
    }
}
