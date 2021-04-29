#include "DynamicArray.h"
#include "complex.h"
#include <stdexcept>
#include <string>
#include <cassert>
#include <iostream>

using namespace std;
using namespace MAIN;

//
// implementing methods of template DymamicArray
//

template DynamicArray<int>;
template DynamicArray<long>;
template DynamicArray<float>;
template DynamicArray<double>;
template DynamicArray<Complex>;
template DynamicArray<string>;


// Create object
template<class T>
DynamicArray<T>::DynamicArray(T* items, int count)
{
	assert(count >= 0, "$Count cannot be less then 0");
	if (count < 0) {
		throw invalid_argument("[ERROR] Count cannot be less then 0");
	}else {
		this->data = new T[count];
		this->size = count;
		for (int i = 0; i < count; i++)
		{
			this->data[i] = items[i];
		}
	}
}

template<class T>
DynamicArray<T>::DynamicArray(int size)
{
	assert(size >= 0);
	if (size < 0) {
		throw invalid_argument("[ERROR] Count cannot be less then 0");
	}
	else {
		this->data = new T[size];
		this->size = size;
	}
	
}
template<class T>
DynamicArray<T>::DynamicArray() : DynamicArray<T>::DynamicArray(0) {}

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
	assert(index > -1);
	return index >= 0? this->data[index]: throw invalid_argument("[ERROR] index < 0");
}

template<class T>
T DynamicArray<T>::operator[](int index) { return this->Get(index); }
// operations methods


template<typename T> 
bool DynamicArray<T>::operator==(DynamicArray<T>& arr) {
	if (this->size != arr.size) {
		return false;
	}
	for (int i = 0; i < this->size; i++) {
		if (this->Get(i) != arr.Get(i)) {
			return false;
		}
	}
	return true;
}

template<class T>
void DynamicArray<T>::Set(int index, T value) {
	assert(-1 < index);
	if (index >= 0) {
		if (index >= this->size)
			this->Resize(index + 1);
		this->data[index] = value;
	}
	else
		throw invalid_argument("[ERROR] index < 0, index ");
}

template<class T>
void DynamicArray<T>::Resize(int newSize) {
	T* newArr = new T[newSize];
	int _size = newSize > this->size ? newSize : this->size;

	for (int i = 0; i < size; i++)
		newArr[i] = this->Get(i);

	this->size = newSize;
	delete[] this->data;
	this->data = newArr;
}


template<>
void DynamicArray<int>::Print() {
	for (int i = 0; i < this->size; i++)
	{
		std::cout << "Element #" << i << ": " << this->Get(i) << std::endl;
	}
}


template<>
void DynamicArray<float>::Print() {
	for (int i = 0; i < this->size; i++)
	{
		std::cout << "Element #" << i << ": " << this->Get(i) << endl;
	}
}


template<>
void DynamicArray<string>::Print() {
	for (int i = 0; i < this->size; i++)
	{
		std::cout << "Element #" << i << ": \"" << this->Get(i) << "\"" << endl;
	}
}


template<>
void DynamicArray<Complex>::Print() {
	for (int i = 0; i < this->size; i++)
	{
		std::cout << "Element #" << i << ": cmlx(" << this->Get(i).getReal() << ", " << this->Get(i).getIm() << "i)" << endl;
	}
}