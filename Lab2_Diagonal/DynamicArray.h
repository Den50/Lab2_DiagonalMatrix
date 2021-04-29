#pragma once

namespace MAIN {
	template <class T> class DynamicArray {
	private:
		T* data;
		int size;
	public:
		// Create object
		DynamicArray();
		DynamicArray(int size);
		DynamicArray(T* items, int count);
		DynamicArray(DynamicArray<T>& dynamicArray);

		// decompose
		T Get(int index);
		int GetSize();

		// operations
		void Set(int index, T value);
		void Resize(int newSize);
		T operator[](int index);
		bool operator==(DynamicArray<T>& arr);

		// other methods
		void Print();

		//Destructor
		~DynamicArray() {
			delete[] this->data;
		};
	};
}
