#include<iostream>
using namespace std;

void Print(int arr[], const int n);
int* push_back(int arr[], int &n, int value);
int* push_front(int arr[], int &n, int value);
int* insert(int arr[], int &n, int value, int index);
int* pop_front(int arr[], int &n);
int* pop_back(int arr[], int &n);
int*erase(int arr[], int &n, int index);

void main()
{
	setlocale(LC_ALL, "");
	int n;//размер массива
	cout << "Введите размер массива: "; cin >> n;
	int *arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		cout << (arr[i] = rand() % 100) << "\t";
	}
	cout << endl;

	int value, chouse;
	/*cout << "1. Добавить значение в начале массива " << endl << "2. Добавить значение в конце массива " << "3. Добавить значение в середину массива" << endl;
	cin >> chouse;*/
	//cout << "Введите добавляемое значение: "; cin >> value;
	//if (chouse == 1)
	//{
	//	arr = push_front(arr, n, value);
	//}
	//else if (chouse == 2)
	//{
	//	arr = push_back(arr, n, value);
	//}
	//else if (chouse == 3)
	//{
		int index;
	cout << "Введите количество отступа: "; cin >> index;
	//	cout << endl;
	//	arr = insert(arr, n, value, index);
	//}
	//else
	//{
	//	cout << "Недопустимый выбор" << endl;
	//}
	arr = pop_front(arr, n);
	Print(arr, n);
	arr = pop_back(arr, n);
	Print(arr, n);
	arr = erase(arr, n, index);
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

int* push_back(int arr[], int &n, int value)
{
	int*buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[]arr;
	arr = buffer;
	arr[n] = value;
	n++;
	return arr;
}

int* push_front(int arr[], int &n, int value)
{
	int*buffer = new int[n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		buffer[i] = arr[i - 1];
	}
	delete[]arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}

int* insert(int arr[], int &n, int value, int index)
{
	int*buffer = new int[n + 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	arr = buffer;
	arr[index] = value;
	n++;
	return arr;
}

int* pop_front(int arr[], int &n)
{
	int*buffer = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[]arr;
	arr = buffer;
	n--;
	return arr;
}

int* pop_back(int arr[], int &n)
{
	int*buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[]arr;
	return buffer;
}

int*erase(int arr[], int &n, int index)
{
	int*buffer = new int[n - 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i] = arr[i+1];
	}
	arr = buffer;
	n--;
	return arr;
}

