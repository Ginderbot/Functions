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
	*a = *a + *b; 
	*b = *a - *b; 
	*a = *a - *b; 
}