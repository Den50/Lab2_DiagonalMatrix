#pragma once

#include "Sequence.h"
#include "LinkedList.h"

namespace MAIN {
    template <class T>
    class LinkedListSequence : Sequence<T> {
    private:
        LinkedList<T> listSequence;
    public:
        class IndexOutOfRange : LinkedList<T>::IndexOutOfRange {};

        // Creating an object

        LinkedListSequence(T* items, int count) {
            listSequence = LinkedList<T>(items, count);
        }
        // Creates an empty sequence
        LinkedListSequence() {
            listSequence = LinkedList<T>();
        }
        // Copying Constructor
        explicit LinkedListSequence(const LinkedList <T>& list) {
            listSequence = LinkedList<T>(list);
        }

        // Deleting an object

        // destructor
        ~LinkedListSequence() {
            listSequence.Delete_LinkedList();
        }
        // delete sequence function
        void Delete_LinkedListSequene() {
            listSequence.Delete_LinkedList();
        }

        // Decomposition

        // Returns the first element
        T GetFirst() {
            return listSequence.GetFirst();
        }

        // Returns the last element
        T GetLast() {
            return listSequence.GetLast();
        }
        // Returns the element by index
        T& Get(int index) {
            return listSequence.Get(index);
        }

        // Get a list of all elements, starting with startIndex and ending with endIndex
        LinkedListSequence<T>* GetSubsequence(int startIndex, int endIndex) {
            auto new_LinkedList = listSequence.GetSubList(startIndex, endIndex);
            auto* new_LinkedListSequence = new LinkedListSequence<T>(new_LinkedList);
            return new_LinkedListSequence;
        }

        int GetLength() {
            return listSequence.GetLength();
        }

        // Operations

        // Adds an item to the end of the list
        void Append(T item) {
            listSequence.Append(item);
        }
        // Adds an item to the top of the list
        void Prepend(T item) {
            listSequence.Prepend(item);
        }
        // Inserts the element at the specified position
        void InsertAt(T item, int index) {
            listSequence.InsertAt(item, index);
        }
        // Concatenates two lists
        LinkedListSequence<T>* Concat(Sequence<T>* list) {
            auto* new_LinkedList = new LinkedListSequence<T>(*this);
            for (int i = 0; i < list->GetLength(); i++) {
                new_LinkedList->Append(list->Get(i));
            }

            return new_LinkedList;
        }

        // Operator overloading
        /*LinkedListSequence<T>& operator = (LinkedListSequence<T> listSequence) {
            listSequence = listSequence.listSequence;
            return *this;
        }*/

    };
}