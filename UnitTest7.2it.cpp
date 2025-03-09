#include "pch.h"
#include "CppUnitTest.h"
#include "../Project7.2/Project7.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72it
{
	TEST_CLASS(UnitTest72it)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int rowCount = 8;
			int colCount = rowCount;

			int Low = 4;
			int High = 51;

			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];

			Create(a, rowCount, colCount, Low, High);

			bool t = true;

			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					if (a[i][j] < Low || a[i][j] > High) {
						t = false;
					}
				}
					
			}

			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;

			Assert::AreEqual(t, true);
		}
	};
}
