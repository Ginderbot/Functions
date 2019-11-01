#include<iostream>
#include<ctime>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	const int n = 10;
	int Arr[n];
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		cout << (Arr[i] = rand() % 10) << "\t";
	}
	cout << endl;

	//Вычислим количество чётных и нечётных значений в исходном массиве...
	int n_even = 0;// количество чётных елементов
	int n_odd = 0;// количество нечётных елементов
	for (int i = 0; i < n; i++)
	{
		if (Arr[i] % 2 == 0)
		{
			n_even++;
		}
		else
		{
			n_odd++;
		}
	}
	cout << "Количество чётных елементов: " << n_even << endl;
	cout << "Количество не чётных елементов: " << n_odd << endl;

	//Выделяем память для чётных и нечётных значений
	int*even_values = new int[n_even];
	int*odd_values = new int[n_odd];
	for (int i = 0, j = 0, k = 0; i < n; i++)
	{
		if (Arr[i] % 2 == 0)
		{
			even_values[j++] = Arr[i];
		}
		else
		{
			odd_values[k++] = Arr[i];
		}
	}
	for (int i = 0; i < n_even; i++)
	{
		cout << even_values[i] << "\t";
	}
	cout << endl;
	for (int i = 0; i < n_odd; i++)
	{
		cout << odd_values[i] << "\t";
	}
	cout << endl;
}
