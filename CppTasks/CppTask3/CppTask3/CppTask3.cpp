#include<iostream>
using namespace std;

void main() {

	cout << "\n\n1.=======================================\n\n";

	//Task 1

	/*
	1
	12
	123
	1234
	12345
	123456
	1234567
	12345678
	123456789
	*/

	int size = 10;

	for (int i = 1; i < size; i++) {
		for (int k = 1; k < size; k++)
		{
			if (k <= i) {
				cout << k;
			}
			
			else {
				break;
			}
		}
		cout << endl;
	}

	cout << endl;


	cout << "\n\n2.=======================================\n\n";



	//Task 2

	/*
	1
	21
	321
	4321
	54321
	654321
	7654321
	*/

	int size3 = 8;

	for (int i = 1; i < size3; i++) {
		for (int k = size3; k > 0; k--)
		{
			if (k <= i) {
				cout << k;
			}

		}
		cout << endl;
	}

	cout << endl;


	cout << "\n\n3.=======================================\n\n";


	//Task 3

	/*
	1
	2 3
	4 5 6
	7 8 9 10
	11 12 13 14 15
	16 17 18 19 20 21
	22 23 24 25 26 27 28
	*/

	int size7 = 28;
	int counter = 1;

	for (int i = 1; i < size7; i++) {
		for (int k = 1; k < size7; k++)
		{
			if (k <= i) {
				cout << counter<<" ";
				counter++;
			}

			else {
				break;
			}
		}
		if (counter == 29) {
			break;
		}

		cout << endl;
	}

	cout << endl;
	cout << endl;


	cout << "\n\n4.=======================================\n\n";


	//Task 4

	/*
	1
	22
	333
	4444
	55555
	666666
	7777777
	88888888
	999999999
	*/

	int size2 = 10;

	for (int i = 1; i < size2; i++) {
		for (int k = 1; k < size2; k++)
		{
			if (k <= i) {
				cout << i;
			}

			else {
				break;
			}
		}
		cout << endl;
	}

	cout << endl;


	cout << "\n\n5.=======================================\n\n";


	//Task 5

	/*
	1
	2 3 2
	4 5 6 5 4
	7 8 9 10 9 8 7 
	*/

	int size6 = 10;
	int counter2 = 1;
	int minus = 2;
	int counter3 = 0;

	for (int i = 0; i < size6; i++) {
		for (int k = 0; k < size6; k++)
		{
			if (k <= i) {
				cout << counter2 << " ";
				counter2++;
			}

			else if (k<=2*i) {
				counter3=counter2-minus;
				cout << counter3<<" ";
				minus++;
			}

			else {
				minus=2;
				break;
			}
		}
		if (counter2 == 11) {
			break;
		}

		cout << endl;
	}

	cout << endl;
	cout << endl;


	cout << "\n\n6.=======================================\n\n";


	//Task 6

	/*
	7777777
	666666
	55555
	4444
	333
	22
	1
	*/

	int size4 = 7;

	for (int i = size4; i >= 1; i--) {
		for (int k = 1; k <= size4; k++)
		{
			if (k <= i) {
				cout << i;
			}

			

			else {
				break;
			}
		}
		cout << endl;
	}

	cout << endl;
	cout << endl;


	cout << "\n\n7.=======================================\n\n";


	//Task 7

	/*
	1234567
	123456
	12345
	1234
	123
	12
	1
	*/

	int size5 = 7;

	for (int i = size5; i >= 1; i--) {
		for (int k = 1; k <= size5; k++)
		{
			if (k <= i) {
				cout << k;
			}

			else {
				break;
			}
		}
		cout << endl;
	}



}
