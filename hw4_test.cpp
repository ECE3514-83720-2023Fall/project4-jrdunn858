
#define CATCH_CONFIG_MAIN			// this line tells Catch to provide a main() function
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

}


