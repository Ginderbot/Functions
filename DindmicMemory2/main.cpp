#include"Functions.h"
#include"Memory.cpp"
#include"BaseFunctions.cpp"
#include"SimpleAreys.cpp"
#include"MultidimentionalArrays.cpp"
//#define DINAMIC_MEMORY_1
#define DINAMIC_MEMORY_2
#define ROWS
//#define COLS

typedef int DataType;
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
	int value;
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
	 cout << "Введите удаляемое значение: "; cin >> index;
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
	DataType **arr = allocate<DataType>(m, n);
	cout << "memory allocated" << endl;
	cout << "Filling array" << endl;
	///////////////////////////////////////////////////////
	// использование двумерного динамического массива
	FillRand(arr, m, n);
	Print(arr, m, n);
#ifdef ROWS
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
	arr = insert_row(arr, m, n, index);
	Print(arr, m, n);
	cout << "Row addet" << endl;
	cout << "Какую строку Вы хотите удалить? ";
	cin >> index; cout << endl;
	arr = erase_row(arr, m, n, index);
	Print(arr, m, n);
#endif // ROWS
#ifdef COLS
	push_col_back(arr, m, n);
	Print(arr, m, n);
	push_col_front(arr, m, n);
	Print(arr, m, n);
	pop_col_back(arr, m, n);
	Print(arr, m, n);
	pop_col_front(arr, m, n);
	Print(arr, m, n);
	/*cout << "В какую строку Вы хотите вставить новую? "; int index;
	cin >> index; cout << endl;
arr = insert_col (arr, m, n, index);
	Print(arr, m, n);
	cout << "Какую строку Вы хотите удалить? ";
	cin >> index; cout << endl;
arr = erase_col(arr, m, n, index);*/
	Print(arr, m, n);
#endif // COLS
	// удаление двумерного динамического массива
	clear(arr, m);
#endif // DINAMIC_MEMORY_2
}




