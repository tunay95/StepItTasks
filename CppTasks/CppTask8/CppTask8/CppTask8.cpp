#include <iostream>
using namespace std;


void main() {

#pragma region Task 1

	// 1. Pointerdən istifadə edərək, İstiadəçinin daxil etdiyi rəqəmin
	// işarəsini tapan program yazın.

	/*
	float number;

	cout << "Enter The Number: ";
	cin >> number;
	float* ptrNum = &number;

	if (*ptrNum<0)
	{
		cout << *ptrNum << " is Negative.\n";
	}
	else if (*ptrNum=0)
	{
		cout << ptrNum << " is Zero.\n";
	}
	else {
		cout << ptrNum << " is Positive.\n";

	}
	*/

#pragma endregion



#pragma region Task 2

	// 2. Ancaq pointerdən istifadə edərək, primitiv kalkulyator yazın.

	/*
	int choice;
	float number1, number2;
	cout << "Enter Number 1: ";
	cin >> number1;
	cout << "Enter Number 2: ";
	cin >> number2;

	cout << endl;

	cout << "1) a + b \n2) a - b \n3) a * b \n4) a / b \n\nYour Choice: ";
	cin >> choice;

	int* ptrChoice = &choice;
	float* ptrNum1 = &number1;
	float* ptrNum2 = &number2;

	cout << endl<<"Result: ";

	if (*ptrChoice == 1)
	{
		cout << *ptrNum1 << " + " << *ptrNum2 << " = " << *ptrNum1 + *ptrNum2;
	}
	else if (*ptrChoice == 2)
	{
		cout << *ptrNum1 << " - " << *ptrNum2 << " = " << *ptrNum1 - *ptrNum2;
	}
	else if (*ptrChoice == 3)
	{
		cout << *ptrNum1 << " * " << *ptrNum2 << " = " << *ptrNum1 * *ptrNum2;
	}
	else if (*ptrChoice == 4)
	{
		cout << *ptrNum1 << " / " << *ptrNum2 << " = " << *ptrNum1 / *ptrNum2;
	}
	else {
		cout << "Enter The Correct Choice !!";
	}

	cout << endl;
	*/

#pragma endregion



#pragma region Task 3

	// 3. Tam ədədlərdən ibarət massivin elementlərini toplayan program	yazın.

	/*
	const int size = 5;
	int numbers[size]{ 1,2,3,4,5 };
	int sum = 0;

	int* ptrNums = numbers;
	int* ptrSum = &sum;

	cout << "Array:  ";

	for (int i = 0; i < size; i++)
	{
		cout << *(ptrNums + i) << "  ";
	}

	cout << endl;

	for (int i = 0; i < size; i++)
	{
		*ptrSum += *(ptrNums + i);
	}

	cout << "\nThe Sum of The Array Elements is " << *ptrSum << ".\n";
	*/

#pragma endregion



#pragma region Task 4

	// 4. İki pointerdən istifadə edərək, bir massivdəki elementləri 
	// digərinə kopyalayn program yazın.

	/*
	const int size = 5;
	int numbers1[size] = { 1,2,3,4,5 };
	int numbers2[size];

	int* ptrNums1 = numbers1;
	int* ptrNums2 = numbers2;

	for (int i = 0; i < size; i++)
	{
		*(ptrNums2+i) = *(ptrNums1+i);
	}

		cout << "Array 1:  ";

	for (int i = 0; i < size; i++)
	{
		cout  << *(ptrNums1 + i) << "  ";
	}

	cout << "\n\nArray 2:  ";

	for (int i = 0; i < size; i++)
	{
		cout  << *(ptrNums2 + i) << "  ";
	}
	*/

#pragma endregion



#pragma region Task 5

	// 5. Pointerlərdən istifadə edərək, ölçüsü 10 olan massivdə 
	// elementlərin sırasını tərsinə çevirən program yazın.

	/*
	const int size = 5;
	int numbers1[size] = { 1,2,3,4,5 };
	int numbers2[size];

	int* ptrNums1 = numbers1;
	int* ptrNums2 = numbers2;

	for (int i = 0; i < size; i++)
	{
		*(ptrNums2 + size - 1 - i) = *(ptrNums1 + i);
	}

	cout << "Array 1:  ";

	for (int i = 0; i < size; i++)
	{
		cout << *(ptrNums1 + i) << "  ";
	}

	cout << "\n\nArray 2:  ";

	for (int i = 0; i < size; i++)
	{
		cout << *(ptrNums2 + i) << "  ";
	}

	cout << endl;
	*/

#pragma endregion



#pragma region Task 6

	// 6. İki pointerdən elə istifadə edin ki, birinci massivdən ikinci massivə
	// ədədləri tərsinə kopyalayan program yazın.

	/*
	const int size = 5;
	int numbers1[size] = { 13,21,39,94,67 };
	int numbers2[size];;
	int a, b;

	int* ptrNums1 = numbers1;
	int* ptrNums2 = numbers2;
	int* ptrA = &a;
	int* ptrB = &b;

	for (int i = 0; i < size; i++)
	{
		*ptrA = *(ptrNums1 + i) / 10;
		*ptrB = *(ptrNums1 + i) % 10;
		*(ptrNums2 + i) = *ptrB * 10 + *ptrA;
	}

	cout << "Array 1:  ";

	for (int i = 0; i < size; i++)
	{
		cout << *(ptrNums1 + i) << "  ";
	}

	cout << "\n\nArray 2:  ";

	for (int i = 0; i < size; i++)
	{
		cout << *(ptrNums2 + i) << "  ";
	}

	cout << endl;
	*/

#pragma endregion



#pragma region Task 7

	// 7. Pointerlərdən istifadə edərək, massivin maximal və minimal
	// elementlərini tapan program yazın.

	/*
	const int size = 5;
	int numbers[size] = { 13,21,39,94,67 };
	int minEl = numbers[0], maxEl = numbers[0];

	int* ptrNums = numbers;
	int* ptrMinEl = &minEl;
	int* ptrMaxEl = &maxEl;

	cout << "Array:  ";

	for (int i = 0; i < size; i++)
	{
		cout << *(ptrNums + i) << "  ";
	}

	for (int i = 0; i < size; i++)
	{
		if (*ptrMinEl < *(ptrNums + i))
		{
			*ptrMinEl = *(ptrNums + i);
		}
	}

	for (int i = 0; i < size; i++)
	{
		if (*ptrMaxEl > *(ptrNums + i))
		{
			*ptrMaxEl = *(ptrNums + i);
		}
	}

	cout << "\n\nThe Maximum Element is " << *ptrMaxEl << ".\n";
	cout << "\nThe Minimum Element is " << *ptrMinEl << ".\n";
	*/

#pragma endregion



#pragma region Task 8

	// 8. Pointerlərdən istifadə edərək massivi dövrü sürüşdürən yazın.
	// (bu tapışırıq dövrlərdə iki dəfə yazmısınız, alqoritmini ordangötürə bilərsiniz)

	/*
	const int size = 5;
	int numbers1[size] = { 1,2,3,4,5 };
	int numbers2[size],index;
	
	cout << "Enter The Index: ";
	cin >> index;

	int* ptrNums1 = numbers1;
	int* ptrNums2 = numbers2;
	int* ptrIndex = &index;

	for (int i = 0; i < size; i++)
	{
		*(ptrNums2 + (*ptrIndex + i)%size) = *(ptrNums1 + i);
	}

	cout << "\nDefault Array:  ";

	for (int i = 0; i < size; i++)
	{
		cout << *(ptrNums1 + i) << "  ";
	}

	cout << "\n\nSlided Array:  ";

	for (int i = 0; i < size; i++)
	{
		cout << *(ptrNums2 + i) << "  ";
	}
	
	cout << endl;
	*/

#pragma endregion


}


