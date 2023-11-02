#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\kiril\source\repos\ОІПЗ 5\ОІПЗ 5\Головний код.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(calculatorTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int n = 4;
			double x = 2;
			double expected = 6.85;
			double actual = calculator(n, x);
			Assert::AreEqual(expected, actual);
		}
	public:

		TEST_METHOD(TestMethod2)
		{
			int n = 3;
			double x = -8;
			double expected = -4;
			double actual = calculator(n, x);
			Assert::AreEqual(expected, actual);
		}
	public:

		TEST_METHOD(TestMethod3)
		{
			int n = 6;
			double x = -2;
			double expected = -5;
			double actual = calculator(n, x);
			Assert::AreEqual(expected, actual);
		}
	};
	TEST_CLASS(dataNChecking)
	{
	public:
		TEST_METHOD(CheckN1)
		{
			int n = 11;
			try
			{
				dataNChecking(n);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
	public:
		TEST_METHOD(CheckN2)
		{
			int n = 1;
			try
			{
				dataNChecking(n);
				Assert::Fail();
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}
		}

	};
	TEST_CLASS(dataHChecking)
	{
	public:
		TEST_METHOD(CheckH1)
		{
			double h = 1;
			try
			{
				dataHChecking(h);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
	public:
		TEST_METHOD(CheckH2)
		{
			double h = -2;
			try
			{
				dataHChecking(h);
				Assert::Fail();
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}
		}
	};
}
