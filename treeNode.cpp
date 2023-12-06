

#include "treeNode.h"



treeNode::treeNode() {
	this->setLeftChildPtr(nullptr);
	this->setRightChildPtr(nullptr);
	this->setNetId("");
	this->setPort(-1);
}

treeNode::treeNode(const std::string netId_in,  int port_in) {
	this->setLeftChildPtr(nullptr);
	this->setRightChildPtr(nullptr);
	this->setNetId(netId_in);
	this->setPort(port_in);
}

void treeNode::setNetId(const std::string netId_in) {
	rtEntry.netId = netId_in;

}

void treeNode::setPort(const int port_in) {
	rtEntry.port = port_in;
	
}



std::string treeNode::getNetId() const {
	
	return this->rtEntry.netId;
}

 int treeNode::getPort() const {
	 return this->rtEntry.port;
	
}

 RoutingEntry treeNode::getRoutingEntry() const
 {
	 RoutingEntry s = { getNetId(),getPort()};
	 return s;
 }

bool treeNode::isLeaf() const {
	
	return ((getLeftChildPtr() == nullptr) && (getRightChildPtr() == nullptr));

}

std::shared_ptr<treeNode> treeNode::getLeftChildPtr() const {

	return leftChildPtr;
	
}
std::shared_ptr<treeNode>  treeNode::getRightChildPtr() const {
	return rightChildPtr;
}

void treeNode::setLeftChildPtr(std::shared_ptr<treeNode> leftPtr) {
	leftChildPtr = leftPtr;
}

void treeNode::setRightChildPtr(std::shared_ptr<treeNode> rightPtr) {
	rightChildPtr = rightPtr;
}