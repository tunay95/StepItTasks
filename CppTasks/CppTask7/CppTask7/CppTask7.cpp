#include <iostream>
#include<iomanip>
using namespace std;


//Task 4


template<typename InitT>
auto InitArray(InitT numbers[], int size, int min, int max)
{
	for (int i = 0; i < size; i++)
	{
		numbers[i] = rand() % (max - min + 1) + min;
	}
	return numbers;
}

void InitArray(float numbers[], int size, int min, int max)
{
	for (int i = 0; i < size; i++)
	{
		numbers[i] = float(rand() % (max - min + 1) + min) / 10;
	}
}

void InitArray(double numbers[], int size, int min, int max)
{
	for (int i = 0; i < size; i++)
	{
		numbers[i] = double(rand() % (max - min + 1) + min) / 10;
	}
}

template<typename T>
auto BubbleSort(T numbers[], int size, bool isIncreasing)
{
	T temp = 0;
	for (int i = 0; i < size; i++)
	{
		if (isIncreasing)
		{
			for (int k = 0; k < size - 1; k++)
			{
				if (numbers[k] > numbers[k + 1]) {
					temp = numbers[k + 1];
					numbers[k + 1] = numbers[k];
					numbers[k] = temp;
				}
			}

		}
		else {
			for (int k = 0; k < size - 1; k++)
			{
				if (numbers[k] < numbers[k + 1]) {
					temp = numbers[k + 1];
					numbers[k + 1] = numbers[k];
					numbers[k] = temp;
				}
			}
		}
	}
	return numbers;
}


template<typename PrintT>
void PrintArray(PrintT numbers[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << numbers[i] << "  ";
	}
	cout << endl;
}



//Task 5

template <typename T>
int Search(T numbers[], int size, T searchedNum)
{
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		if (numbers[i] == searchedNum)
		{
			return i;
			counter++;
		}
	}
	if (counter == 0)
	{
		return -1;
	}
}

/*
int Search(float numbers[], int size, float searchedNum)
{
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		if (numbers[i] == searchedNum)
		{
			return i;
			counter++;
		}
	}
	if (counter == 0)
	{
		return -1;
	}
}

int Search(int numbers[], int size, int searchedNum)
{
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		if (numbers[i] == searchedNum)
		{
			return i;
			counter++;
		}
	}
	if (counter == 0)
	{
		return -1;
	}
}

int Search(char numbers[], int size, char searchedNum)
{
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		if (numbers[i] == searchedNum)
		{
			return i;
			counter++;
		}
	}
	if (counter == 0)
	{
		return -1;
	}
}

int Search(double numbers[], int size, double searchedNum)
{
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		if (numbers[i] == searchedNum)
		{
			return i;
			counter++;
		}
	}
	if (counter == 0)
	{
		return -1;
	}
}
*/



//Task 6

template <typename T>
T MinimumElement(T numbers[], int size, int min, int max)
{
	T minEl = numbers[0];
	for (int i = 0; i < size; i++)
	{
		if (numbers[i] < minEl)
		{
			minEl = numbers[i];
		}
	}
	return minEl;
}



//Task 7

template <typename T>
T MaximumElement(T numbers[], int size, int min, int max)
{
	T maxEl = numbers[0];
	for (int i = 0; i < size; i++)
	{
		if (numbers[i] > maxEl)
		{
			maxEl = numbers[i];
		}
	}
	return maxEl;
}


/*
int MaximumElement(int numbers[], int size, int min, int max)
{
	int maxEl = numbers[0];
	for (int i = 0; i < size; i++)
	{
		if (numbers[i] > maxEl)
		{
			maxEl = numbers[i];
		}
	}
	return maxEl;
}

float MaximumElement(float numbers[], int size, int min, int max)
{
	float maxEl = numbers[0];
	for (int i = 0; i < size; i++)
	{
		if (numbers[i] > maxEl)
		{
			maxEl = numbers[i];
		}
	}
	return maxEl;
}

char MaximumElement(char numbers[], int size, int min, int max)
{
	char maxEl = numbers[0];
	for (int i = 0; i < size; i++)
	{
		if (numbers[i] > maxEl)
		{
			maxEl = numbers[i];
		}
	}
	return maxEl;
}

double MaximumElement(double numbers[], int size, int min, int max)
{
	double maxEl = numbers[0];
	for (int i = 0; i < size; i++)
	{
		if (numbers[i] > maxEl)
		{
			maxEl = numbers[i];
		}
	}
	return maxEl;
}
*/



//Task 8

template<typename T>
void SliderFunction(T numbers[], const int size, int sliderIndex)
{
	T numbers5[size];

	for (int i = 0; i < size; i++)
	{
		if (i >= size - sliderIndex)
		{
			numbers5[abs(size - (i + sliderIndex))] = numbers[i];
		}
		else {
			numbers5[i + sliderIndex] = numbers[i];
		}
	}

	for (int k = 0; k < size; k++)
	{
		numbers[k] = numbers5[k];
	}
}



void main()
{

#pragma region Bubble Sort (Task 4)

	// 4. Bubble sort edən funksiya yazın. (Funksiya massiv, ölçüsü və boolqəbul edir.
	// Əgər funksiyaya true göndərilərsə sort - azalandan artana, false qəbul edirsə artandan azalana sort olur).

	/*
	srand(time(NULL));
	const int size = 5;
	int numbers[size], max, min;
	float numbers2[size];
	char numbers3[size];
	double numbers4[size];

	cout << "Enter Min: ";
	cin >> min;
	cout << "Enter Max: ";
	cin >> max;
	cout << "Do you want the function to be increasing order ? \n(For Yes: 1, For No: 0) ==> Your Choice: ";
	bool isIncreasing;
	cin >> isIncreasing;
	cout << endl;

	InitArray(numbers, size, min, max);
	cout << setw(15) << "Default Array: ";
	PrintArray(numbers, size);
	BubbleSort(numbers, size, isIncreasing);
	cout << setw(15) << "Sorted Array: ";
	PrintArray(numbers, size);

	cout << endl;

	InitArray(numbers2, size, min, max);
	cout << setw(15) << "Default Array: ";
	PrintArray(numbers2, size);
	BubbleSort(numbers2, size, isIncreasing);
	cout << setw(15) << "Sorted Array: ";
	PrintArray(numbers2, size);

	cout << endl;

	InitArray(numbers3, size, min, max);
	cout << setw(15) << "Default Array: ";
	PrintArray(numbers3, size);
	BubbleSort(numbers3, size, isIncreasing);
	cout << setw(15) << "Sorted Array: ";
	PrintArray(numbers3, size);

	cout << endl;

	InitArray(numbers4, size, min, max);
	cout << setw(15) << "Default Array: ";
	PrintArray(numbers4, size);
	BubbleSort(numbers4, size, isIncreasing);
	cout << setw(15) << "Sorted Array: ";
	PrintArray(numbers4, size);
	*/

#pragma endregion



#pragma region Searching Function (Task 5)

	// 5. Massivdəki elementi axtaran funksiya yazın, funksiyaya massiv, ölçüsü və axtarılan rəqəm göndərilir. 
	// Funksiya tapılan elementin indexini qaytarır. (int, double, float, char)

	/*
	srand(time(NULL));
	const int size = 5;

	int numbers[size], max, min;
	int searchedNum;

	float numbers2[size];
	float searchedNum2;

	char numbers3[size];
	char searchedNum3;

	double numbers4[size];
	double searchedNum4;

	cout << "Enter Min: ";
	cin >> min;
	cout << "Enter Max: ";
	cin >> max;
	cout << endl;

	InitArray(numbers, size, min, max);
	cout << setw(15) << "Default Array: ";
	PrintArray(numbers, size);
	cout << "Enter Searched Number: ";
	cin >> searchedNum;
	if (Search(numbers, size, searchedNum) == -1) {
		cout << "The Searched Number was not Found.\n";
	}
	else {
		cout << "The Index of Number that You Searched is " << Search(numbers, size, searchedNum) << ".\n";
	}

	cout << endl;

	InitArray(numbers2, size, min, max);
	cout << setw(15) << "Default Array: ";
	PrintArray(numbers2, size);
	cout << "Enter Searched Number: ";
	cin >> searchedNum2;
	if (Search(numbers2, size, searchedNum2) == -1) {
		cout << "The Searched Number was not Found.\n";
	}
	else {
		cout << "The Index of Number that You Searched is " << Search(numbers2, size, searchedNum2) << ".\n";
	}

	cout << endl;

	InitArray(numbers3, size, min, max);
	cout << setw(15) << "Default Array: ";
	PrintArray(numbers3, size);
	cout << "Enter Searched Number: ";
	cin >> searchedNum3;
	if (Search(numbers3, size, searchedNum3) == -1) {
		cout << "The Searched Number / Character was not Found.\n";
	}
	else {
		cout << "The Index of Number / Character that You Searched is " << Search(numbers3, size, searchedNum3) << ".\n";
	}

	cout << endl;

	InitArray(numbers4, size, min, max);
	cout << setw(15) << "Default Array: ";
	PrintArray(numbers4, size);
	cout << "Enter Searched Number: ";
	cin >> searchedNum4;
	if (Search(numbers4, size, searchedNum4) == -1) {
		cout << "The Searched Number was not Found.\n";
	}
	else {
		cout << "The Index of Number that You Searched is " << Search(numbers4, size, searchedNum4) << ".\n";
	}
	*/

#pragma endregion



#pragma region Minimum Element (Task 6)

	// 6. Massivdəki ən kiçik elementi tapan funksiya yazın. (Massivi sort etmək olmaz)

	/*
	srand(time(NULL));
	const int size = 5;

	int numbers[size], max, min;
	int searchedNum;

	float numbers2[size];
	float searchedNum2;

	char numbers3[size];
	char searchedNum3;

	double numbers4[size];
	double searchedNum4;

	cout << "Enter Min: ";
	cin >> min;
	cout << "Enter Max: ";
	cin >> max;
	cout << endl;

	InitArray(numbers, size, min, max);
	cout << setw(15) << "Default Array: ";
	PrintArray(numbers, size);
	cout << "Minimum Element of Array is " << MinimumElement(numbers, size, min, max) << ".\n\n";

	InitArray(numbers2, size, min, max);
	cout << setw(15) << "Default Array: ";
	PrintArray(numbers2, size);
	cout << "Minimum Element of Array is " << MinimumElement(numbers2, size, min, max) << ".\n\n";

	InitArray(numbers3, size, min, max);
	cout << setw(15) << "Default Array: ";
	PrintArray(numbers3, size);
	cout << "Minimum Element of Array is " << MinimumElement(numbers3, size, min, max) << ".\n\n";

	InitArray(numbers4, size, min, max);
	cout << setw(15) << "Default Array: ";
	PrintArray(numbers4, size);
	cout << "Minimum Element of Array is " << MinimumElement(numbers4, size, min, max) << ".\n";
	*/

#pragma endregion



#pragma region Maximum Element (Task 7)

	// 7. Massivdəki ən böyük elementi tapan funksiya yazın. (Massivi sort etmək olmaz)
	// (int, double, float, )

	/*
	srand(time(NULL));
	const int size = 5;

	int numbers[size], max, min;
	int searchedNum;

	float numbers2[size];
	float searchedNum2;

	char numbers3[size];
	char searchedNum3;

	double numbers4[size];
	double searchedNum4;

	cout << "Enter Min: ";
	cin >> min;
	cout << "Enter Max: ";
	cin >> max;
	cout << endl;

	InitArray(numbers, size, min, max);
	cout << setw(15) << "Default Array: ";
	PrintArray(numbers, size);
	cout << "Maximum Element of Array is " << MaximumElement(numbers, size, min, max) << ".\n\n";

	InitArray(numbers2, size, min, max);
	cout << setw(15) << "Default Array: ";
	PrintArray(numbers2, size);
	cout << "Maximum Element of Array is " << MaximumElement(numbers2, size, min, max) << ".\n\n";

	InitArray(numbers3, size, min, max);
	cout << setw(15) << "Default Array: ";
	PrintArray(numbers3, size);
	cout << "Maximum Element of Array is " << MaximumElement(numbers3, size, min, max) << ".\n\n";

	InitArray(numbers4, size, min, max);
	cout << setw(15) << "Default Array: ";
	PrintArray(numbers4, size);
	cout << "Maximum Element of Array is " << MaximumElement(numbers4, size, min, max) << ".\n";
	*/

#pragma endregion



#pragma region Slider Function (Task 8)

	// 8. Massivin funksiyaya ötürülən rəqəm qədər sağa dövrü sürüşməsiniyerinə yetirən funksiya yazın. 
	// (Funksiyaya massiv, ölçüsü və sürüşmə indeksi göndərilir). Məsələn massiv : 1, 2, 3, 4, 5 rəqəmləri ilə
	// dolurudur. Sürüşmə indexi 2dirsə, cavab : 4, 5, 1, 2, 3 .

	/*
	srand(time(NULL));
	const int size = 5;

	int numbers[size], max, min, sliderIndex;
	int searchedNum;

	float numbers2[size];
	float searchedNum2;

	char numbers3[size];
	char searchedNum3;

	double numbers4[size];
	double searchedNum4;

	cout << "Enter Min: ";
	cin >> min;
	cout << "Enter Max: ";
	cin >> max;
	cout << "Enter Slider Index: ";
	cin >> sliderIndex;
	cout << endl;

	InitArray(numbers, size, min, max);
	cout << setw(15) << "Default Array: ";
	PrintArray(numbers, size);
	SliderFunction(numbers, size, sliderIndex);
	cout << setw(15) << "Updated Array: ";
	PrintArray(numbers, size);

	cout << endl;

	InitArray(numbers2, size, min, max);
	cout << setw(15) << "Default Array: ";
	PrintArray(numbers2, size);
	SliderFunction(numbers2, size, sliderIndex);
	cout << setw(15) << "Updated Array: ";
	PrintArray(numbers2, size);

	cout << endl;

	InitArray(numbers3, size, min, max);
	cout << setw(15) << "Default Array: ";
	PrintArray(numbers3, size);
	SliderFunction(numbers3, size, sliderIndex);
	cout << setw(15) << "Updated Array: ";
	PrintArray(numbers3, size);

	cout << endl;

	InitArray(numbers4, size, min, max);
	cout << setw(15) << "Default Array: ";
	PrintArray(numbers4, size);
	SliderFunction(numbers4, size, sliderIndex);
	cout << setw(15) << "Updated Array: ";
	PrintArray(numbers4, size);
	*/

#pragma endregion


}
