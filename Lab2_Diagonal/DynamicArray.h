#pragma once

namespace MAIN {
    template <class T>
    class DynamicArray {
    private:
        T* array;
        int len; // length array
        int size; // how many elements the array is designed for - number of cells
    public:
        class IndexOutOfRange {};

        // create object
        DynamicArray(T* items, int count); // creates an empty array and copies the elements from the passed array (an identical array is obtained)
        explicit DynamicArray(int newSize); // creates an empty array of the specified length
        DynamicArray(DynamicArray<T> const& dynamicArray); // creating a copy of the original masive
        DynamicArray(); // creating an empty array

        // Deleting an object
        ~DynamicArray(); // destructor
        void Delete_DynamicArray(); // delete array operation

        // Decomposition
        T& Get(int index); // returns the element by index
        int GetSize(); // returns the length of the array(number of all cells)
        int GetLen(); // returns the length of the array (number of filled cells)

        // Operations on array parameters 
        void Set(int index, T value); // Sets the element by index
        void Resize(int newSize); // changes the dimension of the array
        void Relen(int newLen); // Changes the length of the array

        // Operator overloading
        DynamicArray<T>& operator = (DynamicArray<T> dynamicArray) {
            Resize(dynamicArray.GetSize());
            size = dynamicArray.GetSize();
            len = dynamicArray.GetLen();
            for (int i = 0; i < len; i++) {
                array[i] = dynamicArray.array[i];
            }
            return *this;
        }
    };

}
