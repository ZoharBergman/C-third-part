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
	Node<T>* head;

	LinkedList(const LinkedList<T>& other);
	const LinkedList& operator=(const LinkedList<T>& other);

public:
	LinkedList(Node<T>* head = nullptr);
	~LinkedList();

	void addData(const T& data);

	void removeData(const T& data);

	bool isExists(const T& data) const;

	friend ostream& operator<<(ostream& os, const LinkedList<T>& linkedList);
};

template<class T>
LinkedList<T>::LinkedList(Node<T>* head) : head(head){}

template<class T>
LinkedList<T>::~LinkedList()
{
	if (head != nullptr)
	{
		Node<T>* tempNext = head->getNext();
		Node<T>* curr = head;

		delete curr;
		curr = tempNext;

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
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* currNode = head;

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
void LinkedList<T>::removeData(const T& data)
{
	Node<T>* currNode = head;

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

template<class T>
bool LinkedList<T>::isExists(const T& data) const
{
	Node<T>* currNode = head;

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

template<class T>
ostream& operator<<(ostream& os, const LinkedList<T>& linkedList)
{
	Node<T>* currNode = linkedList.getHead();

	while (currNode != nullptr)	
	{		
		os << "{" << currNode->getData() << "}, ";
		currNode = currNode->getNext();
	}

	os << '\b' << '\b';
	return os;
}

#endif // __LINKED_LIST_H