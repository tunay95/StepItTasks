#include<iostream>
#include<iomanip>
using namespace std;


void InitArray(int**& numbers, int row, int col)
{
	int min = 0, max = 9;

	for (int i = 0; i < row; i++)
	{
		for (int k = 0; k < col; k++)
		{
			numbers[i][k] = min + rand() % (max - min + 1);
		}
	}
}

void PrintArray(int**& numbers, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int k = 0; k < col; k++)
		{
			cout << setw(4) << numbers[i][k] << "  ";
		}
		cout << "\n\n";
	}
}

void DeleteArray(int**& array)
{
	delete[] array;
}



// Task 1

int**& MultOfRows(int**& numbers, int& row, int& col)
{

	for (int i = 0; i < row / 2; i++)
	{
		for (int k = 0; k < col; k++)
		{
			numbers[i][k] *= numbers[row - i - 1][k];
		}
	}

	row /= 2;

	return numbers;
}



// Task 2

int**& SumOfColumns(int**& numbers, int& row, int& col)
{
	for (int i = 0; i < row; i++)
	{
		for (int k = 0; k < col / 2; k++)
		{
			numbers[i][k] += numbers[i][col - k - 1];
		}
	}

	col /= 2;

	return numbers;
}



// Task 3

int**& MinOfColumns(int**& numbers, int& row, int& col)
{
	for (int i = 0; i < row; i++)
	{
		for (int k = 0; k < col-1 ; k++)
		{
			numbers[i][0] += numbers[i][col - k - 1];
		}
	}

	col /= 4;

	return numbers;
}



// Task 4

int**& MinOfRows(int**& numbers, int& row, int& col)
{
	for (int i = 0; i < row-1; i++)
	{
		for (int k = 0; k < col - 1; k++)
		{
			numbers[0][k] *= numbers[row-i-1][k];
		}
	}

	row /= 4;

	return numbers;
}





void main()
{

	srand(time(NULL));

#pragma region Task 1

	// 1. Maxtrix-i X oxu üzrə qatlayın və üst-üstə düşən elementləri vurun.

	/*
	int row = 4, col = 4;
	int** numbers = new int* [4] {new int[4], new int[4], new int[4], new int[4]};

	InitArray(numbers, row, col);
	cout << "\033[31m" << "   Default Array: \n\n" << "\033[0m";
	PrintArray(numbers, row, col);

	numbers = MultOfRows(numbers, row, col);

	cout << "\033[32m" << "\n   Updated Array:\n\n" << "\033[0m";

	PrintArray(numbers, row, col);
	DeleteArray(numbers);
	*/

#pragma endregion



#pragma region Task 2

	// 2. Maxtrix-i Y oxu üzrə qatlayın və üst-üstə düşən elementləri toplayın.

	/*
	int row = 4, col = 4;
	int** numbers = new int* [4] {new int[4], new int[4], new int[4], new int[4]};

	InitArray(numbers, row, col);
	cout << "\033[31m" << "   Default Array: \n\n" << "\033[0m";
	PrintArray(numbers, row, col);

	numbers = SumOfColumns(numbers, row, col);

	cout << "\033[32m" << "\n   Updated Array:\n\n" << "\033[0m";

	PrintArray(numbers, row, col);
	DeleteArray(numbers);
	*/

#pragma endregion



#pragma region Task 3

	// 3. Sütunu minimal ölçüyə gələnə qədər sıxlaşdırın.

	/*
	int row = 4, col = 4;
	int** numbers = new int* [4] {new int[4], new int[4], new int[4], new int[4]};

	InitArray(numbers, row, col);
	cout << "\033[31m" << "   Default Array: \n\n" << "\033[0m";
	PrintArray(numbers, row, col);

	numbers = MinOfColumns(numbers, row, col);

	cout << "\033[32m" << "\n   Updated Array:\n\n" << "\033[0m";

	PrintArray(numbers, row, col);
	DeleteArray(numbers);
	*/

#pragma endregion



#pragma region Task 4

	// 4. Sətiri minimal ölçüyə gələnə qədər sıxlaşdırın.

	/*
	int row = 4, col = 4;
	int** numbers = new int* [4] {new int[4], new int[4], new int[4], new int[4]};

	InitArray(numbers, row, col);
	cout << "\033[31m" << "   Default Array: \n\n" << "\033[0m";
	PrintArray(numbers, row, col);

	numbers = MinOfRows(numbers, row, col);

	cout << "\033[32m" << "\n   Updated Array:\n\n" << "\033[0m";

	PrintArray(numbers, row, col);
	DeleteArray(numbers);
	*/

#pragma endregion


}