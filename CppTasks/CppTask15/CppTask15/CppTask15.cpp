#include<iostream>
using namespace std;

#pragma region Task

//Fraction - kesr

	//numerator - suret 
	//denumerator - mexrec

	/*
	+
	-
	*
	/

	*/

//Fraction a(10, 20);
//Fraction b(1, 3);
//
//1 / 2 + 1 / 3 = 5 / 6
//
//Fraction c = a + b;
//cout << c;
//cin >> c;
//c += d;
//Fraction d = c.plus(a);
// plus   mult   subt   div

//-- ++

//+  -   *   /

//+=   -=   /=   *=

#pragma endregion


class Fraction
{
private:

	int numerator,denominator;

public:

	Fraction(int numerator, int denominator)
	{
		this->numerator = numerator;
		this->denominator = denominator;
	}

	int getNumer() const
	{
		return numerator;
	}

	int getDenom() const
	{
		return denominator;
	}

	void setNumer(int& numerator)
	{
		if (numerator == 0)
		{
			cout << "Numerator must be different from 0(If you chose Division op).\n\nNew Numerator: ";
			cin >> numerator;
		}

		this->numerator = numerator;
	}

	void setDenom(int& denominator)
	{
		if (denominator == 0)
		{
			cout << "Denominator must be different from 0.\n\nNew Denominator: ";
			cin >> denominator;
		}

		this->denominator = denominator;
	}

	Fraction Addition(const Fraction& other)
	{
		int newDenom = denominator * other.denominator;
		int newNumer = (newDenom / denominator) * numerator + (newDenom / other.denominator) * other.numerator;

		Fraction newFrac(newNumer, newDenom);
		
		return newFrac;
	}

	Fraction Substraction(const Fraction& other)
	{
		int newDenom = denominator * other.denominator;
		int newNumer = (newDenom / denominator) * numerator - (newDenom / other.denominator) * other.numerator;

		Fraction newFrac(newNumer, newDenom);
		
		return newFrac;
	}

	Fraction Multiplication(const Fraction& other)
	{
		int newDenom = denominator * other.denominator;
		int newNumer = numerator * other.numerator;
		
		Fraction newFrac(newNumer, newDenom);
		
		return newFrac;
	}

	Fraction Division(const Fraction& other)
	{
		int newDenom = denominator * other.numerator;
		int newNumer = numerator * other.denominator;
		
		Fraction newFrac(newNumer, newDenom);
		
		return newFrac;
	}

	void Simplify()
	{
		for (int i = denominator / 2; i > 1; i--)
		{
			if (denominator % i == 0 && numerator % i == 0)
			{
				denominator /= i;
				numerator /= i;
			}
		}
	}

	void Print()
	{
		if (this->denominator == 1)
		{
			cout << numerator;
		}

		else if (this->numerator % this->denominator == 0)
		{
			cout << numerator / denominator;
		}

		else
		{
			cout << numerator << "/" << denominator;
		}
	}
};


void main()
{
	int denominator, numerator, denominator2, numerator2, choice;

	cout << "The Denominator of The First Fraction: ";
	cin >> denominator;
	cout << "The Numerator of The First Fraction: ";
	cin >> numerator;

	Fraction fraction1(numerator, denominator);
	fraction1.setDenom(denominator);

	cout << "The Denominator of The Second Fraction: ";
	cin >> denominator2;
	cout << "The Numerator of The Second Fraction: ";
	cin >> numerator2;

	Fraction fraction2(numerator2, denominator2);
	fraction2.setDenom(denominator2);

	cout << "\n==============================================\n\n1) Addition \n2) Substraction \n3) Multiplication \n4) Division \n\nChoice: ";
	cin >> choice;
	cout << endl;

	while (choice > 4 || choice < 1)
	{
		cout << "Enter The Correct Choice !!\n\n";
		cout << "New Choice: ";
		cin >> choice;
		cout << endl;
	}

	Fraction result(0, 1);			//  Default constructor`a olmadan aşağıdakı əməliyatları edə bilməsi üçün. 
	fraction1.Print();

	if (choice == 1)
	{
		result = fraction1.Addition(fraction2);

		cout << " + ";
	}

	else if (choice == 2)
	{
		result = fraction1.Substraction(fraction2);

		cout << " - ";
	}

	else if (choice == 3)
	{
		result = fraction1.Multiplication(fraction2);

		cout << " * ";
	}

	else if (choice == 4)
	{
		fraction2.setNumer(numerator2);
		result = fraction1.Division(fraction2);

		cout << " : ";
	}

	result.Simplify();

	fraction2.Print();

	cout << " = ";
	
	result.Print();
	
	cout << endl;

}
