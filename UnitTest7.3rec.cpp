#include "pch.h"
#include "CppUnitTest.h"
#include "../Project7.2rec/Project7.2rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest73rec
{
	TEST_CLASS(UnitTest73rec)
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

			CreateRows(a, colCount, Low, High, 0);
			
			bool t = true;

			for (int i = 0; i < colCount; i++) {
				for (int j = 0; j < colCount; j++) {
					if (a[i][j] > 51 || a[i][j] < 4) {
						t = false;
					}
				}
			}
			Assert::AreEqual(t, true);
		}
	};
}
