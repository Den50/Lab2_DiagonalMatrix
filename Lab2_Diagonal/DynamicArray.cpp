#include "DynamicArray.h"
#include "complex.h"
#include <string>

//
// implementing methods of template DymamicArray
//

template DynamicArray<int>;
template DynamicArray<long>;
template DynamicArray<float>;
template DynamicArray<double>;
template DynamicArray<complex>;
template DynamicArray<std::string>;


// Create object
template<class T>
DynamicArray<T>::DynamicArray(T* items, int count)
{
    this->data = new T[count];
	this->size = count;
	for (int i = 0; i < count; i++)
	{
		this->data[i] = items[i];
	}
}

template<class T>
DynamicArray<T>::DynamicArray(int size)
{
	this->data = new T[size];
	this->size = size;
}

template<class T>
DynamicArray<T>::DynamicArray(DynamicArray<T>& dynamicArray) {
	this->size = dynamicArray.GetSize();
	this->data = new T[this->size];
	for (int i = 0; i < dynamicArray.GetSize(); i++)
	{
		this->Set(i, dynamicArray.Get(i));
	}
}

// decompose methods

template<class T>
int DynamicArray<T>::GetSize()
{
	return this->size;
}

template<class T>
T DynamicArray<T>::Get(int index)
{
	return this->data[index];
}

// operations methods

template<class T>
void DynamicArray<T>::Set(int index, T value) {
	this->data[index] = value;
}

template<class T>
void DynamicArray<T>::Resize(int newSize) {
	this->size = newSize;
}
