#pragma once
#include "Sequence.h"
#include "DynamicArray.h"
#include "DynamicArray.cpp"

using namespace MAIN;

namespace MAIN {
    template <class T>
    class ArraySequence : Sequence<T> {
    private:
        DynamicArray<T> dynamicArray;
    public:
        class IndexOutOfRange : DynamicArray<T> ::IndexOutOfRange {};

        // Create new Array
        ArraySequence(T* items, int count) {
            dynamicArray = DynamicArray<T>(items, count);
        }
        // create new emty Array
        ArraySequence() {
            dynamicArray = DynamicArray<T>(0);
        }
        // create new array extends operand - copeis constructor
        explicit ArraySequence(const DynamicArray<T>& dynamicArray) {
            dynamicArray = DynamicArray<T>(dynamicArray);
        }

        // destructor
        ~ArraySequence() {
            dynamicArray.Delete_DynamicArray();
        }
        // Delete array function
        void Delete_ArraySequence() {
            dynamicArray.Delete_DynamicArray();
        }

        // Decompose

        // Get first item
        T GetFirst() {
            return dynamicArray.Get(0);
        }
        // Get last item
        T GetLast() {
            return dynamicArray.Get(dynamicArray.GetLen() - 1);
        }
        // get item by index
        T& Get(int index) {
            return dynamicArray.Get(index);
        }
        // Get subsequence from this sequence [startIndex, endIndex]
        ArraySequence<T>* GetSubsequence(int startIndex, int endIndex) {
            if (startIndex >= dynamicArray.GetLen() || endIndex >= dynamicArray.GetLen() || startIndex < 0 || endIndex < 0) {
                throw IndexOutOfRange();
            }

            auto* new_arraySequence = new ArraySequence<T>;
            int iter;
            if (startIndex < endIndex) {
                iter = 1;
            }
            else {
                iter = -1;
            }

            for (int i = startIndex; i != endIndex; i += iter) {
                new_arraySequence->Append(dynamicArray.Get(i));
            }

            return new_arraySequence;
        }
        // get size this sequence
        int GetLength() {
            return dynamicArray.GetLen();
        }

        // Operations

        // set item on index position
        ArraySequence<T>& Set(T item, int index){
            dynamicArray.Set(item, index);
            return *this;
        }
        // Append item to end of array
        void Append(T item) {
            int free_cells = dynamicArray.GetSize() - dynamicArray.GetLen();
            if (free_cells == 0) {
                dynamicArray.Resize(dynamicArray.GetSize() + 200);
            }
            dynamicArray.Relen(dynamicArray.GetLen() + 1);
            dynamicArray.Set(dynamicArray.GetLen() - 1, item);
        }

        // prepand item to start of array
        void Prepend(T item) {
            dynamicArray.Resize(dynamicArray.GetLen() + 1);
            dynamicArray.Relen(dynamicArray.GetLen() + 1);
            T saved_cell = dynamicArray.Get(0);
            T this_cell;
            dynamicArray.Set(0, item);

            for (int i = 1; i < dynamicArray.GetLen(); i++) {
                this_cell = dynamicArray.Get(i);
                dynamicArray.Set(i, saved_cell);
                saved_cell = this_cell;
            }
        }
        // insert item to array by index
        void InsertAt(T item, int index) {
            if (index < 0 || index >= this->GetLength()) { throw IndexOutOfRange(); }

            dynamicArray.Resize(dynamicArray.GetLen() + 1);
            dynamicArray.Relen(dynamicArray.GetLen() + 1);
            T this_cell;
            T saved_cell = dynamicArray.Get(index);
            dynamicArray.Set(index, item);
            for (int i = index + 1; i < dynamicArray.GetLen(); i++) {
                this_cell = dynamicArray.Get(i);
                dynamicArray.Set(i, saved_cell);
                saved_cell = this_cell;
            }
        }
        // concat two sequence to one
        ArraySequence<T>* Concat(Sequence<T>* list) {
            auto* new_arraySequence = new ArraySequence<T>;
            //new_arraySequence = ArraySequence<T>();

            for (int i = 0; i < dynamicArray.GetLen(); i++) {
                new_arraySequence->Append(dynamicArray.Get(i));
            }
            for (int i = 0; i < list->GetLength(); i++) {
                new_arraySequence->Append(list->Get(i));
            }

            return new_arraySequence;
        }

        // overloading operators =
        ArraySequence<T>& operator = (ArraySequence<T> n_dynamicArray) {
            dynamicArray = n_dynamicArray.dynamicArray;
            return *this;
        }
    };
}