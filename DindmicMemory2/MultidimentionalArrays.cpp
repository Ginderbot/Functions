#include"Functions.h"

template<typename T>
T **push_row_back(T **arr, int &m, const int n)
{
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
void insert_col(T** arr, const int m, int& n, int index)
{
	for (int i = 0; i < m; i++)
	{
		T* buf = new T[n + 1]{};
		for (int j = 0; j < index; j++)
		{
			buf[j] = arr[i][j];
		}
		for (int j = index; j < n + 1; j++)
		{
			buf[j + 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buf;
	}
	n++;
}
template<typename T>
void erase_col(T** arr, const int m, int& n, int index)
{
	for (int i = 0; i < m; i++)
	{
		T* buf = new T[n - 1]{};
		for (int j = 0; j < index; j++)
		{
			buf[j] = arr[i][j];
		}
		for (int j = index; j < n; j++)
		{
			buf[j] = arr[i][j + 1];
		}
		delete[] arr[i];
		arr[i] = buf;
	}
	n--;
}

