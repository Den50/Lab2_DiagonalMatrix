#pragma once

//using namespace std;

template <class T>
struct Node
{
    T val;
    Node<T>* next;
};

template <class T> class LinkedList{
    private:
        Node<T>* first;
        Node<T>* last;
        int size;
    public:
        // constructors
        LinkedList();
        LinkedList(T* items, int count);
        LinkedList(LinkedList <T>& list);

        // decompose
        int GetLength();
        T GetFirst();
        T GetLast();
        T Get(int index);
        LinkedList<T>* GetSubList(int startIndex, int endIndex);

        // operations methods
        void Append(T valueToInsert);
        void Prepand(T valueToInsert);
        //void InsertAt(T item, int index);
        //LinkedList<T>* Concat(LinkedList<T>* list);

        // other methods
        bool Pop();
        void Print();
        bool IsEmpty();
        void Clear();
};
