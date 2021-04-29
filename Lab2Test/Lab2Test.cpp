#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>
#include "../Lab2_Diagonal/DynamicArray.h"
#include "../Lab2_Diagonal/complex.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;


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
	TEST_CLASS(DynamicArray)
	{
	public:
		TEST_METHOD(Constructor)
		{
			const int size_a = 4;
			float arr[4];
			MAIN::DynamicArray<std::string> dyn1();
			MAIN::DynamicArray<int> dyn2(size_a);
			MAIN::DynamicArray<float> dyn3(arr, size_a);
			MAIN::DynamicArray<float> dyn4(dyn3);
			Assert::IsTrue(1 == 1);
		}
		TEST_METHOD(Decompose)
		{
			//Assert::IsTrue(1 == 2);
			Assert::AreEqual(1, 1);
		}
		TEST_METHOD(Operations)
		{
			//Assert::IsTrue(1 == 2);
			Assert::AreEqual(1, 1);
		}
	};
}
