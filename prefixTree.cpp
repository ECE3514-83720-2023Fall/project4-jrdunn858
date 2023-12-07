///////////////////////////////////////////////////////
// ECE 3514, Project 4, Josh Dunn
//
// File name: prefixTree.cpp
// Description: This file implements prefixTree class member functions
// Date: 12/6/2023
//

#include "prefixTree.h"
//#include "treeNode.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

prefixTree::prefixTree() 
{
}  // end default constructor

prefixTree::prefixTree(std::string filename) {


}

void prefixTree::destructorHelper(std::shared_ptr<treeNode>& nodePtr) {
	if (nodePtr != nullptr) {
		destructorHelper(nodePtr->getLeftChildPtr());
		destructorHelper(nodePtr->getRightChildPtr());
	}
}

prefixTree::~prefixTree()
{
	
}

// returns a pointer to where the new node should b insterted
std::shared_ptr<treeNode> prefixTree::findInsertion(std::string netId, std::shared_ptr<treeNode> &nodePtr) {
	if (netId == "") return nodePtr;

	if (nodePtr->isLeaf()) {
		return nodePtr;
	}

	// need these values for various purposes (making the next lines neater)
	std::size_t thisIdLength = nodePtr->getNetId().length();
	std::size_t newIdLength = netId.length();
	std::size_t leftIdLength = nodePtr->getLeftChildPtr()->getNetId().length();
	std::size_t rightIdLength = nodePtr->getLeftChildPtr()->getNetId().length();

	if (netId[thisIdLength] == '0') {
		if (newIdLength < leftIdLength) {
			return nodePtr;
		}
		else findInsertion(netId, nodePtr->getLeftChildPtr());
	}

	if (netId[thisIdLength] == '1') {
		if (newIdLength < rightIdLength) {
			return nodePtr;
		}
		else findInsertion(netId, nodePtr->getRightChildPtr());
	}
	
}




bool prefixTree::add(const std::string netid, const int port) {
	/*if (this->rootPtr == nullptr) {
		rootPtr = std::make_shared<treeNode>(netid, port);
		return true;
	}
	else {
		
	}*/
	
	return false;
}

int prefixTree::findPort(std::string ipaddr) const
{

	return -1;
	
}



bool prefixTree::remove(const std::string prefix)
{
	
	return false;
}

void prefixTree::clear()
{
	
	return;
}


std::string prefixTree::postorderTraverseHelper(std::string visit(std::shared_ptr<treeNode> NodePtr), std::shared_ptr<treeNode> treePtr) const
{
	
	return "";
}



RoutingEntry  prefixTree::getRoutingEntry(const std::string netId) const 
{

	return RoutingEntry{ "", -1 };
}

std::string prefixTree::postorderTraverse(std::string visit(std::shared_ptr<treeNode> NodePtr)) const {
	return "";
}



int prefixTree::getHeightHelper(std::shared_ptr<treeNode> subTreePtr) const
{
	return -1;
}

int prefixTree::getNumberOfNodesHelper(std::shared_ptr<treeNode> subTreePtr) const
{
	return -1;
}





bool prefixTree::isEmpty() const {
	return true;
}

int prefixTree::getHeight() const
{
	return 0;
}

int prefixTree::getNumberOfNodes() const
{
	return 0;
}


