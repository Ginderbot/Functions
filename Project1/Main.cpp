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
	cout << "C���� ���������: " << Sum(arr, n) << endl;
	cout << "C������ ��������: " << Avg(arr, n) << endl;
	cout << "����������� ��������: " << minValueIn(arr, n) << endl;
	cout << "������������ ��������: " << maxValueIn(arr, n) << endl;

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


	cout << "C���� ���������: " << Sum(irr, ROWS, COLS) << endl;
	cout << "C������ ��������: " << Avg(irr, ROWS, COLS) << endl;
	cout << "����������� ��������: " << minValueIn(irr, ROWS, COLS) << endl;
	cout << "������������ ��������: " << maxValueIn(irr, ROWS, COLS) << endl;
}

