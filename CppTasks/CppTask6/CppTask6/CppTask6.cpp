#include <iostream>
using namespace std;



//Task 1

float cubeNum = 0;

float Cube(float number) {

	cubeNum = number * number * number;

	return cubeNum;
}



//Task 2

float Compare(float number1, float number2) {

	if (number1 > number2) 
	{
		return number1;
	}
	else 
	{
		return number2;
	}
}



//Task 3

bool SignFinder(float number) {

	if (number > 0) 
	{
		return true;
	}
	else if (number < 0)
	{
		return false;
	}

}



//Task 4

float Addition(float number1, float number2)
{
	return number1 + number2;
}

float Substraction(float number1, float number2)
{
	return number1 - number2;
}

float Multiplication(float number1, float number2)
{
	return number1 * number2;
}

float Division(float number1, float number2)
{
	return number1 / number2;
}


float Calculator(int choice, float number1, float number2) {
	if (choice == 1) {
		Addition(number1, number2);
	}
	else if (choice == 2) {
		Substraction(number1, number2);
	}
	else if (choice == 3) {
		Multiplication(number1, number2);
	}
	else if (choice == 4) {
		Division(number1, number2);
	}
	else {
		return 0;
	}

}



//Task 5

void SquarePrinter(int size) {
	for (int i = 0; i < size; i++)
	{
		for (int k = 0; k < size; k++)
		{
			cout << "* ";
		}
		cout << endl;
	}
}



//Task 6

int counter=0;

bool IsPrime(int number) {
	for (int i = 2; i < number; i++)
	{
		if (number % i == 0)
		{
			counter++;
		}
	}
	if (counter != 0) 
	{
		return false;
	}
	else
	{
		return true;
	}
}



//Task 7

int Factorial(int number) {

	for (int i = number-1; i > 1; i--)
	{
		number *= i;
	}
	return number;
}



//Task 8

float powerNum = 1;

float Power(float number,int power) {
	for (int i = 0; i < power; i++)
	{
		powerNum *= number;
	}
	return powerNum;
}



//Task 9

int sum = 0;

int SumRange(int startNum, int endNum) {
	for (int i = startNum + 1; i < endNum; i++)
	{
		sum += i;
	}
	return sum;
}



//Task 10

void InitArray(int numbers[], int size, int min, int max) 
{	
	for (int i = 0; i < size; i++)
	{
		numbers[i] = rand() % (max - min + 1) + min;
	}
}

void PrintArray(int numbers[], int size) 
{	
	for (int i = 0; i < size; i++)
	{
		cout << numbers[i] << "  ";		
	}
}

int maxEl = 0;

int MaxElement(int numbers[],int size) 
{
	for (int i = 0; i < size; i++)
	{
		if (maxEl<numbers[i])
		{
			maxEl = numbers[i];
		}
	}
	return maxEl;
}






void main()
{

#pragma region Task 1

	// 1. Ədədin kubunu qaytaran funksiya yazın.

	/*
	float number1;
	cout << "Enter The Number: ";
	cin >> number1;
	cout << Cube(number1);
	*/

#pragma endregion


	
#pragma region Task 2

	// 2. İki ədəddən böyüyünü tapan funksiya yazın.

	/*
	float number2, number3;
	cout << "Enter The Numbers\n\nFirst: ";
	cin >> number2;
	cout << "Second:";
	cin >> number3;
	cout << Compare(number2,number3)<<" is bigger than other number.";
	*/

#pragma endregion



#pragma region Task 3

	// 3. Ədəd müsbətdirsə doğru, mənfidirsə yanlış qaytaran funksiya yazın.

	/*
	float number4;
	cout << "Enter The Number: ";
	cin >> number4;
	cout << SignFinder(number4);
	*/

#pragma endregion



#pragma region Task 4

	// 4. İstifadəçinin seçimindən asılı olaraq Toplama, Çıxma , Vurma, Bölmə
	// funksiyalarından birini çağıran funksiya yazın.

	/*
	int choice;
	float number1, number2;
	cout << "Enter The Numbers.\n\nFirst Number: ";
	cin >> number1;
	cout << "Second Number: ";
	cin >> number2;
	cout << "\n1) a + b \n2) a - b \n3) a * b \n4) a / b";
	cout << "\n\nYour Choice: ";
	cin >> choice;
	cout << "\nResult: " << Calculator(choice, number1, number2) << endl;
	*/

#pragma endregion



#pragma region Task 5

	// 5. Parametr kimi tərfinin uzunluğunu qəbul edən və ekrana həmin
	// ölçüdə kvadrat çıxaran funksiya yazın.

	/*
	int size;
	cout << "Enter The Size: ";
	cin >> size;
	SquarePrinter(size);
	*/

#pragma endregion



#pragma region Task 6

	// 6. Göndərilən rəqəmin sadə olub olmadığını yoxlayan funksiya yazın.

	/*
	int number;
	cout << "Enter The Number: ";
	cin >> number;
	if (number < 2) {
		cout << "The Number should be bigger than Two (2) !!";
	}

	else {
		if (IsPrime(number))
		{
			cout << "The Number You've Entered is Prime";
		}
		else
		{
			cout << "The Number You've Entered is not Prime";
		}
	}
	*/

#pragma endregion



#pragma region Task 7

	// 7. Ədədin faktorialını qaytaran funksiya yazın.

	/*
	int number;
	cout << "Enter The Number: ";
	cin >> number;
	if (number < 1) 
	{
		cout << "The Number should be Positive !! ";
	}

	else {
		cout << "\nThe Factorial of " << number << " is " << Factorial(number) << "." << endl;
	}
	*/

#pragma endregion


#pragma region Task 8

	// 8. İki parametr qəbul edən : Üst və Qüvvət , və ədədin qüvvətini
	// qaytaran funksiya yazın.

	/*
	float number;
	int power;

	cout << "Enter The Number: ";
	cin >> number;
	cout << "\nEnter Power: ";
	cin >> power;
	cout << "\nThe Power of " << number << " is " << Power(number,power) << "." << endl;
	*/

#pragma endregion



#pragma region Task 9

	// 9. Funksiya 2 ədəd qəbul etsin və bunlar arasındakı bütün ədədləri
	// toplayıb qaytarsın.

	/*
	int startRange;
	int endRange;

	cout << "Enter The Start Number of Range: ";
	cin >> startRange;
	cout << "\nEnter The End Number of Range: ";
	cin >> endRange;
	cout << "\nThe Sum of Range (" << startRange <<" and "<<endRange<< ") is " << SumRange(startRange, endRange) << "." << endl;
	*/

#pragma endregion



#pragma region Task 10

	// Massivdəki ən böyük ədədi qaytaran funksiya yazın.

	/*
	const int size = 6;
	int numbers[size]{},min,max;
	cout << "Min: ";
	cin >> min;
	cout << "Max: ";
	cin >> max;
	InitArray(numbers, size, min, max);
	cout << endl;
	cout << "Max Element of Array\n";
	PrintArray(numbers, size);
	cout << "\nis " << MaxElement(numbers, size) << ".\n";
	*/

#pragma endregion


}


