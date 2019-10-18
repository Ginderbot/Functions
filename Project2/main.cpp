#include <iostream>
using namespace std;

#define POINTER_BASICS
#define DECLARATION_OF_POINTER

int main()
{
	setlocale(LC_ALL, "Rus");
#ifdef POINTER_BASICS



	int a = 2;
	int *pa = &a;
	cout << a << endl;
	cout << &a << endl;
	cout << pa << endl;
	cout << *pa << endl << endl;
	int *pb;
	int b = 3;
	pb = &b;
	cout << pb << endl << *pb << endl<<endl;
	//int - тип данных
	//int* - указатель на int

#endif // POINTER_BASICS

#ifdef DECLARATION_OF_POINTER
	const int n = 5;
	short Arr[n] = { 3,5,8,13,21 };
	cout << *Arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(Arr +100 + i) << "\t";
	}
	cout << endl;
#endif // DECLARATION_OF_POINTER
}