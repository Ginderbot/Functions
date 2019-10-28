#include <iostream>
using namespace std;

//#define BY_POINTER
#define BY_REFERENSE

#ifdef BY_POINTER
void Exchange(int* a, int* b);
template<typename T>
void Xor(T*a, T*b);
#endif // BY_POINTER

#ifdef BY_REFERENSE
template<typename T>
void Xor(int &a, int&b);
#endif // BY_REFERENSE


void main()
{
	int a = 2.5, b = 3.14;
	cout << a << "\t" << b << endl;
#ifdef BY_POINTER
	//Exchange(&a, &b);
	//	Xor(&a, &b);
	cout << a << "\t" << b << endl;
#endif // BY_POINTER

	Xor<int>(a, b);
	cout << a << "\t" << b << endl;
}
#ifdef BY_POINTER


void Exchange(int* a, int* b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
#endif // BY_POINTER
template<typename T>
void Xor(int&a, int&b)
{
	a ^= b;
	b ^= a;
	a ^= b;
}