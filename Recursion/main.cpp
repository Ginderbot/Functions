#include <iostream>
using namespace std;

//#define Factorial

#define POWER
#define fibonachi_1
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
void fibonacci_1(int n, int a = 0, int b = 1);
void fibonacci_2(int n,int num=0, int a = 0, int b = 1);


void main()
{
	setlocale(LC_ALL, "");
#ifdef FACTORIAL
	int n;
	cout << "¬ведите число, дл€ вычислени€ факториала: "; cin >> n;
	cout << n << "!=" << factorial(n) << endl;
#endif // FACTORIAL
	/*int a;
	double n;
	cout << "¬ведите основание степени"; cin >> a;
	cout << "¬ведите степень"; cin >> n;
	cout << a << "^" << n << "=" << power(a, n)<<endl;*/
#ifdef fibonachi_1
	int n;
	cout << "¬ведите до какого числа отобразить р€д ‘ибоначи: "; cin >> n;
	fibonacci_1(n);

	cout << "¬ведите количество р€да ‘ибоначи: "; cin >> n;
	fibonacci_2(n);
#endif // fibonachi_1

}


void fibonacci_1(int n, int a, int b)
{
	if (a > n)
	{
		cout << endl;
		return;
	}
	cout << a << "\t";
	fibonacci_1(n, b, a + b);
}
void fibonacci_2(int n,int num, int a, int b)
{
	if (num >= n)
	{
		cout << endl;
		return;
	}
	cout << a << "\t";
	num++;
	fibonacci_2(n,num, b, a + b);
}


