#include "LinkedList.h"
#include "complex.h"
#include <iostream>

//template LinkedList<int>;
//template LinkedList<float>;
//template LinkedList<double>;
//template LinkedList<complex>;

//using namespace std;

template <class T>
LinkedList<T>::LinkedList()
{
	this->first = NULL;
	this->last = NULL;
	this->size = 0;
}

template <class T>
LinkedList<T>::LinkedList(T* items, int count)
{
	Node<T>* temp = this->first;
	for (int i = 0; i < count; i++)
		this.Append(items[i]);
}


template <class T>
LinkedList<T>::LinkedList(LinkedList <T>& list)
{
	
}

template <class T>
void LinkedList<T>::Append(T valueToInsert)
{
	Node<T>* newNode;
	newNode->val = valueToInsert;
	newNode->next = NULL;
	this->size++;

	Node<T>* temp = first;

	if (temp != NULL)
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}
	else
	{
		first = newNode;
	}
}

template <class T>
bool LinkedList<T>::Pop()
{
	if (first == NULL && last == NULL) { return false; }

	if (first == last)
	{
		std::cout << "First is equal to Last." << std::endl;
		delete(first);
		first = last = NULL;
		return true;
	}

	else
	{
		Node<T>* temp = first;
		int nodeCount = 0;

		while (temp != NULL)
		{
			nodeCount = nodeCount + 1;
			temp = temp->next;
		}

		Node<T>* temp2 = first;

		for (int i = 1; i < (nodeCount - 1); i++)
		{
			temp2 = temp2->next;
		}

		std::cout << temp2->val << std::endl;
		delete(temp2->next);

		last = temp2;
		last->next = NULL;
		this->size--;

		return true;
	}
}

template <class T>
void LinkedList<T>::Print()
{
	Node<T>* temp = first;

	if (temp == NULL)
	{
		std::cout << "";
	}

	if (temp->next == NULL)
	{
		std::cout << temp->val;
	}
	else
	{
		while (temp != NULL)
		{
			std::cout << temp->val;
			temp = temp->next;
			std::cout << ",";
		}
	}
}

template <class T>
bool LinkedList<T>::IsEmpty()
{
	if (first == NULL && last == NULL) { return true; }
	else { return false; }
}

template <class T>
int LinkedList<T>::GetLength()
{
	if (first == NULL && last == NULL) { return 0; }

	Node<T>* temp = first;
	int nodeCounter = 0;

	while (temp != NULL)
	{
		nodeCounter = nodeCounter + 1;
		temp = temp->next;
	}
	return nodeCounter;
}

template <class T>
void LinkedList<T>::Clear()
{
	Node<T>* temp = first;
	while (temp != NULL)
	{
		temp = temp->next;
		first = temp;
		delete(temp);
	}
}

template <class T>
void LinkedList<T>::Prepand(T valueToInsert)
{
	Node<T>* newNode;

	newNode->val = valueToInsert;

	if (first == NULL)
	{
		first = newNode;
	}
	else
	{
		newNode->next = first;
		first = newNode;
	}

}

template <class T>
T LinkedList<T>::GetFirst() {
	return this->first->val;
}

template <class T>
T LinkedList<T>::GetLast() {
	return this->last->val;
}

template <class T>
T LinkedList<T>::Get(int index) {
	Node<T>* node = this->first;

	for (int i = 0; i < index; i++)
	{
		node = node->next;
	}
	return node->val;
}

template <class T>
LinkedList<T>* LinkedList<T>::GetSubList(int startIndex, int endIndex) {
	LinkedList<T> list = new LinkedList<T>();
	for (int i = startIndex; i < endIndex; i++)
	{
		list.Append(this->Get(i));
	}

	return list;
}