///////////////////////////////////////////////////////
// ECE 3514, Project 4, Josh Dunn
//
// File name: hw4_test.cpp
// Description: This file tests all methods of treeNode and prefixTree
// Date: 12/6/2023
//


#define CATCH_CONFIG_MAIN 
#define CATCH_CONFIG_COLOUR_NONE


#include "catch.hpp"
#include "prefixTree.h"
#include "treeNode.h"
#include "hw4_datarecord.h"

TEST_CASE("Test Creating an Empty Tree", "[constructor]") {
	
	


}
// To DO

// passed
TEST_CASE("test treenode") {
	treeNode N;

	REQUIRE(N.getLeftChildPtr() == nullptr);
	REQUIRE(N.getRightChildPtr() == nullptr);
	REQUIRE(N.getNetId() == "");
	REQUIRE(N.getPort() == -1);

	// with parameterized constructor
	treeNode M("0010", 3);

	REQUIRE(M.getNetId() == "0010");
	REQUIRE(M.getPort() == 3);
	REQUIRE(M.isLeaf());


	M.setLeftChildPtr(std::make_shared<treeNode>(N));
	REQUIRE(!M.isLeaf());
	REQUIRE(M.getLeftChildPtr().get() != nullptr);

	RoutingEntry routingtest = M.getRoutingEntry();
	CHECK(routingtest.netId == "0010");
	CHECK(routingtest.port == 3);


	std::shared_ptr<treeNode> L = std::make_shared<treeNode>("0110", 5);

	CHECK(visitNode(L) == "0110:5\n");
	CHECK(visitRoutingEntry(L) == "0110:5\n");

	L->setPort(-1);
	CHECK(visitNode(L) == "0110:-1\n");
	CHECK(visitRoutingEntry(L) == "");

}


