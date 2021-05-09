#include "LinkedList.h"
#include <complex>
#include <iostream>

using namespace std;
using namespace MAIN;

template LinkedList<int>;
template LinkedList<float>;
template LinkedList<double>;
template LinkedList<complex<double>>;
template LinkedList<string>;



template <class T>
LinkedList<T>::LinkedList() {
    size = 0;
    head_Node = nullptr;
    end_Node = nullptr;
}

template <class T>
LinkedList<T>::LinkedList(T* items, int count) {
    size = 0;
    head_Node = nullptr;
    end_Node = nullptr;

    for (int i = 0; i < count; i++) {
        Append(items[i]);
    }
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& list) {
    size = 0;
    head_Node = nullptr;
    end_Node = nullptr;
    struct Node* cell = list.head_Node;
    for (int i = 0; i < list.size; i++, cell = cell->next_Node) {
        Append(cell->value);
    }
}

template <class T>
T LinkedList<T>::GetFirst() {
    if (head_Node == nullptr) { throw IndexOutOfRange(); }

    return head_Node->value;
}

template <class T>
T LinkedList<T>::GetLast() {
    if (end_Node == nullptr) { throw IndexOutOfRange(); }

    return end_Node->value;
}

template <class T>
T& LinkedList<T>::Get(int index) {
    if (index < 0 || index >= size) { throw IndexOutOfRange(); }

    struct Node* cell = head_Node;
    for (int i = 0; i < index; i++, cell = cell->next_Node);

    return cell->value;
}

template <class T>
LinkedList<T> LinkedList<T>::GetSubList(int startIndex, int endIndex) {
    if (startIndex >= size || endIndex >= size || startIndex < 0 || endIndex < 0) {
        throw IndexOutOfRange();
    }

    LinkedList<T> new_list = LinkedList<T>();
    auto* cell = new struct Node;
    cell = head_Node;
    for (int i = 0; i < startIndex; i++, cell = cell->next_Node);
    for (int i = startIndex; i <= endIndex; i++, cell = cell->next_Node) {
        new_list.Append(cell->value);
    }

    return new_list;
}

template <class T>
int LinkedList<T>::GetLength() {
    return size;
}

template <class T>
void LinkedList<T>::Prepend(T item) {
    auto* new_cell = new struct Node;
    new_cell->value = item;

    if (head_Node == nullptr) {
        end_Node = new_cell;
    }

    new_cell->next_Node = head_Node;
    head_Node = new_cell;
    size++;
}

template <class T>
void LinkedList<T>::Append(T item) {
    auto* new_cell = new struct Node;
    new_cell->value = item;
    new_cell->next_Node = nullptr;

    if (head_Node == nullptr) {
        head_Node = new_cell;
        end_Node = new_cell;
        size = 1;
        return;
    }

    end_Node->next_Node = new_cell;
    end_Node = new_cell;
    size++;
}

template <class T>
void LinkedList<T>::InsertAt(T item, int index) {
    if (index >= size || index < 0) { throw IndexOutOfRange(); }

    if (index == 0) { Append(item); return; }
    else if (index == size - 1) { Prepend(item); return; }
    else {
        auto* new_cell = new struct Node;
        new_cell->value = item;
        struct Node* previous_cell = head_Node;
        for (int i = 0; i < index - 1; i++, previous_cell = previous_cell->next_Node);
        new_cell->next_Node = previous_cell->next_Node;
        previous_cell->next_Node = new_cell;
        size++;
    }
}

template<class T>
LinkedList<T> LinkedList<T>::Concat(LinkedList<T>* list) {
    LinkedList<T> new_list = LinkedList<T>();

    struct Node* new_cell = head_Node;
    for (int i = 0; i < size; i++, new_cell = new_cell->next_Node) {
        new_list.Append(new_cell->value);
    }

    new_cell = list->head_Node;
    for (int i = 0; i < list->size; i++, new_cell = new_cell->next_Node) {
        new_list.Append(new_cell->value);
    }

    return new_list;
}

template<class T>
T& LinkedList<T>::operator[](int index) {
    if (index < 0 || index > this->size - 1) {
        throw IndexOutOfRange();
    }
    struct Node* temp = head_Node;
    for (int i = 0; i < index; i++) {
        temp = temp->next_Node;
    }
    return temp->value;
}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T> linkedlist) {
    Delete_LinkedList();

    struct Node* cell = linkedlist.head_Node;
    for (int i = 0; i < linkedlist.size; i++, cell = cell->next_Node) {
        Append(cell->value);
    }
    return *this;
}

template<class T>
LinkedList<T>::~LinkedList() {
    Delete_LinkedList();
}

template <class T>
void LinkedList<T>::Delete_LinkedList() {
    struct Node* this_cell;
    while (head_Node != nullptr) {
        this_cell = head_Node;
        head_Node = head_Node->next_Node;
        delete this_cell;
    }
    end_Node = nullptr;
    size = 0;
}


template<class T>
void LinkedList<T>::Print() {
    for (int i = 0; i < this->size; i++)
        cout << "Element #" << i << ": " << this->Get(i) << std::endl;
}