#pragma once

namespace MAIN {
    template <class T>
    class DynamicArray {
    private:
        T* array;
        int len; //длина массива
        int size; //на сколько элементов массив расчитан - кол-во €чеек
    public:
        class IndexOutOfRange {};

        //—оздание объекта
        DynamicArray(T* items, int count); //создает пустой массив и копирует элементы из переданного массива (получаетс€ идентичный по размеру массив)
        explicit DynamicArray(int newSize); //создает пустой массив заданой длины
        DynamicArray(DynamicArray<T> const& dynamicArray); //создание копии исходного масива
        DynamicArray(); //создание пустого массива

        //”даление объекта
        ~DynamicArray();//деструктор
        void Delete_DynamicArray();//операци€ удалени€ массива

        //ƒекомпозици€
        T& Get(int index);//возвращает элемент по индексу
        int GetSize(); //возвращает длину массива(кол-во всех €чеек)
        int GetLen();//возвращает длину массива (кол-во заполненных €чеек)

        //ќперации над параметрами массивов
        void Set(int index, T value); //«адает элемент по индексу
        void Resize(int newSize); //измен€ет размерность массива
        void Relen(int newLen); //»змен€ет длину массива

        //ѕерегрузка операторов
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
