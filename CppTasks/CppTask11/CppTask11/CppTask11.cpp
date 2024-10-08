#include<iostream>
using namespace std;



void DeleteMemory(char*& array)
{
	delete[] array;
}


int& MyStrLen(char*& chrArr)
{
	int count = 0;

	for (int i = 0; chrArr[i] != '\0'; i++)
	{
		count++;
	}

	return count;
}


void PrintArray(char*& array)
{
	for (int i = 0; array[i] != '\0'; i++)
	{
		cout << array[i];
	}

	cout << endl;
}



// Task 1

void MyStrCat(char*& str1, char*& str2)
{
	int size1 = MyStrLen(str1);
	int size2 = MyStrLen(str2);

	for (int i = 0; i < size2; i++)
	{
		str1[size1 + i] = str2[i];
	}
	str1[size1 + size2] = '\0';

	DeleteMemory(str2);

}



// Task 2

char*& FindMyChr(char*& str, char& s)
{
	char* ptr = nullptr;

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == s)
		{
			ptr = &(str[i]);
			str[i + 1] = '\0';
		}
	}

	return ptr;
}



// Task 3

char*& FindStrArray(char*& str1, char*& str2)
{
	char* ptr = nullptr;
	int counter = 1;
	for (int i = 0; str1[i] != '\0'; i++)
	{
		if (str1[i] == str2[0])
		{
			for (int k = 1; k < str2[k] != '\0'; k++)
			{
				if (str1[i + k] = str2[k])
				{
					counter++;
				}
			}
		}
	}

	if (counter >= MyStrLen(str2))
	{
		ptr = &(str1[0]);
	}

	DeleteMemory(str2);
	
	return ptr;
}



// Task 4

int CompMyStr(char*& str1, char*& str2)
{
	int count1 = 0, count2 = 0;

	for (int i = 0; str1[i] != '\0'; i++)
	{
		count1++;
	}

	for (int i = 0; str2[i] != '\0'; i++)
	{
		count2++;
	}

	if (count1 == count2)
	{
		return 0;
	}

	else if (count1 > count2)
	{
		return 1;
	}

	else
	{
		return -1;
	}

}



// Task 5

int StrToNum(char*& str)
{
	int size = MyStrLen(str);
	int num = 0, counter = 1, PowTen = 1;

	for (int i = 0; str[i] != '\0'; i++)
	{
		for (int i = counter; i < size; i++)
		{
			PowTen *= 10;
		}

		num += int(str[i] - '0') * PowTen;
		counter++;
		PowTen = 1;
	}

	return num;
}



// Task 6

char* NumToStr(int number)
{
	int size = 0, digit = 1;
	char* array = new char[20];
	int number2 = number;

	for (int i = 0; number2 >= 1; i++)		//2ci for`un şərtinə daxil ola bilmək üçün yazılıb.
	{
		number2 /= 10;
		size++;
	}

	for (int i = 0; number >= 1; i++)
	{
		digit = number % 10;
		number /= 10;
		array[size - 1 - i] = char(digit + '0');
	}

	array[size] = '\0';

	return array;
}



// Task 7

void StrUpper(char*& str1)
{
	int temp = 0;
	for (int i = 0; str1[i] != 0; i++)
	{
		if (int(str1[i]) >= 97 && int(str1[i]) <= 122)
		{
			temp = int(str1[i]);
			temp -= 32;
			str1[i] = char(temp);
		}
	}

}



// Task 8

void StrLower(char*& str1)
{
	int temp = 0;
	for (int i = 0; str1[i] != 0; i++)
	{
		if (int(str1[i]) >= 65 && int(str1[i]) <= 90)
		{
			temp = int(str1[i]);
			temp += 32;
			str1[i] = char(temp);
		}
	}

}



// Task 9

char*& StrReverse(char*& str)
{
	int size = MyStrLen(str);
	char temp = ' ';

	for (int i = 0; i < size / 2; i++)
	{
		temp = str[size - 1 - i];
		str[size - 1 - i] = str[i];
		str[i] = temp;
	}

	return str;
}



void main()
{


#pragma region Task 1

	// 1. void mystrcat (char &*str1, const char *str2); -
	// funksiya str2 - ni str1 - ə birləşdirir(konkatonatisya).

	/*
	char* strArray1 = new char[20];
	char* strArray2 = new char[20];

	cout << "Enter First Word: ";
	cin.getline(strArray1, 20);
	cout << "Enter Second Word: ";
	cin.getline(strArray2, 20);
	MyStrCat(strArray1, strArray2);
	cout << strArray1 << endl;
	DeleteMemory(strArray1);
	*/

#pragma endregion



#pragma region Task 2

	// 2. char* mystrchr (char *str, char s); - funksiya s simvolunu 
	// str sətrində axtarır əgər taparsa həmin hərfə pointer qaytarır, tapmazsa 0.

	/*
	char* strArray = new char[20];
	char s = 's';

	cout << "Enter The Word: ";
	cin.getline(strArray, 20);
	char* ptr = FindMyChr(strArray, s);

	if (ptr == nullptr)
	{
		cout << "Result: " << "0" << endl;
	}
	else
	{
		cout << "Result: " << &ptr << " or " << *(ptr) << endl;
	}

	DeleteMemory(strArray);
	*/

#pragma endregion



#pragma region Task 3

	// 3. char* mystrstr (char *str1, char *str2); - funksiya str1 sətrinin içində 
	// str2 sətrini axtarır.Tapdığı halda ilk hərfə pointer qaytarır, tapmazsa 0.

	/*
	char* strArray1 = new char[20];
	char* strArray2 = new char[20];

	cout << "Enter First Word: ";
	cin.getline(strArray1, 20);
	cout << "Enter Second Word: ";
	cin.getline(strArray2, 20);
	char* ptr = FindStrArray(strArray1, strArray2);

	if (ptr == nullptr)
	{
		cout << "Result: " << "0" << endl;
	}
	else
	{
		cout << "Result: " << &ptr  << endl;
	}
	
	DeleteMemory(strArray1);
	*/

#pragma endregion



#pragma region Task 4

	// 4. int mystrcmp (const char *str1, const char *str2); - funksiya iki sətri müqayisə edir, 
	// əgər sətirlər bərabərdirsə 0, birinci sətir ikinci sətirdən böyükdürsə 1, kiçikdirsə - 1 qayıdır.

	/*
	char* strArray1 = new char[20];
	char* strArray2 = new char[20];

	cout << "Enter First Word: ";
	cin.getline(strArray1, 20);
	cout << "Enter Second Word: ";
	cin.getline(strArray2, 20);

	cout << "Result: " << CompMyStr(strArray1, strArray2);

	DeleteMemory(strArray1);
	DeleteMemory(strArray2);
	*/

#pragma endregion



#pragma region Task 5

	// 5. int mystrtonum(char *str); - funksiya sətiri rəqəmə
	// çevirir və həmin rəqəmi qatarır.

	/*
	char* strArray1 = new char[20];

	cout << "Enter The Number: ";
	cin.getline(strArray1, 20);

	cout << StrToNum(strArray1);
	DeleteMemory(strArray1);
	*/

#pragma endregion



#pragma region Task 6

	// 6. char* mynumtostr (int number); - funksiya rəqəmi
	// sətirə çevirir və sətirə pointer qaytarır.

	/*
	int number;

	cout << "Enter The Number: ";
	cin >> number;

	cout << NumToStr(number);
	*/

#pragma endregion



#pragma region Task 7

	// 7. void mystrup (char *str1); - funksiya sətirdəki bütün
	// hərfləri böyük hərf edir.

	/*
	char* strArray1 = new char[20];

	cout << "Enter First Word: ";
	cin.getline(strArray1, 20);
	StrUpper(strArray1);

	cout << strArray1;
	DeleteMemory(strArray1);
	*/

#pragma endregion



#pragma region Task 8

	// 8. void mystrlow (char *str1) - funksiya sətirdəki bütün
	// hərfləri kiçik hərf edir.

	/*
	char* strArray1 = new char[20];

	cout << "Enter The Word: ";
	cin.getline(strArray1, 20);
	StrLower(strArray1);

	cout << strArray1;
	DeleteMemory(strArray1);
	*/

#pragma endregion



#pragma region Task 9

	// 9. char* mystrrev (char *str); - funksiya verilən sətri
	// əksinə çevirir. (Salam-- - malaS)

	/*
	char* strArray1 = new char[20];

	cout << "Enter The Word: ";
	cin.getline(strArray1, 20);
	StrReverse(strArray1);

	cout << strArray1;
	DeleteMemory(strArray1);
	*/

#pragma endregion


}