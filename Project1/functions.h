#pragma once
#include <iostream>
using namespace std;

#define DELIMETER "\n______________________________________________________________________________________\n"

const int ROWS = 4; // количество строк
const int COLS = 5; // количество елементов

void FillRand(int arr[], const int n);
void FillRand(double arr[], const int n);
void FillRand(float arr[], const int n);
void FillRand(char arr[], const int n);
void FillRand(int arr[ROWS][COLS], const int ROWS, const int COLS);

void Print(int arr[], const int n);
void Print(double arr[], const int n);
void Print(float arr[], const int n);
void Print(char arr[], const int n);
void Print(int arr[ROWS][COLS], const int ROWS, const int COLS);

void Sort(int arr[], const int n);
void Sort(int arr[ROWS][COLS], const int ROWS, const int COLS);
int Sum(int arr[], const int n);
int Sum(int arr[ROWS][COLS], const int ROWS, const int COLS);
double Avg(int arr[], const int n);
double Avg(int arr[ROWS][COLS], const int ROWS, const int COLS);

int minValueIn(int arr[], const int n);
int minValueIn(int arr[ROWS][COLS], const int ROWS, const int COLS);
int maxValueIn(int arr[], const int n);
int maxValueIn(int arr[ROWS][COLS], const int ROWS, const int COLS);

