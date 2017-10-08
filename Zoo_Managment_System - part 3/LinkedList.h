#ifndef __LINKED_LIST_H
#define __LINKED_LIST_H

#include "Node.h"
#include <iostream>

using namespace std;

/*
T should have:
1- operator=     --> for using assignment
2- operator <<   --> for printing with cout
*/
template<class T>
class LinkedList
{
private:
	Node<T> firstNode;	

public:
	LinkedList(Node<T> firstNode);

	const Node<T>& getFirstNode() const { return firstNode; }

	void addNode(Node<T> node);

	void removeNode(Node<T> node);

	friend ostream& operator<<(ostream& os, const LinkedList<T>& linkedList, char delimiter);
};

template<class T>
LinkedList<T>::LinkedList(Node<T> firstNode)
{
	this->firstNode.setData(firstNode.getData());
	this->firstNode.setNext = nullptr;
}

template<class T>
void LinkedList<T>::addNode(Node<T> node)
{
	Node<T> currNode = firstNode;

	// Finding the last node
	while (currNode.getNext() != nullptr)
	{
		currNode = *(currNode.getNext());
	}

	// Settint the next of the last node to the new node
	currNode.setNext(&node);

	// Setting the next of the new node to null
	node.setNext(nullptr);
}

template<class T>
void LinkedList<T>::removeNode(Node<T> node)
{
	Node<T> currNode = firstNode;

	// Finding the node before the node to be removed
	while (currNode != nullptr && currNode.getNext() != &node)
	{
		currNode = *(currNode.getNext());
	}

	// In case we found the node before, we should change it's next to the next of the node to be removed
	if (currNode != nullptr)
	{
		currNode.setNext(node.getNext());
	}
}

template<class T>
ostream& LinkedList<T>::operator<<(ostream& os, const LinkedList<T>& linkedList, char delimiter)
{
	Node<T> currNode = linkedList.getFirstNode();

	while (currNode != nullptr)	
	{
		os << currNode.getData() << delimiter;
	}

	return os;
}

#endif // __LINKED_LIST_H