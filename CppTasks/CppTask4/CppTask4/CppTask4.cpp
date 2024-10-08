#include <iostream>
using namespace std;

void main()
{

#pragma region Task 1

	// 1. Ölçüsü 10 olan massiv yaradın və içərsini random rəqəmlərlə
	// doldurun.İndeksi cüt olan ədədlərin cəmini, indeksi tək olan
	// ədədlərin isə ədədi ortasını tapın.

	/*
	srand(time(NULL));
	const int size1 = 10;
	int numbers1[size1],max=100,min=0;

	for (int i = 0; i < size1; i++)
	{
		numbers1[i] = rand() % (max - min + 1) + min;
	}

	int sumEven=0,sumOdd=0,count=0;

	for (int i = 0; i < size1; i++)
	{
		cout << numbers1[i] << "  ";

		if (i%2==0 && i>0)
		{
			sumEven += numbers1[i];
		}
		else if (i%2==1)
		{
			sumOdd += numbers1[i];
			count++;
		}

	}
	
	cout << "\n\nSum of Even Numbers: " << sumEven<<endl<<"Avarage of Odd Numbers: "<<sumOdd/count<<endl;
	*/
	
#pragma endregion




#pragma region Task 2

	// 2. 10 simvoldan ibarət char massivi yaradın (random doldurun- nəzərə
	// alın ki char 0 - dan 255 - ə qədərdir).Neçə hərf, rəqəm və punktuasiya
	// simvolu olduğunu hesablayan program yazın.

	/*
	srand(time(NULL));
	const int size1 = 10;
	char numbers1[size1], max = 127, min = 0;				 //max 255 verdikde hamisini punktasiya kimi daxil edir

	for (int i = 0; i < size1; i++)
	{
		numbers1[i] = rand() % (max - min + 1) + min;
	}

	int countLet = 0, countDig = 0, countPunc = 0;

	for (int i = 0; i < size1; i++)
	{
		if (int(numbers1[i])>=48 && int(numbers1[i]) <= 57)
		{
			countDig++;
		}
		else if (int(numbers1[i]) >= 65  && int(numbers1[i]) <= 90  ||
				 int(numbers1[i]) >= 97  && int(numbers1[i]) <= 122 ||
				 int(numbers1[i]) >= 128 &&	int(numbers1[i]) <= 165  )
		{
			countLet++;
		}
		else
		{
			countPunc++;
		}
	}

	for (int i = 0; i < size1; i++)
	{
		cout << numbers1[i] << "  ";
	}

	cout << endl << "Count of Digits: " << countDig << endl 
		<< "Count of Letters: " << countLet<<endl
		<< "Count of Punctuation: " << countPunc;
	*/

#pragma endregion




#pragma region Task 3

	// 3. Ölçüsü 50 olan massiv yaradın və içərisini random doldurun(1-100) .
	// İstifadəçi 1 - 100 arasında rəqəm daxil edir, və massivdə bu əddədən
	// neçə dənə olduğunu hesablayan program yazın.

	/*
	srand(time(NULL));
	const int size2 = 50;
	int numbers2[size2], max = 100, min = 0,counter=0,searchedNumber;				 //max 255 verdikde hamisini punktasiya kimi daxil edir
	
	cout << "Enter The Number: ";
	cin >> searchedNumber;

	for (int i = 0; i < size2; i++)
	{
		numbers2[i] = rand() % (max - min + 1) + min;
	}

	for (int i = 0; i < size2; i++)
	{
		if (searchedNumber==numbers2[i])
		{
			counter++;
		}
	}

	cout << endl;

	for (int i = 0; i < size2; i++)
	{
		cout << numbers2[i] << "  ";
	}

	cout <<"\n\nCount of the Searched Number: " << counter << endl;
	*/

#pragma endregion




#pragma region Task 4

	// 4. 1 və 100 arasında random rəqəmlərdən ibarət ölçüsü 10 olan massiv
	// yaradın. 3 - ə, 5 - ə.7 - ə bölünən rəqəmlərin sayını tapın. (ayrı - ayrı)

    /*
	srand(time(NULL));
	const int size1 = 10;
	int numbers3[size1], max = 100, min = 1;
	int count3div = 0, count5div = 0, count7div = 0;

	for (int i = 0; i < size1; i++)
	{
		numbers3[i] = rand() % (max - min + 1) + min;
	}

	for (int i = 0; i < size1; i++)
	{
		if (numbers3[i]%3==0)
		{
			count3div++;
		}
		if (numbers3[i]%5==0)
		{
			count5div++;
		}
		if (numbers3[i]%7==0)
		{
			count7div++;
		}
	}

	for (int i = 0; i < size1; i++)
	{
		cout << numbers3[i] << "  ";
	}

	cout <<"\n\nCount of Divisible by 3: " << count3div << endl
		<< "Count of Divisible by 5: " << count5div << endl
		<< "Count of Divisible by 7: " << count7div << endl;
	*/

#pragma endregion




#pragma region Task 5

	// 5. 1 və 100 arasında random rəqəmlərdən ibarət ölçüsü 10 olan massiv
	// yaradın. 3 - ə bölünüb 5 - ə bölünməyən rəqəmlərin sayını çıxarın.
	// (eyni anda həm 3ə bölünsün həm 5 - ə bölünməsin)

	/*
	srand(time(NULL));
	const int size1 = 10;
	int numbers3[size1], max = 100, min = 1;
	int counter2=0;
	
	for (int i = 0; i < size1; i++)
	{
		numbers3[i] = rand() % (max - min + 1) + min;
	}
	
	for (int i = 0; i < size1; i++)
	{
		if (numbers3[i] % 3 == 0 && numbers3[i] % 5 != 0)
		{
			counter2++;
		}
	}
	
	for (int i = 0; i < size1; i++)
	{
		cout << numbers3[i] << "  ";
	}
	
	cout << "\n\nCount of Divisible by 3 and Not Divisible by 5: " << counter2 << endl;
	*/

#pragma endregion




#pragma region Task 6

	// 6. -10 və 30 arasında random rəqəmlərdən ibarət ölçüsü 10 olan
	// massiv yaradın.Birinci mənfi ədəddən sonra gələn bütün rəqəmləri
	// toplayan program yazın. (1, 2, -3, 4, 5, -6, 7 bu halda,
	// 4 + 5 + (-6) + 7 olacaq)

	/*
	//srand(time(NULL));
	const int size1 = 10;
	int numbers4[size1], max = 30, min = -10;

	for (int i = 0; i < size1; i++)
	{
		numbers4[i] = rand() % (max - min + 1) + min;
	}
	

	for (int i = 0; i < size1; i++)
	{
		cout << numbers4[i] << "  ";
	}

	cout << "\n\n";
	int sumFromNeg = 0;

	for (int i = 1; i < size1; i++)
	{
		if (numbers4[i-1] < 0) {
			for (int k = i; k < size1; k++)
			{
			cout << numbers4[k] << " + ";
			sumFromNeg += numbers4[k];
			}
		}
		break;

	}
	cout << "\b\b\b = " << sumFromNeg << endl;
	*/

#pragma endregion




#pragma region Task 7

	// 7. -30 və 20 arasında random rəqəmlərdən ibarət ölçüsü 10 olan
	// massiv yaradın.Birinci müsbət ədəddən sonra gələn bütün rəqəmləri
    // toplayan program yazın.

	/*
	//srand(time(NULL));
	const int size1 = 10;
	int numbers5[size1], max = 20, min = -30;

	for (int i = 0; i < size1; i++)
	{
		numbers5[i] = rand() % (max - min + 1) + min;
	}


	for (int i = 0; i < size1; i++)
	{
		cout << numbers5[i] << "  ";
	}

	cout << "\n\n";
	int sumFromPos = 0;

	for (int i = 1; i < size1; i++)
	{
		if (numbers5[i-1] > 0) {
			for (int k = i; k < size1; k++)
			{
			cout << numbers5[k] << " + ";
			sumFromPos += numbers5[k];
			}
		}
		break;

	}
	cout << "\b\b\b = " << sumFromPos << endl;
	*/

#pragma endregion
}


