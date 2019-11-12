#include<iostream>
using std::cin;
using std::cout;
using std::endl;
//#define DINAMIC_MEMORY_1
#define DINAMIC_MEMORY_2
void FillRand(int**arr, const int n, const int m);
void Print(int arr[], const int n);
void Print(int**arr, const int n, const int m);
int* push_back(int arr[], int &n, int value);
int* push_front(int arr[], int &n, int value);
int **push_row_back(int **arr, int &m, const int n);
int **push_row_front(int **arr, int &m, const int n);
int **pop_row_back(int **arr, int &m, const int n);
int **pop_row_front(int **arr, int &m, const int n);
int **insert_row(int **arr, int &m, const int n, int index);
int **erase_row(int **arr, int &m, const int n, int index);
int* insert(int arr[], int &n, int value, int index);
int* pop_front(int arr[], int &n);
int* pop_back(int arr[], int &n);
int* erase(int arr[], int &n, int index);
void main()
{
	setlocale(LC_ALL, "");
#ifdef DINAMIC_MEMORY_1
	int n;//размер массива
	cout << "¬ведите размер массива: "; cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << (arr[i] = rand() % 100) << "\t";
	}
	cout << endl;
	int value, chouse;
	/*cout << "1. ƒобавить значение в начале массива " << endl << "2. ƒобавить
	значение в конце массива " << "3. ƒобавить значение в середину массива" << endl;
	cin >> chouse;*/
	//cout << "¬ведите добавл¤емое значение: "; cin >> value;
	//if (chouse == 1)
	//{
	// arr = push_front(arr, n, value);
	//}
	//else if (chouse == 2)
	//{
	// arr = push_back(arr, n, value);
	//}
	//else if (chouse == 3)
	//{
	int index;
	cout << "¬ведите количество отступа: "; cin >> index;
	// cout << endl;
	// arr = insert(arr, n, value, index);
	//}
	//else
	//{
	// cout << "Ќедопустимый выбор" << endl;
	//}
	arr = pop_front(arr, n);
	Print(arr, n);
	arr = pop_back(arr, n);
	Print(arr, n);
	arr = erase(arr, n, index);
	Print(arr, n);
	delete[] arr;
#endif // DINAMIC_MEMORY_1
#ifdef DINAMIC_MEMORY_2
	int m;//количество строк
	int n;// оличество елементов в строке
	cout << "¬ведите количество строк: "; cin >> m;
	cout << "¬ведите количество улументов строки: "; cin >> n;
	// обь¤вление динамического массива
	int **arr = new int*[m];
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n] {};
	}
	cout << "memory allocated" << endl;
	cout << "Filling array" << endl;
	///////////////////////////////////////////////////////
	// использование двумерного динамического массива
	FillRand(arr, m, n);
	Print(arr, m, n);
	arr = push_row_back(arr, m, n);
	Print(arr, m, n);
	arr = push_row_front(arr, m, n);
	Print(arr, m, n);
	arr = pop_row_back(arr, m, n);
	Print(arr, m, n);
	arr = pop_row_front(arr, m, n);
	Print(arr, m, n);
	cout << "В какую строку Вы хотите вставить новую? "; int index;
	cin >> index; cout << endl;
	arr=insert_row(arr, m, n, index);
	Print(arr, m, n);
	cout << "Row addet" << endl;
	cout << "Какую строку Вы хотите удалить? ";
	cin >> index; cout << endl;
	erase_row(arr, m, n, index);
	Print(arr, m, n);
	//////////////////////////////////////////////////////
	// удаление двумерного динамического массива
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
#endif // DINAMIC_MEMORY_2
}
void FillRand(int**arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void Print(int**arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
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
	for (int i = 0; i < n + 1; i++)	buffer[i] = arr[i - 1];
	delete[]arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}
int **push_row_back(int **arr, int &m, const int n)
{
	/*int** buf = new int*[m + 1]{};
	for (int i = 0; i < m; i++)
	{
	buf[i] = new int[n] {};
	}
	for (int i = 0; i < m; i++)
	{
	for (int j = 0; j < n; j++)
	{
	buf[i][j] = arr[i][j];
	}
	}
	for (int i = 0; i < m; i++)
	{
	delete[] arr[i];
	}
	delete[] arr;
	arr = buf;
	arr[m] = new int [n] {};
	m++;
	return arr;*/
	// создаем буферный массив
	int** buffer = new int*[m + 1];
	// копируем
	for (int i = 0; i < m; i++) buffer[i] = arr[i];
	delete[]arr;
	arr = buffer;
	arr[m] = new int[n] {};
	m++;
	return arr;
}
int **push_row_front(int **arr, int &m, const int n)
{
	int** buffer = new int*[m + 1];
	for (int i = 0; i < m; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[0] = new int [n] {};
	m++;
	return arr;
}
int **pop_row_back(int **arr, int &m, const int n)
{
	int** buffer = new int*[m + 1];
	for (int i = 0; i < m; i++) buffer[i] = arr[i];
	delete[]arr;
	arr = buffer;
	m--;
	return arr;
}
int **pop_row_front(int **arr, int &m, const int n)
{
	int** buffer = new int*[m - 1];
	for (int i = 0; i < m; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	arr = buffer;
	m--;
	return arr;
}
int **insert_row(int **arr, int &m, const int n, int index)
{
	if (index > m)return arr;
	int**buffer = new int*[m + 1]{};
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	for (int i = index; i < m; i++)
	{
		buffer[i+1] = arr[i];
	}
	delete[]arr;
	arr = buffer;
	arr[index] = new int [n] {};
	m++;
	return arr;
}
int **erase_row(int **arr, int &m, const int n, int index)
{
	if (index > m)return arr;
	int**buffer = new int*[m - 1];
	for (int i = 0; i < m-1; i++)
	{
		if (i<index)
		{
			buffer[i] = arr[i];
		}
		else
		{
			buffer[i] = arr[i + 1];
		}
	}
	delete[]arr;
	arr = buffer;
	m--;
	return arr;
}
int* insert(int arr[], int &n, int value, int index)
{
	if (index > n)return arr;
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
	if (index > n)return arr;
	int*buffer = new int[n - 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index - 1; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}arr = buffer; n--; return arr;
}