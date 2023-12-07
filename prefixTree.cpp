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
	if (nodePtr->getNetId() == netId) {
		nodePtr->setPort(port);
		return true;
	}

	if (nodePtr->getNetId() == "") {
		if (netId[0] == '0') {
			std::shared_ptr<treeNode> newNode = std::make_shared <treeNode>(netId, port);
			nodePtr->setLeftChildPtr(newNode);
			return true;
		}
		else {
			std::shared_ptr<treeNode> newNode = std::make_shared <treeNode>(netId, port);
			nodePtr->setRightChildPtr(newNode);
			return true;
		}
	}

	// left side
	if (netId[nodePtr->getNetId().length()] == '0') {
		if (nodePtr->getLeftChildPtr() == nullptr) {
			std::shared_ptr<treeNode> newNode = std::make_shared <treeNode>(netId, port);
			nodePtr->setLeftChildPtr(newNode);
			return true;
		}
		return recursiveAdd(nodePtr->getLeftChildPtr(), netId, port);
	}

	// right side
	if (netId[nodePtr->getNetId().length()] == '1') {
		if (nodePtr->getRightChildPtr() == nullptr) {
			std::shared_ptr<treeNode> newNode = std::make_shared <treeNode>(netId, port);
			nodePtr->setRightChildPtr(newNode);
			return true;
		}
		return recursiveAdd(nodePtr->getRightChildPtr(), netId, port);
	}

	// add unsuccessful
	return false;
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
	return (rootPtr == nullptr);
}

int prefixTree::getHeight() const
{
	return 0;
}

int prefixTree::getNumberOfNodes() const
{
	return 0;
}


