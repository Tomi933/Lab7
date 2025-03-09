#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
void Sort(int** a, const int rowCount);

int main() {
	srand((unsigned)time(NULL));

	int rowCount = 8;
	int colCount = rowCount;

	int Low = 4;
	int High = 51;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];

	Create(a, rowCount, colCount, Low, High);
	Print(a, rowCount, colCount);
	cout << endl;
	Sort(a, rowCount);
	Print(a, rowCount, colCount);


	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;

	return 0;
}

void Print(int** a, const int rowCount, const int colCount) {
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < colCount; j++)
			cout << setw(5) << a[i][j];
		cout << endl;
	}
}
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High) {
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Sort(int** a, const int rowCount) {
	
	for (int i = 0; i < rowCount - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < rowCount; j++) {
			if (a[j][j] > a[minIndex][minIndex]) {
				minIndex = j;
			}
		}
		
		if (minIndex != i) {
			int temp = a[i][i];
			a[i][i] = a[minIndex][minIndex];
			a[minIndex][minIndex] = temp;
		}
	}
}
