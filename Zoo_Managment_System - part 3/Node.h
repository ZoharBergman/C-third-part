#ifndef __NODE_H
#define __NODE_H

/*
T should have:
1- operator=     --> for using assignment
2- copy c'tor    --> for c'tor
*/
template<class T>
class Node
{
private:
	// Attributes
	T data;
	Node<T>* next;
	
	// Deleted methods
	Node(const Node<T>& other);
	const Node<T>& operator=(const Node<T>& other);

public:
	// Ctor
	Node(T data) : data(data), next(nullptr) {}
	
	// Getters & Setters
	const T& getData() const { return data; }	
	const Node<T>* getNext() const { return next; }
	Node<T>* getNext() { return next; }

	void setData(T data) { this->data = data; }	
	void setNext(Node<T>* next) { this->next = next; }
};

#endif //__NODE_H