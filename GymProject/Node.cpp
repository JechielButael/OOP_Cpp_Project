#include "Node.h"

template <class T>
Node<T>::Node(const T& d) : data(d), next(nullptr) {}

template <class T>
Node<T>::Node(const Node<T>& other) : data(other.data), next(other.next) {}

template <class T>
std::ostream& operator<<(std::ostream& os, const Node<T>& node)
{
	os << node.data;
	return os;
}
