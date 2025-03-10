#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo);
void CreateRows(int** a, const int N, const int Low, const int High, int rowNo);
void PrintRow(int** a, const int rowNo, const int N, int colNo);
void PrintRows(int** a, const int N, int rowNo);
void Sort(int** a, int rowCount, int col);
void SortF(int** a, int rowCount, int colt, int& minIndex);

int main() {
	srand((unsigned)time(NULL));

	int rowCount = 8;
	int colCount = rowCount;

	int Low = 4;
	int High = 51;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];

	CreateRows(a, colCount, Low, High, 0);
	PrintRows(a, colCount, 0);
	cout << endl;
	Sort(a, rowCount, 0);
	PrintRows(a, colCount, 0);


	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;

	return 0;
}

void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo)
{
	a[rowNo][colNo] = Low + rand() % (High - Low + 1);
	if (colNo < N - 1)
		CreateRow(a, rowNo, N, Low, High, colNo + 1);
}
void CreateRows(int** a, const int N, const int Low, const int High, int rowNo)
{
	CreateRow(a, rowNo, N, Low, High, 0);
	if (rowNo < N - 1)
		CreateRows(a, N, Low, High, rowNo + 1);
}
void PrintRow(int** a, const int rowNo, const int N, int colNo)
{
	cout << setw(4) << a[rowNo][colNo];
	if (colNo < N - 1)
		PrintRow(a, rowNo, N, colNo + 1);
	else
		cout << endl;
}
void PrintRows(int** a, const int N, int rowNo)
{
	PrintRow(a, rowNo, N, 0);
	if (rowNo < N - 1)
		PrintRows(a, N, rowNo + 1);
	else
		cout << endl;
}

void SortF(int** a, int rowCount, int colt, int& minIndex) {
	if (colt >= rowCount) return; 

	if (a[colt][colt] < a[minIndex][minIndex]) {
		minIndex = colt;
	}

	SortF(a, rowCount, colt + 1, minIndex);
}

void Sort(int** a, int rowCount, int col) {
	if (col >= rowCount - 1) return; 

	int minIndex = col;
	SortF(a, rowCount, col, minIndex);

	if (minIndex != col) {

		int temp = a[col][col];
		a[col][col] = a[minIndex][minIndex];
		a[minIndex][minIndex] = temp;
	}

	Sort(a, rowCount, col + 1);
}

