#pragma once

template <class T> class DynamicArray {
	private:
		T* data;
		int size;
	public:
		// Create object
		DynamicArray(T* items, int count);
		DynamicArray(int size);
		DynamicArray(DynamicArray<T>& dynamicArray);

		// decompose
		T Get(int index);
		int GetSize();

		// operations
		void Set(int index, T value);
		void Resize(int newSize);
};