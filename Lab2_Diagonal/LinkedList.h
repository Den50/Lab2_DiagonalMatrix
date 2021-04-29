#pragma once

namespace MAIN {
    template <class T>
    class LinkedList {
    private:
        struct Node {
            T value;
            struct Node* next_Node;
        };
        int size = 0;
        // nullptr is a keyword that can be used at all places where NULL is expected like NULL
        struct Node* head_Node = nullptr;
        struct Node* end_Node = nullptr;

    public:
        class IndexOutOfRange {};

        // Constuctors
        LinkedList(T* items, int count); // Copies all elements from T* items
        LinkedList(); // Create empty list
        LinkedList(const LinkedList <T>& list); // Copyed constructor

        // Delete object
        ~LinkedList(); // destructor
        void Delete_LinkedList(); // delete list

        // Decompose
        T GetFirst(); // return first element
        T GetLast(); // return last element
        T& Get(int index); // return T* element by index
        LinkedList<T> GetSubList(int startIndex, int endIndex); // return sublist from int startIndex to endIndex
        int GetLength(); // return length

        // Operations
        void Append(T item); // add element to end this list
        void Prepend(T item); // add element to the beginning of the list
        void InsertAt(T item, int index); // insert an element at a specified position
        LinkedList<T> Concat(LinkedList<T>* list); // concatenates two lists

        // Overloading operators
        T& operator[](int index); // return T* element by index; inherits this->Get
        LinkedList<T>& operator = (LinkedList<T> linkedlist); // completely copies the given list

        // Other methods
        void Print(); // displays a list depending on the type 
    };
}