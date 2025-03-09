#include "pch.h"
#include "CppUnitTest.h"
#include "../Project7.1/Project7.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int rowCount = 8;
			int colCount = 5;

			int Low = 4;
			int High = 51;

			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];

			Create(a, rowCount, colCount, Low, High);
			bool t = true;
			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++)
					if (a[i][j] > 51 && a[i][j] < 4) {
						t = false;
					}
			}

			Assert::AreEqual(t,true);
		}
	};
}

