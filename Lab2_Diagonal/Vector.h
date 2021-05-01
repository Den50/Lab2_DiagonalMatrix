#pragma once

#include <iostream>
#include "ArraySequence.h"

namespace MAIN {
    template<class T>
    class Vector {
    private:
        ArraySequence<T> vector;
    public:
        //�������� �������
        Vector() {
            ArraySequence<T> new_vector;
            vector = new_vector;
        }//�������� ������� �������
        Vector(T* coords, int count) {
            ArraySequence<T> new_vector(coords, count);
            vector = new_vector;
        }// �������� ������� �� �������
        explicit Vector(ArraySequence<T>& n_vector) {
            vector = n_vector;
        }//���������� �����������

        //�������� �������
        ~Vector() {
            vector.Delete_ArraySequence();
        }
        void Delete_Vector() {
            vector.Delete_ArraySequence();
        }

        //������������
        T& GetCoord(int index) {
            return vector.Get(index);
        }
        int GetVectorLen() {
            return vector.GetLength();
        }

        //��������
        Vector<T> SumOfVectors(Vector<T> b) {
            Vector<T> new_vector;
            if (vector.GetLength() == b.vector.GetLength()) {
                for (int i = 0; i < vector.GetLength(); i++) {
                    new_vector.vector.Append(this->vector.Get(i) + b.vector.Get(i));
                }
            }
            else {
                int maxlen;
                int minlen;
                Vector<T> biger_vector;
                if (vector.GetLength() > b.vector.GetLength()) {
                    biger_vector = Vector<T>(vector);//c *this ���� ��������
                    maxlen = vector.GetLength();
                    minlen = b.vector.GetLength();
                }
                else {
                    biger_vector = Vector<T>(b);
                    maxlen = b.vector.GetLength();
                    minlen = vector.GetLength();
                }

                for (int i = 0; i < minlen; i++) {
                    new_vector.vector.Append(this->vector.Get(i) + b.vector.Get(i));
                }
                for (int i = minlen; i < maxlen; i++) {
                    new_vector.vector.Append(biger_vector.vector.Get(i));
                }
            }
            return new_vector;
        }//c����� ������� ����� �����������
        Vector<T> SubOfVectors(Vector<T> b) {
            Vector<T> new_vector;
            if (vector.GetLength() == b.vector.GetLength()) {
                for (int i = 0; i < vector.GetLength(); i++) {
                    new_vector.vector.Append(this->vector.Get(i) - b.vector.Get(i));
                }
            }
            else {
                int maxlen;
                int minlen;
                int scalar;
                Vector<T> biger_vector;
                if (vector.GetLength() > b.vector.GetLength()) {
                    biger_vector = Vector<T>(vector);//c *this ���� ��������
                    scalar = 1;
                    maxlen = vector.GetLength();
                    minlen = b.vector.GetLength();
                }
                else {
                    biger_vector = Vector<T>(b);
                    scalar = -1;
                    maxlen = b.vector.GetLength();
                    minlen = vector.GetLength();
                }

                for (int i = 0; i < minlen; i++) {
                    new_vector.vector.Append(this->vector.Get(i) - b.vector.Get(i));
                }
                for (int i = minlen; i < maxlen; i++) {
                    new_vector.vector.Append(biger_vector.vector.Get(i) * scalar);
                }
            }
            return new_vector;
        }
        Vector<T> MulOfVectors(T scalar) {
            Vector<T> new_vector;
            for (int i = 0; i < vector.GetLength(); i++) {
                new_vector.vector.Append(this->vector.Get(i) * scalar);
            }
            return new_vector;
        }
        Vector<T> Normalization() {
            T len = 0;
            for (int i = 0; i < vector.GetLength(); i++) {
                len = len + vector.Get(i) * vector.Get(i);
            }
            //����� ������� ��� ������ len ��� ����������� �����
            len = sqrt(len);
            Vector<T> new_vector;
            for (int i = 0; i < vector.GetLength(); i++) {
                new_vector.vector.Append(this->vector.Get(i) / len);
            }
            //������� ������� ����������
            return new_vector;
        }// TODO ���� �������� ��� �����������
        T ScalarMulOfVectors(Vector<T> b) {
            T scalar = vector.Get(0) * b.vector.Get(0);
            int minlen;
            if (vector.GetLength() > b.vector.GetLength()) {
                minlen = b.vector.GetLength();
            }
            else {
                minlen = vector.GetLength();
            }
            for (int i = 1; i < minlen; i++) {
                scalar = scalar + vector.Get(i) * b.vector.Get(i);
            }

            return scalar;
        }

        //���������� ����������
        friend std::ostream& operator << (std::ostream& cout, Vector<T>& n_vector) {
            cout << '{';
            for (int i = 0; i < n_vector.GetVectorLen(); i++) {
                cout << n_vector.GetCoord(i);
                if (i != n_vector.GetVectorLen() - 1) {
                    cout << ", ";
                }
            }
            cout << '}';
            return cout;
        }

        Vector<T>& operator = (Vector<T> n_vector) {
            vector = n_vector.vector;
            return *this;
        }

    };
}