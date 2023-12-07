///////////////////////////////////////////////////////
// ECE 3514, Project 4, Josh Dunn
//
// File name: hw4_datarecord.cpp
// Description: This file implements prefixTree class member functions
// Date: 12/6/2023
//

#include "hw4_datarecord.h"
#include <string>

std::string visitNode(std::shared_ptr<treeNode> nodePtr) {
	std::string out = nodePtr.get()->getNetId();
	out.append(":");
	out.append(std::to_string(nodePtr.get()->getPort()));
	out.append("\n");
	return out;
}

std::string visitRoutingEntry(std::shared_ptr<treeNode> nodePtr) {
	if (nodePtr.get()->getPort() == -1) {
		return "";
	}
	else return visitNode(nodePtr);
}