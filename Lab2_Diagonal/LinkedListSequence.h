#pragma once

#include "Sequence.h"
#include "LinkedList.h"

namespace MAIN {
    template <class T>
    class LinkedListSequence : Sequence<T> {
    private:
        LinkedList<T> listSequence;
    public:
        class IndexOutOfRange : LinkedList<T>::IndexOutOfRange {};

        //�������� �������
        LinkedListSequence(T* items, int count) {
            listSequence = LinkedList<T>(items, count);
        }//�������� �������� �� ����������� �������
        LinkedListSequence() {
            listSequence = LinkedList<T>();
        }//������� ������ ������������������
        explicit LinkedListSequence(const LinkedList <T>& list) {
            listSequence = LinkedList<T>(list);
        }//���������� �����������

        //�������� �������
        ~LinkedListSequence() {
            listSequence.Delete_LinkedList();
        }//����������
        void Delete_LinkedListSequene() {
            listSequence.Delete_LinkedList();
        }//������� �������� ������������������

        //������������
        T GetFirst() {
            return listSequence.GetFirst();
        }//���������� ������ �������
        T GetLast() {
            return listSequence.GetLast();
        }//���������� ��������� �������
        T& Get(int index) {
            return listSequence.Get(index);
        }//���������� ������� �� �������
        LinkedListSequence<T>* GetSubsequence(int startIndex, int endIndex) {
            //auto *new_LinkedList = new LinkedList<T>;
            auto new_LinkedList = listSequence.GetSubList(startIndex, endIndex);
            auto* new_LinkedListSequence = new LinkedListSequence<T>(new_LinkedList);
            return new_LinkedListSequence;
        }//�������� ������ �� ���� ���������, ������� � startIndex � ���������� endIndex
        int GetLength() {
            return listSequence.GetLength();
        }

        //��������
        void Append(T item) {
            listSequence.Append(item);
        }//��������� ������� � ����� ������
        void Prepend(T item) {
            listSequence.Prepend(item);
        }//��������� ������� � ������ ������
        void InsertAt(T item, int index) {
            listSequence.InsertAt(item, index);
        }//��������� ������� � �������� �������
        LinkedListSequence<T>* Concat(Sequence<T>* list) {
            auto* new_LinkedList = new LinkedListSequence<T>(*this);
            for (int i = 0; i < list->GetLength(); i++) {
                new_LinkedList->Append(list->Get(i));
            }

            return new_LinkedList;
        }//�������� ��� ������

        //���������� ����������

        /*LinkedListSequence<T>& operator = (LinkedListSequence<T> listSequence) {
            listSequence = listSequence.listSequence;
            return *this;
        }*/

    };
}