#include "LinkedList.h"
#include "complex.h"
#include <iostream>

using namespace std;
using namespace MAIN;

template LinkedList<int>;
//template LinkedList<float>;
//template LinkedList<double>;
//template LinkedList<complex>;


template <class T>
LinkedList<T>::LinkedList()
{
	this->last = NULL;
	this->first = NULL;
	this->size = 0;
}

template <class T>
LinkedList<T>::LinkedList(T* items, int count) : LinkedList<T>::LinkedList()
{
	Node<T>* temp = this->first;
	for (int i = 0; i < count; i++)
		this->Append(items[i]);
}


template <class T>
LinkedList<T>::LinkedList(LinkedList <T>& list) : LinkedList<T>::LinkedList()
{
	for (int i = 0; i < list.GetLength(); i++)
		this->Append(list[i]);
}

template <class T>
void LinkedList<T>::Append(T valueToInsert)
{
	Node<T>* newNode = new Node<T>;
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
		this->first = newNode;
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
	Node<T>* temp = this->first;

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
	if (first == NULL && last == NULL) return true;
	return false;
}

template <class T>
int LinkedList<T>::GetLength()
{
	return this->size;
}


template <class T>
void LinkedList<T>::Prepand(T valueToInsert)
{
	Node<T>* newNode = new Node<T>;
	newNode->val = valueToInsert;
	this->size++;

	if (this->first == NULL)
	{
		this->first = newNode;
	}
	else
	{
		newNode->next = this->first;
		this->first = newNode;
	}

}

template <class T>
T LinkedList<T>::GetFirst() {
	return T(this->first->val);
}

template <class T>
T LinkedList<T>::GetLast() {
	return this->Get(this->GetLength() - 1);
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
T LinkedList<T>::operator[](int index) { return this->Get(index); }

template <class T>
void LinkedList<T>::InsertAt(T item, int index) {
	Node<T>* current = this->first;
	for (int i = 0; i < index - 1; i++)
	{
		current = current->next;
	}

	if (current == NULL) {
		this->Append(item);
	}
	else {
		Node<T>* tmpItem = new Node<T>;
		tmpItem->val = item;
		tmpItem->prev = current;
		tmpItem->next = current->next;
		current->next->prev = tmpItem;
		current->next = tmpItem;
		this->size++;
	}
}


//template <class T>
//LinkedList<T>* LinkedList<T>::GetSubList(int startIndex, int endIndex) {
//	LinkedList<T> list;
//	for (int i = startIndex; i < endIndex; i++)
//		list.Append(this->Get(i));
//
//	return list;
//}

//template <class T>
//void LinkedList<T>::Set(LinkedList<T>& source) {
//	for (int i = 0; i < source.GetLength(); i++)
//	{
//		this->Append(source.Get(i));
//	}
//}
//
//template <class T>
//LinkedList<T>* Concat(LinkedList<T>* list) {
//	for (int i = 0; i < list->GetLength(); i++)
//		this->Append(list[i]);
//}