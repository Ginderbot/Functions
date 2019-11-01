#include<iostream>
#include<ctime>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	const int n = 10;
	int Arr[n];
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		cout << (Arr[i] = rand() % 10) << "\t";
	}
	cout << endl;

	//�������� ���������� ������ � �������� �������� � �������� �������...
	int n_even = 0;// ���������� ������ ���������
	int n_odd = 0;// ���������� �������� ���������
	for (int i = 0; i < n; i++)
	{
		if (Arr[i] % 2 == 0)
		{
			n_even++;
		}
		else
		{
			n_odd++;
		}
	}
	cout << "���������� ������ ���������: " << n_even << endl;
	cout << "���������� �� ������ ���������: " << n_odd << endl;

	//�������� ������ ��� ������ � �������� ��������
	int*even_values = new int[n_even];
	int*odd_values = new int[n_odd];
	for (int i = 0, j = 0, k = 0; i < n; i++)
	{
		if (Arr[i] % 2 == 0)
		{
			even_values[j++] = Arr[i];
		}
		else
		{
			odd_values[k++] = Arr[i];
		}
	}
	for (int i = 0; i < n_even; i++)
	{
		cout << even_values[i] << "\t";
	}
	cout << endl;
	for (int i = 0; i < n_odd; i++)
	{
		cout << odd_values[i] << "\t";
	}
	cout << endl;
}
