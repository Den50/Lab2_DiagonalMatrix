#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>
#include "../Lab2_Diagonal/DynamicArray.h"
#include "../Lab2_Diagonal/ArraySequence.h"
#include "../Lab2_Diagonal/LinkedList.h"
#include "../Lab2_Diagonal/LinkedListSequence.h"
#include "../Lab2_Diagonal/complex.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

float round_float(float a, int order) {
	for (int i = 0; i < order; i++) {
		a = a * 10;
	}
	a = (float)(int)a / 10;
	for (int i = 0; i < order - 1; i++) {
		a = a / 10;
	}
	return a;
}

namespace Lab2Test
{
	TEST_CLASS(Complex)
	{
	public:
		TEST_METHOD(Constructor)
		{
			Logger::WriteMessage(L"Complex: Constructor test");
			MAIN::Complex b = MAIN::Complex();
			MAIN::Complex a = MAIN::Complex(0.1, 0.2);
			MAIN::Complex c = MAIN::Complex(a);
			
			Assert::IsTrue(b.getReal() == 0.0 && b.getIm() == 0.0, L"Constructors 1");
			Assert::IsTrue(a.getReal() == 0.1 && a.getIm() == 0.2, L"Constructors 2");
			Assert::IsTrue(a == MAIN::Complex(0.1, 0.2), L"Constructors 3");
			Assert::IsTrue(c == a, L"Constructors 4");
		}
		TEST_METHOD(Summ)
		{
			Logger::WriteMessage(L"Complex: Summ test");
			MAIN::Complex a = MAIN::Complex(10, 5);
			MAIN::Complex b = MAIN::Complex(20.1, 0.41);
			MAIN::Complex c = a + b;
			MAIN::Complex d = MAIN::Complex(0.000001, 0.000002) + MAIN::Complex(0.000005, 0.000006);
			MAIN::Complex e = MAIN::Complex(100000, 200000) + MAIN::Complex(300000, 400000);

			Assert::IsTrue(c == a + b, L"Summ 1");
			Assert::IsTrue(c.getReal() == 30.1 && c.getIm() == 5.41, L"Summ 2");
			Assert::IsTrue(e == MAIN::Complex(400000, 600000), L"Summ 3");
		}
		TEST_METHOD(Sub)
		{
			Logger::WriteMessage(L"Complex: Sub test");
			MAIN::Complex a = MAIN::Complex(10, 5);
			MAIN::Complex b = MAIN::Complex(20.1, 0.41);
			MAIN::Complex c = a - b;
			MAIN::Complex d = MAIN::Complex(0.000001, 0.000002) - MAIN::Complex(0.000005, 0.000006);
			MAIN::Complex e = MAIN::Complex(100000, 200000) - MAIN::Complex(300000, 400000);

			Assert::IsTrue(c == a - b, L"Sub 1");
			//Assert::IsTrue(d == MAIN::Complex(-0.000004, -0.000004), L"sub 2");
			Assert::IsTrue(e == MAIN::Complex(-200000, -200000), L"Sub 3");
		}
		TEST_METHOD(Multiply)
		{
			Logger::WriteMessage(L"Complex: Multiply test");
			MAIN::Complex a = MAIN::Complex(10, 5);
			MAIN::Complex b = MAIN::Complex(20.1, 0.41);
			MAIN::Complex c = a * b;
			MAIN::Complex d = MAIN::Complex(0.000001, 0.000002) * MAIN::Complex(0.000005, 0.000006);
			MAIN::Complex e = MAIN::Complex(100000, 200000) * MAIN::Complex(300000, 400000);

			Assert::IsTrue(c == a * b, L"Mult 1");
			Assert::IsTrue(c.getReal() - 198.95 < 1E-8 && c.getIm() - 104.6 < 1E-8, L"Mult 2");
			//Assert::IsTrue(d == MAIN::Complex(1.6E-11, 1.6E-11), L"Mult 3");
			//Assert::IsTrue(e == MAIN::Complex(1E11, 1E11), L"Mult 4");
		}
		TEST_METHOD(MultiplyOnAlpha)
		{
			Logger::WriteMessage(L"Complex: Multiply on Alpha test");
			MAIN::Complex a = MAIN::Complex(10, 5);
			MAIN::Complex b = MAIN::Complex(20.1, 0.41);
			MAIN::Complex c = a * 0.1;
			MAIN::Complex d = b * 100;

			Assert::IsTrue(c == a * 0.1, L"Mult 1");
			Assert::IsTrue(d == b * 100, L"Mult 2");
			Assert::IsTrue(c.getReal() == 1 && c.getIm() == 0.5, L"Mult 3");
			//Assert::IsTrue(d == MAIN::Complex(1.6E-11, 1.6E-11), L"Mult 3");
			//Assert::IsTrue(e == MAIN::Complex(1E11, 1E11), L"Mult 4");
		}
	};

	TEST_CLASS(TestArraySequence)
	{
	public:
		TEST_METHOD(Constructor)
		{
			ArraySequence<int> AS1;
			srand(45413634);
			assert(AS1.GetLength() == 0);

			for (int i = 1; i < 10000; i++) {
				auto arr = new int[i];
				for (int j = 0; j < i; j++) {
					arr[j] = rand();
				}
				ArraySequence<int> AS2(arr, i);
				Assert::IsTrue(AS2.GetLength() == i);
				for (int k = 0; k < i; k++) {
					assert(AS2.Get(k) == arr[k]);
				}
				ArraySequence<int> AS3(AS2);
				Assert::IsTrue(AS3.GetLength() == AS2.GetLength());
				Assert::IsTrue(AS2.GetLength() == i);
				for (int k = 0; k < i; k++) {
					assert(AS3.Get(k) == AS2.Get(k));
				}

				AS3.Delete_ArraySequence();
				AS2.Delete_ArraySequence();
				delete[] arr;
			}
			AS1.Delete_ArraySequence();
		}
		TEST_METHOD(Decomposition)
		{
			srand(454135234);
			for (int i = 10; i < 1000; i++) {
				auto arr = new int[i];
				for (int j = 0; j < i; j++) {
					arr[j] = rand();
				}
				ArraySequence<int> AS(arr, i);
				Assert::IsTrue(AS.GetFirst() == arr[0]);
				Assert::IsTrue(AS.GetLast() == arr[i - 1]);
				Assert::IsTrue(AS.GetLength() == i);
				for (int k = 0; k < i; k++) {
					Assert::IsTrue(AS.Get(k) == arr[k]);
				}
				/*
				for (int a = 0; a < i; a++){
					for (int b = 0; b < a; b++){
						ArraySequence<int> AS1 (*(AS.GetSubsequence(b, a)));
						assert(AS1.GetLength() == a - b);
						for (int k = 0; k < a - b; k++){
							assert(AS1.Get(k) == AS.Get(k + b));
						}
						AS1.Delete_ArraySequence();
					}
				}
				*/
				AS.Delete_ArraySequence();
				delete[] arr;
			}
		}
		TEST_METHOD(Operations)
		{
			srand(42513634);
			for (int i = 10; i < 10000; i++) {
				auto arr = new int[i];
				for (int j = 0; j < i; j++) {
					arr[j] = rand();
				}
				ArraySequence<int> AS(arr, i);
				int item = rand();
				int item_cpy = rand();
				AS.Append(item);
				Assert::IsTrue(AS.GetLength() == i + 1);
				Assert::IsTrue(AS.Get(i) == item);
				AS.Prepend(item);
				Assert::IsTrue(AS.GetLength() == i + 2);
				Assert::IsTrue(AS.Get(0) == item);
				AS.Set(i, item_cpy);
				Assert::IsTrue(AS.GetLength() == i + 2);
				Assert::IsTrue(AS.Get(i) == item_cpy);

				AS.InsertAt(item_cpy, i);
				Assert::IsTrue(AS.GetLength() == i + 3);
				Assert::IsTrue(AS.Get(i) == item_cpy);

				AS.Delete_ArraySequence();
				delete[] arr;
			}
		}
	};

	TEST_CLASS(TestLinkedListSequence) {
	public:
		TEST_METHOD(Constructors) {
			LinkedListSequence<int> LLS1;
			Assert::IsTrue(LLS1.GetLength() == 0);
			srand(4540924);

			for (int i = 1; i < 2000; i++) {
				auto arr = new int[i];
				for (int j = 0; j < i; j++) {
					arr[j] = rand();
				}
				LinkedListSequence<int> LLS2(arr, i);
				Assert::IsTrue(LLS2.GetLength() == i);
				for (int k = 0; k < i; k++) {
					Assert::IsTrue(LLS2.Get(k) == arr[k]);
				}
				LinkedListSequence<int> LLS3(LLS2);
				Assert::IsTrue(LLS3.GetLength() == LLS2.GetLength());
				for (int k = 0; k < i; k++) {
					Assert::IsTrue(LLS3.Get(k) == LLS2.Get(k));
				}

				LLS2.Delete_LinkedListSequene();
				LLS3.Delete_LinkedListSequene();
				delete[] arr;
			}
			LLS1.Delete_LinkedListSequene();
		}

		TEST_METHOD(Decomposition) {
			srand(454163545);
			for (int i = 10; i < 2000; i++) {
				auto arr = new int[i];
				for (int j = 0; j < i; j++) {
					arr[j] = rand();
				}
				LinkedListSequence<int> LLS(arr, i);
				Assert::IsTrue(LLS.GetFirst() == arr[0]);
				Assert::IsTrue(LLS.GetLast() == arr[i - 1]);
				Assert::IsTrue(LLS.GetLength() == i);
				for (int k = 0; k < i; k++) {
					Assert::IsTrue(LLS.Get(k) == arr[k]);
				}
				LLS.Delete_LinkedListSequene();
				delete[] arr;
			}
		}
		TEST_METHOD(Operations) {
			srand(4544541);
			for (int i = 10; i < 2000; i++) {
				auto arr = new int[i];
				for (int j = 0; j < i; j++) {
					arr[j] = rand();
				}
				LinkedListSequence<int> LLS(arr, i);
				int item = rand();
				LLS.Append(item);
				Assert::IsTrue(LLS.GetLength() == i + 1);
				Assert::IsTrue(LLS.Get(i) == item);
				LLS.Prepend(item);
				Assert::IsTrue(LLS.GetLength() == i + 2);
				Assert::IsTrue(LLS.Get(0) = item);
				LLS.Delete_LinkedListSequene();
				delete[] arr;
			}
		}
	};

	TEST_CLASS(TestDynamicArray) {
	public:
		TEST_METHOD(Constructor) {
			// _1_
			int _arr[] = { 1, 2, 3, 4, 5 };
			DynamicArray<int> d1(_arr, 5);
			Assert::IsTrue(d1.GetLen() == 5);
			Assert::IsTrue(d1.GetSize() == 5);
			Assert::IsTrue(d1.Get(3) == 4);
			d1.Resize(8);
			Assert::IsTrue(d1.GetSize() == 8);
			Assert::IsTrue(d1.GetLen() == 5);
			d1.Set(3, 10);
			Assert::IsTrue(d1.Get(3) == 10);
			d1.Resize(0);
			Assert::IsTrue(d1.GetLen() == 0);
			Assert::IsTrue(d1.GetSize() == 0);
			d1.Delete_DynamicArray();

			// _2_
			DynamicArray<int> arr1(10);
			Assert::IsTrue(arr1.GetSize() == 10);
			Assert::IsTrue(arr1.GetLen() == 0);
			arr1.Delete_DynamicArray();

			// _3_ 
			DynamicArray<int> d2(_arr, 5);
			DynamicArray<int> b(d2);
			Assert::IsTrue(b.GetSize() == 5);
			Assert::IsTrue(b.Get(2) == 3);
			Assert::IsTrue(b.Get(1) == 2);
			d2.Delete_DynamicArray();
			b.Delete_DynamicArray();

			// _4_
			DynamicArray<int> arr2;
			Assert::IsTrue(arr2.GetSize() == 0);
			Assert::IsTrue(arr2.GetLen() == 0);
			arr2.Delete_DynamicArray();
		}
		TEST_METHOD(Operations) {
			// Get
			int arr[] = { 1, 2, 3, 4, 5 };
			DynamicArray<int> d1(arr, 5);
			Assert::IsTrue(d1.Get(3) == 4);
			Assert::IsTrue(d1.Get(4) == 5);
			Assert::IsTrue(d1.Get(0) == 1);
			d1.Delete_DynamicArray();

			// GetSize
			DynamicArray<int> d2(arr, 5);
			Assert::IsTrue(d2.GetSize() == 5);
			d2.Delete_DynamicArray();

			// GetLen
			DynamicArray<int> d3(arr, 5);
			Assert::IsTrue(d3.GetLen() == 5);
			d3.Delete_DynamicArray();

			// Set
			DynamicArray<int> d4(arr, 5);
			d4.Set(3, 100);
			Assert::IsTrue(d4.Get(3) == 100);
			Assert::IsTrue(d4.Get(2) == 3);
			d4.Delete_DynamicArray();

			// Resize
			DynamicArray<int> d5(arr, 5);
			Assert::IsTrue(d5.GetSize() == 5);
			d5.Resize(10);
			Assert::IsTrue(d5.GetSize() == 10);
			Assert::IsTrue(d5.GetLen() == 5);
			d5.Delete_DynamicArray();
		}
	};

	TEST_CLASS(TestLinkedList) {
		TEST_METHOD(Constructor) {
			float arr[] = { 5.5, 6.6, -7.8, -9.9, 0 };

			// _1_
			LinkedList<float> list1(arr, 5);
			Assert::IsTrue(list1.GetLength() == 5);
			Assert::IsTrue(round_float(list1.Get(1), 1) == round_float(6.6, 1));
			list1.Delete_LinkedList();

			// _2_
			LinkedList<float> list2;
			Assert::IsTrue(list2.GetLength() == 0);
			list2.Delete_LinkedList();

			// _3_
			LinkedList<float> list3(arr, 5);
			LinkedList<float> list4(list3);
			Assert::IsTrue(list3.GetLength() == list4.GetLength());
			Assert::IsTrue(list3.Get(3) == list4.Get(3));
			Assert::IsTrue(list3.Get(0) == list4.Get(0));
			Assert::IsTrue(list3.Get(2) == list4.Get(2));
			list3.Delete_LinkedList();
			list4.Delete_LinkedList();
		}

		TEST_METHOD(Operations) {
			float arr[] = { 5.5, 6.6, -7.8, -9.9, 0 };

			// GetFirst
			LinkedList<float> list1(arr, 5);
			Assert::IsTrue(round_float(list1.GetFirst(), 2) == round_float(5.5, 2));
			list1.Delete_LinkedList();

			// GetLast
			LinkedList<float> list2(arr, 5);
			Assert::IsTrue(round_float(list2.GetLast(), 2) == round_float(0, 2));
			list2.Delete_LinkedList();

			// Get
			LinkedList<float> list3(arr, 5);
			Assert::IsTrue(round_float(list3.Get(0), 2) == round_float(5.5, 2));
			Assert::IsTrue(round_float(list3.Get(1), 2) == round_float(6.6, 2));
			Assert::IsTrue(round_float(list3.Get(3), 2) == round_float(-9.9, 2));
			list3.Delete_LinkedList();

			// GetSubList
			LinkedList<float> list4(arr, 5);
			LinkedList<float> list5(list4.GetSubList(1, 3));
			Assert::IsTrue(round_float(list5.Get(0), 2) == round_float(6.6, 2));
			Assert::IsTrue(round_float(list5.Get(1), 2) == round_float(-7.8, 2));
			Assert::IsTrue(round_float(list5.Get(2), 2) == round_float(-9.9, 2));
			Assert::IsTrue(list5.GetLength() == 3);
			list4.Delete_LinkedList();
			list5.Delete_LinkedList();

			// GetLength
			LinkedList<float> list6(arr, 5);
			Assert::IsTrue(list6.GetLength() == 5);
			list6.Delete_LinkedList();

			// Append
			LinkedList<float> list7(arr, 5);
			list7.Append(-10.5);
			Assert::IsTrue(list7.GetLength() == 6);
			Assert::IsTrue(round_float(list7.Get(5), 2) == round_float(-10.5, 2));
			Assert::IsTrue(round_float(list7.Get(4), 2) == round_float(0, 2));

			LinkedList<int> list8;
			list8.Append(5);
			Assert::IsTrue(list8.GetLength() == 1);
			Assert::IsTrue(list8.Get(0) == 5);
			list7.Delete_LinkedList();
			list8.Delete_LinkedList();

			// Prepand
			LinkedList<float> list9(arr, 5);
			list9.Prepend(3.5);
			Assert::IsTrue(list9.GetLength() == 6);
			Assert::IsTrue(round_float(list9.Get(0), 2) == round_float(3.5, 2));
			Assert::IsTrue(round_float(list9.Get(1), 2) == round_float(5.5, 2));

			LinkedList<int> list10;
			list10.Prepend(5);
			Assert::IsTrue(list10.GetLength() == 1);
			Assert::IsTrue(list10.Get(0) == 5);
			list10.Delete_LinkedList();
			list10.Delete_LinkedList();

			// InsertAt
			LinkedList<float> list11(arr, 5);
			list11.InsertAt(4, 3);
			Assert::IsTrue(list11.GetLength() == 6);
			Assert::IsTrue(round_float(list11.Get(3), 2) == round_float(4, 2));
			Assert::IsTrue(round_float(list11.Get(2), 2) == round_float(-7.8, 2));
			Assert::IsTrue(round_float(list11.Get(4), 2) == round_float(-9.9, 2));
			list11.Delete_LinkedList();

			// Concat
			LinkedList<float> list12(arr, 5);
			float arr2[] = { 5.5, 6.6, -7.8, -9.9, 0 };
			LinkedList<float> list13(arr, 5);
			LinkedList<float> list14(list12.Concat(&list13));
			Assert::IsTrue(list14.GetLength() == 10);
			Assert::IsTrue(round_float(list14.Get(5), 2) == round_float(5.5, 2));
			list12.Delete_LinkedList();
			list13.Delete_LinkedList();
			list14.Delete_LinkedList();
		}
	};
}
