#include"functions.h"

void main()
{
	setlocale(LC_ALL, "");
	const int n = 5;
	int arr[n];

	FillRand(arr, n);
	Print(arr, n);
	Sort(arr, n);
	Print(arr, n);
	cout << "Cумма елементов: " << Sum(arr, n) << endl;
	cout << "Cреднее значение: " << Avg(arr, n) << endl;
	cout << "Минимальное значение: " << minValueIn(arr, n) << endl;
	cout << "Максимальное значение: " << maxValueIn(arr, n) << endl;

	double brr[n];
	FillRand(brr, n);
	Print(brr, n);

	float crr[n];
	FillRand(crr, n);
	Print(crr, n);

	char drr[n];
	FillRand(drr, n);
	Print(drr, n);

	int irr[ROWS][COLS];
	FillRand(irr, ROWS, COLS);
	Print(irr, ROWS, COLS);
	Sort(irr, ROWS, COLS);
	cout << DELIMETER;
	Print(irr, ROWS, COLS);


	cout << "Cумма елементов: " << Sum(irr, ROWS, COLS) << endl;
	cout << "Cреднее значение: " << Avg(irr, ROWS, COLS) << endl;
	cout << "Минимальное значение: " << minValueIn(irr, ROWS, COLS) << endl;
	cout << "Максимальное значение: " << maxValueIn(irr, ROWS, COLS) << endl;
}

