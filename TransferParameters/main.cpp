#include <iostream>
using namespace std;

void Exchange(int* a, int* b);


void main()
{
	int a = 2, b = 3;
	cout << a << "\t" << b << endl;
	Exchange(&a, &b);
	cout << a << "\t" << b << endl;
}
void Exchange(int* a, int* b)
{
	*a = *a + *b; // 2+3=5
	*b = *a - *b; // 5-3=2
	*a = *a - *b; // 5-2=3
}