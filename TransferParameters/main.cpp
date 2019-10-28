#include <iostream>
using namespace std;

void Exchange(int* a, int* b);
template<typename T>
void Xor(T*a, T*b);


void main()
{
	int a = 10, b = 6;
	cout << a << "\t" << b << endl;
	//Exchange(&a, &b);
	Xor(&a, &b);
	cout << a << "\t" << b << endl;
}
void Exchange(int* a, int* b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
template<typename T>
void Xor(T*a, T*b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}