#include<iostream>
using namespace std;

void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	int n;//размер массива
	cout << "¬ведите размер массива: "; cin >> n;
	int *arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		cout << (arr[i] = rand() % 100) << "\t";
	}
	cout << endl;

	// добавление элемента в конец массива
	int value;
	cout << "¬ведите добавл€емое значение: "; cin >> value;
	// 1)создаЄм буферный массив, размером на 1 элемент больше 
	int*buffer = new int[n + 1]{};
	// 2)копируем содержимое исходного массива в буферный 
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	// 3) ”дал€ем исходный масив из пам€ти
	delete[]arr;
	// 4) в указатель исходного массива записываем адрес нового массива
	arr = buffer;
	arr[n] = value;
		n++;
	Print(arr, n);


	delete[] arr;
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}