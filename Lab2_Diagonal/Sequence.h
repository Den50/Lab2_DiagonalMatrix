#pragma once


namespace MAIN {
    template <class T>
    class Sequence {
    public:
        // Decompose
        virtual T GetFirst() = 0; // return first element from list
        virtual T GetLast() = 0; // return last element from list
        virtual T& Get(int index) = 0; // return T* element by index
        virtual int GetLength() = 0; // return length list
        virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) = 0; // return subsequence from startIndex to endIndex

        // Operations
        virtual void Append(T item) = 0; // add item to beginning of the list
        virtual void Prepend(T item) = 0; // add item to end of the list
        virtual void InsertAt(T item, int index) = 0; // insert an element at a specified position
        virtual Sequence <T>* Concat(Sequence <T>* list) = 0; // concatenates two lists

        // Overloading operators
        //virtual T& operator[](int index) = 0; // return element by index; inherits this->Get
        //virtual bool operator==(Sequence<T>& seq) = 0; // return true if two sequence is equal and false else
    };
}