#pragma once

namespace MAIN {
    template <class T>
    class DynamicArray {
    private:
        T* array;
        int len; //����� �������
        int size; //�� ������� ��������� ������ �������� - ���-�� �����
    public:
        class IndexOutOfRange {};

        //�������� �������
        DynamicArray(T* items, int count); //������� ������ ������ � �������� �������� �� ����������� ������� (���������� ���������� �� ������� ������)
        explicit DynamicArray(int newSize); //������� ������ ������ ������� �����
        DynamicArray(DynamicArray<T> const& dynamicArray); //�������� ����� ��������� ������
        DynamicArray(); //�������� ������� �������

        //�������� �������
        ~DynamicArray();//����������
        void Delete_DynamicArray();//�������� �������� �������

        //������������
        T& Get(int index);//���������� ������� �� �������
        int GetSize(); //���������� ����� �������(���-�� ���� �����)
        int GetLen();//���������� ����� ������� (���-�� ����������� �����)

        //�������� ��� ����������� ��������
        void Set(int index, T value); //������ ������� �� �������
        void Resize(int newSize); //�������� ����������� �������
        void Relen(int newLen); //�������� ����� �������

        //���������� ����������
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
