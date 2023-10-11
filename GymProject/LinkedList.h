#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template<class T>
class Node
{
public:
	T data;
	Node<T>* next;

	Node<T>(const T& data) : data(data), next(nullptr) {}
	friend ostream& operator<<(ostream& os, const Node<T>& node) { os << node.data; return os; }

	template<class T> friend class LinkedList;
};

template<class T>
class LinkedList
{
private:
	Node<T>* head;
	Node<T>* tail;
	int count;

public:
	LinkedList(Node<T>* newNode = nullptr) : head(newNode), tail(newNode) {}

	template<class T>
	void push_back(T& val)
	{
		Node<T>* newNode = new Node<T>(val);
		if (tail == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		count++;
	}

	template<class T>
	void remove(int index)
	{
		Node<T>* before = nullptr;
		Node<T>* cur = head;

		for (int i = 1; i < index; i++)
		{
			before = cur;
			cur = cur->next;
			if (cur == nullptr)
			{
				return;
			}
		}

		if (cur == head)
		{
			head = cur->next;
		}
		else
		{
			before->next = cur->next;

			if (cur == tail)
			{
				tail = before;
			}
		}
		count--;
		delete cur;
	}

	template<class T>
	friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list)
	{
		Node<T>* cur = list.head;
		int count = 1;
		while (cur != nullptr)
		{
			os << count++ << ". " << *cur << std::endl;
			cur = cur->next;
		}
		if (count == 1)
		{
			os << " There isn't exercise machines in the gym\n" << std::endl;
		}
		return os;
	}

	bool isEmpty() const
	{
		return count == 0;
	}
};

#endif