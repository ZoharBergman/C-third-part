#ifndef __LINKED_LIST_H
#define __LINKED_LIST_H

#include "Node.h"
#include <iostream>

using namespace std;

/*
T should have:
1- operator=     --> for using assignment
2- operator <<   --> for printing with cout
3- copy c'tor    --> for c'tor
*/
template<class T>
class LinkedList
{
private:
	// Attributes
	Node<T>* firstNode;

	// Deleted methods
	LinkedList(const LinkedList<T>& other);
	const LinkedList& operator=(const LinkedList<T>& other);

	// Methods
	const Node<T>* getFirstNode() const { return firstNode; }
	void setFirstNode(Node<T>* firstNode) { this->firstNode = firstNode; }

public:
	// Ctor & Dtor
	LinkedList(Node<T>* firstNode = nullptr);
	~LinkedList();

	// Methods
	/*Add a copy of the data to the linked list*/
	void addData(const T& data);

	/*Remove from the linked list the first node that it's data is equeal to the parameter*/
	void removeFirstInstanceOfData(const T& data);

	/*Checking if the data exists in the linked list - if it does exist than return true, otherwise return false*/
	bool isExists(const T& data) const;	

	// Operators
	/*Print the linked list's nodes' data*/
	friend ostream& operator<<(ostream& os, const LinkedList<T>& linkedList)
	{
		const Node<T>* currNode = linkedList.getFirstNode();

		if (currNode != nullptr)
		{
			while (currNode != nullptr)	
			{		
				os << "{" << *currNode->getData() << "}, ";
				currNode = currNode->getNext();
			}

			os << '\b' << '\b';
		}

		return os;
	}
};

template<class T>
LinkedList<T>::LinkedList(Node<T>* firstNode) : firstNode(firstNode){}

template<class T>
LinkedList<T>::~LinkedList()
{
	// Checking that the linked list is not empty
	if (firstNode != nullptr)
	{
		Node<T>* tempNext = firstNode->getNext();
		Node<T>* curr = firstNode;

		delete curr;
		curr = tempNext;

		// Free all nodes while the linked list is not empty
		while (tempNext != nullptr)
		{
			tempNext = tempNext->getNext();
			delete curr;
			curr = tempNext;	
		}

	}
}

template<class T>
void LinkedList<T>::addData(const T& data)
{
	// Checking the linked list is initial
	if (firstNode == nullptr)
	{
		firstNode = new Node<T>(data);
	}
	else
	{
		Node<T>* currNode = firstNode;

		// Finding the last node
		while (currNode->getNext() != nullptr)
		{
			currNode = currNode->getNext();
		}

		Node<T>* newNode = new Node<T>(data);

		// Settint the next of the last node to the new node
		currNode->setNext(newNode);
	}
}

template<class T>
void LinkedList<T>::removeFirstInstanceOfData(const T& data)
{
	Node<T>* currNode = firstNode;

	// Checking if we should remove the head
	if (currNode != nullptr && currNode->getData() == data)
	{
		Node<T>* temp = currNode->getNext();
		delete firstNode;
		setFirstNode(temp);
	}
	else
	{
		// Finding the node before the node to be removed
		while (currNode != nullptr && currNode->getNext()->getData() != data)
		{
			currNode = currNode->getNext();
		}

		// In case we found the node before, we should change it's next to the next of the node to be removed and delete the asked node
		if (currNode != nullptr)
		{
			Node<T>* temp = currNode->getNext();
			currNode->setNext(currNode->getNext()->getNext());

			delete temp;
		}
	}
}

template<class T>
bool LinkedList<T>::isExists(const T& data) const
{
	Node<T>* currNode = firstNode;

	// Finding the node before the node to be removed
	while (currNode != nullptr)
	{
		if (currNode->getData() == data)
		{
			return true;
		}

		currNode = currNode->getNext();
	}

	return false;
}

#endif // __LINKED_LIST_H