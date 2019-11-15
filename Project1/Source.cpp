#include<iostream>
using std::cin;
using std::cout;
using std::endl;



//#define DINAMIC_MEMORY_1
#define DINAMIC_MEMORY_2

template<typename T>T ** allocate(const int m, const int n);
template<typename T>void clear(T** arr, const int n);
template<typename T>void FillRand(T**arr, const int n, const int m);

template<typename T>void Print(T arr[], const int n);
template<typename T>void Print(T**arr, const int n, const int m);

template<typename T>T* push_back(T arr[], int &n, T value);
template<typename T>T* push_front(T arr[], int &n, T value);
template<typename T>T* insert(T arr[], int &n, T value, int index);

template<typename T>T **push_row_back(T **arr, int &m, const int n);
template<typename T>T **push_row_front(T **arr, int &m, const int n);

template<typename T> void push_col_back(T **arr, int const m, int &n);
template<typename T>void push_col_front(T **arr, int const m, int &n);
template<typename T>T **pop_row_back(T **arr, int &m, const int n);
template<typename T>void pop_col_back(T **arr, int const m, int &n);
template<typename T>T **pop_row_front(T **arr, int &m, const int n);
template<typename T>void pop_col_front(T **arr, int const m, int &n);
template<typename T>T **insert_row(T **arr, int &m, const int n, int index);
template<typename T>T **erase_row(T **arr, int &m, const int n, int index);
template<typename T>T* pop_front(T arr[], int &n);
template<typename T>T* pop_back(int arr[], int &n);
template<typename T>T* erase(T arr[], int &n, int index);
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
	//cout << "¬ведите добавл€емое значение: "; cin >> value;
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
	// обь€вление динамического массива
	int **arr = allocate<int>(m, n);
	cout << "memory allocated" << endl;
	cout << "Filling array" << endl;
	///////////////////////////////////////////////////////
	// использование двумерного динамического массива
	FillRand(arr, m, n);
	Print(arr, m, n);
	/*
	arr = push_row_back(arr, m, n);
	Print(arr, m, n);
	arr = push_row_front(arr, m, n);
	Print(arr, m, n);
	arr = pop_row_back(arr, m, n);
	Print(arr, m, n);
	arr = pop_row_front(arr, m, n);
	Print(arr, m, n);
	cout << "¬ какую строку ¬ы хотите вставить новую? "; int index;
	cin >> index; cout << endl;
	arr = insert_row(arr, m, n, index);
	Print(arr, m, n);
	cout << "Row addet" << endl;
	cout << " акую строку ¬ы хотите удалить? ";
	cin >> index; cout << endl;
	arr = erase_row(arr, m, n, index);
	Print(arr, m, n);*/
	push_col_back(arr, m, n);
	Print(arr, m, n);
	push_col_front(arr, m, n);
	Print(arr, m, n);
	pop_col_back(arr, m, n);
	Print(arr, m, n);
	pop_col_front(arr, m, n);
	Print(arr, m, n);
	//////////////////////////////////////////////////////
	// удаление двумерного динамического массива
	clear(arr, m);
#endif // DINAMIC_MEMORY_2
}
template<typename T>
T** allocate(const int m, const int n)
{
	T **arr = new T*[m];
	for (int i = 0; i < m; i++)
	{
		arr[i] = new T[n]{};
	}
	return arr;
}
template<typename T>
void clear(T** arr, const int m)
{
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}
template<typename T>
void FillRand(T**arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 100;
			arr[i][j] /= 10;
		}
	}
}
template<typename T>
void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
template<typename T>
void Print(T**arr, const int m, const int n)
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
template<typename T>
T* push_back(T arr[], int &n, T value)
{
	T*buffer = new T[n + 1]{};
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
template<typename T>
T* push_front(T arr[], int &n, T value)
{
	T*buffer = new T[n + 1];
	for (int i = 0; i < n + 1; i++)	buffer[i] = arr[i - 1];
	delete[]arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}
template<typename T>
T **push_row_back(T **arr, int &m, const int n)
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
	T** buffer = new T*[m + 1];
	// копируем
	for (int i = 0; i < m; i++) buffer[i] = arr[i];
	delete[]arr;
	arr = buffer;
	arr[m] = new T[n]{};
	m++;
	return arr;
}
template<typename T>
void push_col_back(T **arr, int const m, int &n)
{
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n + 1]{};
		for (int j = 0; j < n; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[]arr[i];
		arr[i] = buffer;
	}
	n++;
}
template<typename T>
T **push_row_front(T **arr, int &m, const int n)
{
	T** buffer = new T*[m + 1];
	for (int i = 0; i < m; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[0] = new T[n]{};
	m++;
	return arr;
}
template<typename T>
void push_col_front(T **arr, int const m, int &n)
{
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n + 1]{};
		for (int j = 0; j < n; j++)
		{
			buffer[j + 1] = arr[i][j];
		}
		delete[]arr[i];
		arr[i] = buffer;
	}
	n++;
}
template<typename T>
T **pop_row_back(T **arr, int &m, const int n)
{
	T** buffer = new T*[--m];
	for (int i = 0; i < m; i++) buffer[i] = arr[i];
	delete[]arr;
	arr = buffer;
	return arr;
}
template<typename T>
void pop_col_back(T **arr, int const m, int &n)
{
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n]{};
		for (int j = 0; j < n; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[]arr[i];
		arr[i] = buffer;
	}
	n--;
}
template<typename T>
T **pop_row_front(T **arr, int &m, const int n)
{
	T** buffer = new T*[--m];
	for (int i = 0; i < m; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	arr = buffer;
	return arr;
}
template<typename T>
void pop_col_front(T **arr, int const m, int &n)
{
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n]{};
		for (int j = 0; j < n; j++)
		{
			buffer[j] = arr[i][j + 1];
		}
		delete[]arr[i];
		arr[i] = buffer;
	}
	n--;
}
template<typename T>
T **insert_row(T **arr, int &m, const int n, int index)
{
	if (index > m)return arr;
	T**buffer = new T*[m + 1]{};
	for (int i = 0; i < m + 1; i++)
	{
		i < index ? buffer[i] = arr[i] : buffer[i + 1] = arr[i];
	}
	delete[]arr;
	arr = buffer;
	arr[index] = new T[n]{};
	m++;
	return arr;
}
template<typename T>
T **erase_row(T **arr, int &m, const int n, int index)
{
	if (index > m)return arr;
	T**buffer = new T*[m - 1];
	for (int i = 0; i < m - 1; i++)
	{
		i < index ? buffer[i] = arr[i] : buffer[i] = arr[i + 1];
	}
	delete[]arr;
	arr = buffer;
	m--;
	return arr;
}
template<typename T>
T* insert(T arr[], int &n, T value, int index)
{
	if (index > n)return arr;
	T*buffer = new T[n + 1];
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
template<typename T>
T* pop_front(T arr[], int &n)
{
	T*buffer = new T[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[]arr;
	arr = buffer;
	n--;
	return arr;
}
template<typename T>
T* pop_back(T arr[], int &n)
{
	int*buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[]arr;
	return buffer;
}
template<typename T>
T*erase(T arr[], int &n, int index)
{
	if (index > n)return arr;
	T*buffer = new T[n - 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index - 1; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	arr = buffer;
	n--;
	return arr;
}