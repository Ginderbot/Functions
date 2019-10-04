#include <iostream>
using namespace std;

//#define Factorial

#define POWER
int factorial(int n)
{
	if (n == 0)return 1;
	return n * factorial(n - 1);
	/*int f = n * factorial(n - 1);
	return f;*/
}

double power(double a, int n)
{
	return n == 0 ? 1 : n > 0 ? a * power(a, n - 1) : 1 / a * power(a, n + 1);
	/*if (n == 0)return 1;
	if (n > 0)return a * power(a, n - 1);
	else return 1 / a*power(a, n + 1);*/
}
int fibonacci(int a, int b, int c)
{
	a+b=c
	if ()
	{

	}
}

void main()
{
	setlocale(LC_ALL, "");
#ifdef FACTORIAL
	int n;
	cout << "¬ведите число, дл€ вычислени€ факториала: "; cin >> n;
	cout << n << "!=" << factorial(n) << endl;
#endif // FACTORIAL
	int a;
	double n;
	cout << "¬ведите основание степени"; cin >> a;
	cout << "¬ведите степень"; cin >> n;
	cout << a << "^" << n << "=" << power(a, n)<<endl;
	cout << fibonacci(a);
}

