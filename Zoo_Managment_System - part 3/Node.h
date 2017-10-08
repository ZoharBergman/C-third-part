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
	T data;
	Node<T>* next;
	
	Node(const Node<T>& other);
	const Node<T>& operator=(const Node<T>& other);

public:
	Node(T data);
	
	const T& getData() const { return data; }
	
	const Node<T>* getNext() const { return next; }
	Node<T>* getNext() { return next; }

	void setData(T data) { this->data = data; }
	void setNext(Node<T>* next) { this->next = next; }
};

template<class T>
Node<T>::Node(T data) : data(data), next(nullptr) {}

#endif //__NODE_H