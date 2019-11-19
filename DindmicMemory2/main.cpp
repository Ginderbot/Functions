#include<iostream>
using std::cin;
using std::cout;
using std::endl;



//#define DINAMIC_MEMORY_1
#define DINAMIC_MEMORY_2
int** allocate(const int m, const int n);
void clear(int** arr, const int n);

void FillRand(int**arr, const int n, const int m);
void Print(int arr[], const int n);
void Print(int**arr, const int n, const int m);
int* push_back(int arr[], int &n, int value);
int* push_front(int arr[], int &n, int value);
void push_row_back(int **& arr, int &m, const int n);
void push_col_back(int **arr, int const m, int &n);
void push_row_front(int **& arr, int &m, const int n);
void push_col_front(int **arr, int const m, int &n);
void pop_row_back(int **& arr, int &m, const int n);
void pop_col_back(int **arr, int const m, int &n);
void pop_row_front(int **& arr, int &m, const int n);
void pop_col_front(int **arr, int const m, int &n);
void insert_row(int **& arr, int &m, const int n, int index);
void erase_row(int **& arr, int &m, const int n, int index);
int* insert(int arr[], int &n, int value, int index);
int* pop_front(int arr[], int &n);
int* pop_back(int arr[], int &n);
int* erase(int arr[], int &n, int index);
void insert_col(int** arr, const int m, int& n, int index);
void erase_col(int** arr, const int m, int& n, int index);

void main()
{
	setlocale(LC_ALL, "");
#ifdef DINAMIC_MEMORY_1
	int n;//размер массива
	cout << "Введите размер массива: "; cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << (arr[i] = rand() % 100) << "\t";
	}
	cout << endl;
	int value, chouse;
	
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);
	arr = push_back(arr, n, value);
	Print(arr, n);
	int index;
	cout << "Введите количество отступа: "; cin >> index;
	cout << endl;
	arr = insert(arr, n, value, index);
	Print(arr, n);
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
	int n;//Количество елементов в строке
	cout << "Введите количество строк: "; cin >> m;
	cout << "Введите количество улументов строки: "; cin >> n;
	// обьявление динамического массива
	int **arr = allocate(m, n);
	///////////////////////////////////////////////////////
	// использование двумерного динамического массива
	FillRand(arr, m, n);
	Print(arr, m, n);
	
	push_row_back(arr, m, n);
	Print(arr, m, n);
	push_row_front(arr, m, n);
	Print(arr, m, n);
	pop_row_back(arr, m, n);
	Print(arr, m, n);
	pop_row_front(arr, m, n);
	Print(arr, m, n);
	cout << "В какую строку Вы хотите вставить новую? "; int index;
	cin >> index; cout << endl;
	insert_row(arr, m, n, index);
	Print(arr, m, n);
	cout << "Какую строку Вы хотите удалить? ";
	cin >> index; cout << endl;
	erase_row(arr, m, n, index);
	Print(arr, m, n);
	push_col_back(arr, m, n);
	Print(arr, m, n);
	push_col_front(arr, m, n);
	Print(arr, m, n);
	pop_col_back(arr, m, n);
	Print(arr, m, n);
	pop_col_front(arr, m, n);
	Print(arr, m, n);
	cout << "В какую строку Вы хотите вставить новую? ";
	cin >> index; cout << endl;
	insert_col(arr, m, n, index);
	Print(arr, m, n);
	cout << "Какую строку Вы хотите удалить? ";
	cin >> index; cout << endl;
	erase_col(arr, m, n, index);
	//////////////////////////////////////////////////////
	// удаление двумерного динамического массива
	clear(arr, m);
#endif // DINAMIC_MEMORY_2
}

int** allocate(const int m, const int n)
{
	int **arr = new int*[m];
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n] {};
	}
	return arr;
}

void clear(int** arr, const int m)
{
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
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
void push_row_back(int **& arr, int &m, const int n)
{
	// создаем буферный массив
	int** buffer = new int*[m + 1];
	// копируем
	for (int i = 0; i < m; i++) buffer[i] = arr[i];
	delete[]arr;
	arr = buffer;
	arr[m] = new int[n] {};
	m++;

}
void push_col_back(int **arr, int const m, int &n)
{
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[n + 1]{};
		for (int j = 0; j < n; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[]arr[i];
		arr[i] = buffer;
	}
	n++;
}
void push_row_front(int **& arr, int &m, const int n)
{
	int** buffer = new int*[m + 1];
	for (int i = 0; i < m; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[0] = new int [n] {};
	m++;
}
void push_col_front(int **arr, int const m, int &n)
{
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[n + 1]{};
		for (int j = 0; j < n; j++)
		{
			buffer[j + 1] = arr[i][j];
		}
		delete[]arr[i];
		arr[i] = buffer;
	}
	n++;
}
void pop_row_back(int **& arr, int &m, const int n)
{
	int** buffer = new int*[--m];
	for (int i = 0; i < m; i++) buffer[i] = arr[i];
	delete[]arr;
	arr = buffer;
}
void pop_col_back(int **arr, int const m, int &n)
{
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[n] {};
		for (int j = 0; j < n; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[]arr[i];
		arr[i] = buffer;
	}
	n--;
}
void pop_row_front(int **& arr, int &m, const int n)
{
	int** buffer = new int*[--m];
	for (int i = 0; i < m; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	arr = buffer;
}
void pop_col_front(int **arr, int const m, int &n)
{
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[n] {};
		for (int j = 0; j < n; j++)
		{
			buffer[j] = arr[i][j + 1];
		}
		delete[]arr[i];
		arr[i] = buffer;
	}
	n--;
}
void insert_row(int **& arr, int &m, const int n, int index)
{
	if (index > m)return;
	int**buffer = new int*[m + 1]{};
	for (int i = 0; i < m + 1; i++)
	{
		i < index ? buffer[i] = arr[i] : buffer[i + 1] = arr[i];
	}
	delete[]arr;
	arr = buffer;
	arr[index] = new int [n] {};
	m++;
}
void erase_row(int **& arr, int &m, const int n, int index)
{
	if (index > m)return;
	int**buffer = new int*[m - 1];
	for (int i = 0; i < m - 1; i++)
	{
		i < index ? buffer[i] = arr[i] : buffer[i] = arr[i + 1];
	}
	delete[]arr;
	arr = buffer;
	m--;
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
void insert_col(int** arr, const int m, int& n, int index)
{
	for (int i = 0; i < m; i++)
	{
		int* buf = new int[n + 1]{};
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

void erase_col(int** arr, const int m, int& n, int index)
{
	for (int i = 0; i < m; i++)
	{
		int* buf = new int[n - 1]{};
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

