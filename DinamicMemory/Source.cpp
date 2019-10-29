#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	int n;//размер массива
	cout << "¬ведите размер массива: "; cin >> n;
	double *Arr = new double[n];
	for (int i = 0; i < n; i++)
	{
		*(Arr + i) = rand() % 100;
	}
	for (int i = 0; i < n; i++)
	{
		cout << Arr[i] << "\t";
	}
	cout << endl;

	delete[] Arr;
}