#include <iostream>
using namespace std;



// Task 1

int* AllocateMemory(int size)
{
	auto array = new int[size];
	return array;
}

//double* AllocateMemory(int size)
//{
//	auto array = new double[size];
//	return array;
//}
//
//char* AllocateMemory(int size)
//{
//	auto array = new char[size];
//	return array;
//}
//
//float* AllocateMemory(int size)
//{
//	auto array = new float[size];
//	return array;
//}


// Task 2

template <typename T>
void InitArray(T* array, int* size)
{
	int min = 0, max = 100;

	for (int i = 0; i < *size; i++)
	{
		array[i] = min + rand() % (max - min + 1);
	}
}

void InitArray(double* array, int* size)
{
	int min = 0, max = 1000;

	for (int i = 0; i < *size; i++)
	{
		array[i] = double(min + rand() % (max - min + 1)) / 100;
	}
}

void InitArray(float* array, int* size)
{
	int min = 0, max = 1000;

	for (int i = 0; i < *size; i++)
	{
		array[i] = float(min + rand() % (max - min + 1)) / 100;
	}
}


// Task 3

template <typename T>
void PrintArray(T* array, int* size)
{
	for (int i = 0; i < *size; i++)
	{
		cout << array[i] << "  ";
	}
	cout << endl;
}


// Task 4

template <typename T>
void FreeMemory(T* array)
{
	delete[] array;
}


// Task5

template<typename T>
T* AddLastEl(T* array, int* size, T newEl)
{
	T* newArray = new T[*size + 1];

	for (int i = 0; i < *size; i++)
	{
		newArray[i] = array[i];
	}

	newArray[*size] = newEl;
	*size += 1;
	FreeMemory(array);

	return newArray;
}


// Task 6

template<typename T>
T* AddIndexEl(T* array, int* size, T newEl, int index)
{
	T* newArray = new T[*size + 1];

	for (int i = 0; i < *size + 1; i++)
	{
		if (i < index)
		{
			newArray[i] = array[i];
		}

		else {
			newArray[i + 1] = array[i];
		}

	}
	newArray[index] = newEl;

	*size += 1;
	FreeMemory(array);

	return newArray;
}


// Task 7

template<typename T>
T* DelIndexEl(T* array, int* size, int index)
{
	T* newArray = new T[*size - 1];
	for (int i = 0; i < *size; i++)
	{
		if (i < index)
		{
			newArray[i] = array[i];
		}
		else {
			newArray[i] = array[i + 1];
		}

	}
	*size -= 1;
	FreeMemory(array);

	return newArray;
}


// Task 8

template<typename T>
T* AddLastArr(T* array, T* array2, int* size, int* size2)
{
	T* newArray = new T[*size + *size2];

	for (size_t i = 0; i < *size + *size2; i++)
	{
		if (i < *size)
		{
			newArray[i] = array[i];
		}

		else
		{
			newArray[i] = array2[i - *size];
		}

	}

	*size += *size2;

	FreeMemory(array);
	FreeMemory(array2);

	return newArray;
}


// Task 9

template<typename T>
T* AddIndexArr(T* array, T* array2, int* size, int* size2, int index)
{
	T* newArray = new T[*size + *size2];

	for (size_t i = 0; i < *size + *size2; i++)
	{
		if (i < index)
		{
			newArray[i] = array[i];
		}

		else if (i >= index + *size2)
		{
			newArray[i] = array[i - *size2];
		}

		else
		{
			newArray[i] = array2[i - index];
		}

	}

	*size += *size2;

	FreeMemory(array);
	FreeMemory(array2);

	return newArray;
}


// Task 10 

template <typename T>
T* DelIndexArr(T* array, int* size, int index, int count)
{
	T* newArray = new T[*size - count];

	for (int i = 0; i < *size; i++)
	{
		if (i < index)
		{
			newArray[i] = array[i];
		}

		else
		{
			newArray[i] = array[i + count];
		}
	}

	*size -= count;
	FreeMemory(array);

	return newArray;
}

void main()
{

	srand(time(NULL));

	/*
		int choice;
	cout << "What kind of Array do you want to create ?\n\n1) int \n2) double \n3) float \n4) char\n\nEnter Your Choice: ";
	cin >> choice;
	 
	if (choice == 1)
	{
		int size = 14;
	  auto memory = AllocateMemory(size);
	}

	else if (choice == 2)
	{
		int size = 14;
		auto memory = AllocateMemory<double>(size);
	}

	else if (choice == 3)
	{
		int size = 14;
		auto memory = AllocateMemory<float>(size);
	}

	else if (choice==4)
	{
		int size = 14;
		auto memory = AllocateMemory<char>(size);
	}

	else
	{
		cout << "Enter The Correct Choice !!";
	}
	*/


#pragma region Task 1

	// 1. Dinamik yaddaş ayıran funskiya yazın.

	int size = 14;
	auto memory = AllocateMemory(size);

#pragma endregion



#pragma region Task 2

	// 2. Dinamik massivi random ədədlərlə dolduran funksiya yazın.

	InitArray(memory, &size);

#pragma endregion



#pragma region Task 3

	// 3. Dinamik massivi ekrana çıxaran funksiya yazın.

	cout << "\033[31m" << "Default Array:  " << "\033[0m";
	PrintArray(memory, &size);

#pragma endregion



#pragma region Task 4

	// 4. Dinamik massivi silən funksiya yazın

	/*FreeMemory(memory);*/

#pragma endregion



#pragma region Task 5

	// 5. Dinamik massivin sonuna element əlavə edən funksiya yazın.

	/*
	int newEl;

	cout << "\nThe Element that you want to add: ";
	cin >> newEl;
	cout << endl;

	auto newArray=AddLastEl(memory, &size, newEl);
	cout << "\033[32m" << "Updated Array:  " << "\033[0m";
	PrintArray(newArray, &size);
	FreeMemory(newArray);
	*/

#pragma endregion



#pragma region Task 6

	// 6. Dinmaik massivin göstərilən indexinə element əlavə edən funksiya yazın.

	/*
	int newEl;
	int index;

	cout << "\nThe Element that you want to add: ";
	cin >> newEl;
	cout << "\nThe Index that you want to add The Element: ";
	cin >> index;
	cout << endl;

	auto newArray = AddIndexEl(memory, &size, newEl, index);
	cout << "\033[32m" << "Updated Array:  " << "\033[0m";
	PrintArray(newArray, &size);
	FreeMemory(newArray);
	*/

#pragma endregion



#pragma region Task 7

	// 7. Dinamik massivdən göstərilən indexdəki elementin silinməsi.

	/*
	int index;

	cout << "\nThe Index that you want to delete The Element: ";
	cin >> index;
	cout << endl;

	auto newArray = DelIndexEl(memory, &size, index);
	cout << "\033[32m" << "Updated Array:  " << "\033[0m";
	PrintArray(newArray, &size);
	FreeMemory(newArray);
	*/

#pragma endregion



#pragma region Task 8

	// 8. Dinamik massivin sonuna bir blok element əlavə edən funksiya yazın.

	/*
	int size2 = 7;
	auto memory2 = AllocateMemory(size2);
	InitArray(memory2, &size2);
	cout << "\033[31m" << "\nDefault Array 2:  " << "\033[0m";
	PrintArray(memory2, &size2);

	auto newArray = AddLastArr(memory, memory2, &size, &size2);
	cout << "\033[32m" << "\nUpdated Array:  " << "\033[0m";
	PrintArray(newArray, &size);
	FreeMemory(newArray);
	*/

#pragma endregion



#pragma region Task 9

	// 9. Dinamik massivin göstərilən indexindən sonra bir blok element əlavə edən funksiya yazın.

	/*
	int index;

	int size2 = 7;
	auto memory2 = AllocateMemory(size2);
	InitArray(memory2, &size2);
	cout << "\033[31m" << "\nDefault Array 2:  " << "\033[0m";
	PrintArray(memory2, &size2);

	cout << "\nThe Index that you want to add The Array: ";
	cin >> index;
	cout << endl;

	auto newArray = AddIndexArr(memory, memory2, &size, &size2,index);
	cout << "\033[32m" << "\nUpdated Array:  " << "\033[0m";
	PrintArray(newArray, &size);
	FreeMemory(newArray);
	*/

#pragma endregion



#pragma region Task 10

	// 10. Dinamik massivdən bir blok elementi silən funksiya yazın.

	/*
	int index, count;

	cout << "\nThe Index that you want to delete The Array: ";
	cin >> index;
	cout << "\nThe Count of The Elements that you want to delete: ";
	cin >> count;
	cout << endl;

	auto newArray = DelIndexArr(memory, &size, index, count);
	PrintArray(newArray, &size);
	FreeMemory(newArray);
	*/

#pragma endregion


}
