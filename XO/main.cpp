#include <iostream>
#include <conio.h>
using namespace std;

#define HORIZ_OFFSET "\t\t\t\t\t\t\t"
void PrintField(char Field[], const int n, char player);
void Move(char Field[], const int n, char player);
void Check(char Field[], const int n, char player);
void New_game(char Field[], const int n, char player);

int main()
{
	const char player = 'X'; // Первый игрок ходит X
	setlocale(LC_ALL, "Rus");
	const int SIZE = 9 + 1;
	char Field[SIZE] = {}; // Игровое поле
	PrintField(Field, SIZE, player);
	cout << "Ещё разок? (y||Y)(n||N)" << endl;
	New_game(Field, SIZE, player);
}

void PrintField(char Field[], const int n, char player)
{
	system("CLS");
	cout << "\n\n\n\n\n\n\n";
	for (int i = 6; i >= 0; i -= 3)
	{
		cout << HORIZ_OFFSET << " ";
		for (int j = 0; j < 3; j++)
		{
			cout << Field[i + j];
			if (j != 2)cout << " | ";
		}
		cout << endl;
		cout << HORIZ_OFFSET;
		if (i != 0)cout << "--- --- ---" << endl;
	}
	Check(Field, n, player);
}

void Move(char Field[], const int n, char player)
{
	char key;
	bool busy;
	bool miss;
	do
	{
		do
		{
			miss = false;
			key = _getch();
			if (!(key >= '1'&& key <= '9') && key != 27)miss = true;
			if (miss == true) cout << "Вы не попали в поле" << endl;
		} while (miss);
		busy = false;
		if (key == 27)return;
		if (Field[key - 49] != 0)busy = true;
		if (busy == true)
		{
			cout << "Ошибак" << endl;
		}
		else
		{
			Field[key - 49] = player;
		}
	} while (busy);
	player == 'O' ? player = 'X' : player = 'O';
	PrintField(Field, n, player);
}
void Check(char Field[], const int n, char player)
{

	bool game_over = false;

	if (Field[0] == Field[4] && Field[4] == Field[8] && Field[8] != 0)game_over = true;
	else if (Field[2] == Field[4] && Field[4] == Field[6] && Field[6] != 0)game_over = true;

	else if (Field[0] == Field[1] && Field[1] == Field[2] && Field[2] != 0)game_over = true;
	else if (Field[3] == Field[4] && Field[4] == Field[5] && Field[5] != 0)game_over = true;
	else if (Field[6] == Field[7] && Field[7] == Field[8] && Field[8] != 0)game_over = true;

	else if (Field[0] == Field[3] && Field[3] == Field[6] && Field[6] != 0)game_over = true;
	else if (Field[1] == Field[4] && Field[4] == Field[7] && Field[7] != 0)game_over = true;
	else if (Field[2] == Field[5] && Field[5] == Field[8] && Field[8] != 0)game_over = true;

	if (game_over)
	{
		player == 'O' ? player = 'X' : player = 'O';
		cout << "Выиграл игрок " << player << endl;
		return;
	}
	else if (Field[0] != 0 && Field[1] != 0 && Field[2] != 0 && Field[3] != 0 && Field[4] != 0 && Field[5] != 0 && Field[6] != 0 && Field[7] != 0 && Field[8] != 0)
	{
		cout << "Ничья" << endl;
		return;
	}
	if (player == 'X')Move(Field, n, player);
	else Move(Field, n, player);
}
void New_game(char Field[], const int n, char player)
{
	char key;
	bool qwestionth = false;
	do
	{
		key = _getch();
		if (key == 173 || key == 141 || key == 121 || key == 89 || key == 13)
		{
			main();
		}
		else if (key == 110 || key == 78 || key == 226 || key == 146 || key == 27)
		{
			return;
		}
		else
		{
			cout << "Недопустимый выбор!" << endl;
		}
	} while (!qwestionth);
}

//y - 121
//Y - 89
//н - 173
//Н - 141

//n - 110
//N - 78
//т - 226
//Т - 146