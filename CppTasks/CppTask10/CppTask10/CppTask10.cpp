#include <iostream>
using namespace std;


int* AllocateMemory(int& size)
{
	int* array = new int[size];
	return array;
}

int*& InitArray(int*& array, int& size)
{
	int min = 0, max = 100;						// Task 3 də azaldın.

	for (int i = 0; i < size; i++)
	{
		array[i] = min + rand() % (max - min + 1);
	}

	return array;
}

void PrintArray(int*& array, int& size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << "  ";
	}

	cout << endl;
}

void DeleteArray(int*& array)
{
	delete[] array;
}



// Task 1 (Duplicate) 

int& CheckUpEven(int*& numbers, const int& size)
{
	int countEven = 0;

	for (int i = 0; i < size; i++)
	{
		if (numbers[i] != 0 && numbers[i] % 2 == 0)
		{
			countEven++;
		}
	}

	return countEven;
}

int*& DuplicateArray(int*& numbers, int& size)
{
	auto countEven = CheckUpEven(numbers, size);
	int* numbers2 = new int[size + countEven];
	int order = 0;

	for (int i = 0; i < size; i++)
	{
		if (numbers[i] % 2 == 0)
		{
			numbers2[i + order] = numbers[i];
			numbers2[i + order + 1] = numbers[i];
			order++;
		}
		else
		{
			numbers2[i + order] = numbers[i];
		}
	}

	size += order;

	DeleteArray(numbers);

	return numbers2;
}



// Task 2 (The Sum of The Elements)

int*& SumElements(int*& numbers, int& size)
{

	int* numbers2 = new int[size + size / 2] {};
	int order = 0;

	for (int i = 2; i < size * 1.5; i += 3)
	{
		for (int k = i - 2 - order; k < i - order; k++)
		{
			numbers2[i] += numbers[k];
			numbers2[k + order] = numbers[k];
		}
		order++;
	}

	size *= 1.5;

	DeleteArray(numbers);

	return numbers2;
}



// Task 3 (The Count of The Zero)

int*& ZeroCounter(int*& numbers, int& size)
{
	int sum = 0;

	for (int i = 0; i < size; i++)
	{
		sum += numbers[i];
	}

	int* numbers2 = new int[size + sum] {};
	int order = 0;

	for (int i = 0; i < size; i = i + 1)
	{
		numbers2[i + order] = numbers[i];
		order += numbers[i];
	}

	size += sum;

	DeleteArray(numbers);

	return numbers2;
}




void main()
{

	srand(time(NULL));


#pragma region Task 1 (Duplicate) 

	// 1. Massivdeki cut elementleri duplicate eden funksiya yazin.

	/*
	int size = 9;

	int* array = AllocateMemory(size);

	InitArray(array, size);

	PrintArray(array, size);

	array = DuplicateArray(array, size);

	PrintArray(array, size);

	DeleteArray(array);
	*/

#pragma endregion



#pragma region Task 2 (The Sum of The Elemenets)

	// 2. Elə funksiya yazın ki, massivdeki her 2 elementden bir elementlerin cemi sagina yazilsin.

	/*
	int size = 8;

	int* array = AllocateMemory(size);

	InitArray(array, size);

	PrintArray(array, size);

	array = SumElements(array, size);

	PrintArray(array, size);

	DeleteArray(array);
	*/

#pragma endregion



#pragma region Task 3 (The Count of The Zero)

	// 3.Meselen    2 4 1 5 3
	// 2 0 0 4 0 0 0 0 1 0 5 0 0 0 0 0 3 0 0 0

	/*
	int size = 5;

	int* array = new int [size] {};

	InitArray(array, size);

	PrintArray(array, size);
																// InitArray-in min və max elementini dəyişin.
	auto array2 = ZeroCounter(array, size);

	PrintArray(array2, size);

	DeleteArray(array2);
	*/

#pragma endregion


}