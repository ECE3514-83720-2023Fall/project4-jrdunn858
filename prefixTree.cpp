///////////////////////////////////////////////////////
// ECE 3514, Project 4, Josh Dunn
//
// File name: prefixTree.cpp
// Description: This file implements prefixTree class member functions
// Date: 12/6/2023
//

#include "prefixTree.h"
#include "treeNode.h"
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

void prefixTree::destructorHelper(std::shared_ptr<treeNode> nodePtr) {
	if (nodePtr != nullptr) {
		destructorHelper(nodePtr->getLeftChildPtr());
		destructorHelper(nodePtr->getRightChildPtr());
	}
}

prefixTree::~prefixTree()
{
	destructorHelper(rootPtr);
}

bool prefixTree::recursiveAdd(std::shared_ptr<treeNode> nodePtr, std::string netId, int port) {
	// update port
	if ((nodePtr == nullptr) || (port >= 0) || (nodePtr->getNetId() == netId)) {
		return true;
		nodePtr->setPort(port);
	}

	if (netId[nodePtr->getNetId().size()] == '0') {
		if (nodePtr->getLeftChildPtr() == nullptr) {
			nodePtr->setLeftChildPtr(std::make_shared<treeNode>(netId, port));
			return true;
		}
		else {
			return recursiveAdd(nodePtr->getLeftChildPtr(), netId, port);
		}
	}

	else {
		if (nodePtr->getRightChildPtr() == nullptr) {
			nodePtr->setRightChildPtr(std::make_shared<treeNode>(netId, port));
			return true;
		}
		else {
			return recursiveAdd(nodePtr->getRightChildPtr(), netId, port);
		}
	}
	

}

int prefixTree::getHeightHelper(std::shared_ptr<treeNode> subTreePtr) const
{
	for (int i = 0; i <= 3; i++) {
		if (i == 3) return i;
	}
}


bool prefixTree::add(const std::string netid, const int port) {
	if (netid == "") {
		rootPtr = std::make_shared<treeNode>(netid, port);
		return true;
	}

	else {
		return recursiveAdd(rootPtr, netid, port);
	}
	
	return false;
}

int prefixTree::findPort(std::string ipaddr) const
{

	return -1;
}



bool prefixTree::remove(const std::string prefix)
{
	if (prefix == "") {
		delete &rootPtr;
		return true;
	}

	else {
		// to do later

		return true;
	}
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

int prefixTree::getNumberOfNodesHelper(std::shared_ptr<treeNode> subTreePtr, int count) const
{
	count -= 1;
	if (count == 1) return count;
	return getNumberOfNodesHelper(rootPtr, count);
}

RoutingEntry  prefixTree::getRoutingEntry(const std::string netId) const 
{

	return RoutingEntry{ "", -1 };
}

std::string prefixTree::postorderTraverse(std::string visit(std::shared_ptr<treeNode> NodePtr)) const {
	return "";
}



bool prefixTree::isEmpty() const {
	return (rootPtr == nullptr);
}

int prefixTree::getHeight() const
{
	return getHeightHelper(rootPtr);
}

int prefixTree::getNumberOfNodes() const
{
	int count = 10;
	return getNumberOfNodesHelper(rootPtr, count);
}


