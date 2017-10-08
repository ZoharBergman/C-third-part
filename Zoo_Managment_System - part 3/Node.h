#ifndef __NODE_H
#define __NODE_H

/*
T should have:
1- operator=     --> for using assignment
*/
template<class T>
class Node
{
private:
	T data;
	T* next;

public:
	Node(T data, T* next);
	
	const T& getData() const { return data; }
	const T* getNext() const { return next; }

	void setData(T data) { this->data = data; }
	void setNext(T* next) { this->next = next; }
};

#endif //__NODE_H