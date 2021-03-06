	// md311.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <ctime>
using namespace std;
const int SIZE = 20;
bool Nunique(int a[], int b) 
{
	int count = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (a[i] == b) count++;
		if (count > 1) return false;
	}
	return true;
}
bool HasInArray(int a[], int b) {
	for (int i = 0; i < SIZE; i++)
	{
		if (a[i] == b) return true;
	}
	return false;
}
int main()
{
	srand(time(NULL));
	int array[SIZE], onumArray[SIZE], uniqArray[SIZE], nuniqArray[SIZE],uniqNum=0, nuniqNum=0;
	cout << "Array: ";
	for (int i = 0; i < SIZE; i++)
	{
		array[i] = rand() % 19 + 1;
		cout << array[i] << " ";
	}
	cout << "\nDigits: ";
	for (int i = 0; i < SIZE; i++)
	{
		if (array[i] < 10) cout << array[i] << " ";
		if (Nunique(array, array[i])) {
			if (HasInArray(uniqArray, array[i])) continue;
			uniqArray[uniqNum++] = array[i];
		}else{ 
			if (HasInArray(nuniqArray, array[i])) continue;
			nuniqArray[nuniqNum++] = array[i];
		};
	}
	cout << "\nUnique: ";
	for (int i = 0; i < uniqNum; i++) cout << uniqArray[i] << " ";
	cout << "\nNon-Unique: ";
	for (int i = 0; i < nuniqNum; i++) cout << nuniqArray[i] << " ";
	cout << "\nMissing: ";
	for (int i = 1; i < SIZE; i++)
	{
		if (!HasInArray(array, i)) cout << i << " ";
	}
	cout << endl;
	system("pause");
}
