#ifndef __NODE_H
#define __NODE_H

#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
	T data;
	Node<T>* next;

	Node<T>(const T& d);
	Node<T>(const Node<T>& other);
	Node<T>& operator=(const Node<T>&) = delete;
	friend ostream& operator<<(ostream& os, const Node<T>& node);
};

#endif // __NODE_H