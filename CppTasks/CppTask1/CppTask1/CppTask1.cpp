#include <iostream>
using namespace std;

void main()
{
    // 1. Istifadəçi ədəd daxil edir. Ekrana əgər ədəd cütdürsə True,
    // təkdirsə False çap olunsun.


    /*
    int num;

    cout << "Enter The Number: ";
    cin >> num;

    cout << (num % 2 == 0);
    */
    



    // 2. İstifadəçi 1 - 20 arası ədəd daxil edir.Ədəd sadədirsə True,
    // mürəkkəbdirsə False çap olunsun. 
    // (Sadə ədədlər yalnız özünə və 1 - ə bölünən ədədlərdir)


   /* 
   int num;

    cout << "Enter The Number: ";
    cin >> num;

    cout << (num == 2 || num == 3 || num == 5 || num == 7 || num == 11 || num == 13 || num == 17 || num == 19);
    */




    // 3. İstifadəçi 5 rəqəmli ədəd daxil edir. Ədədin polindrom olub olmamasını təyin edin. 
    // (Polindrom - əksinə və düzünə eyni cür oxunur 12321 polindromdur, 12345 polindrom deyil)


    /* 
    int num;

    cout << "Enter The Number: ";
    cin >> num;

    int FirstDig = num / 10000;
    int SecondDig = num / 1000 % 10;
    int FourthDig = num / 10 % 10;
    int LastDig = num % 10;


    cout << (FirstDig == LastDig && SecondDig == FourthDig);
    */




    // 4. İstifadəçi rəqəm daxil edir ( 1dən - 9 rəqəmliyə kimi ola bilər).
    // Onun neçə rəqəmdən ibarət olduğunu tapın. Sadece 1 dəyişənden istifadə edə bilərsiniz.

    /*
    int num;

    cout << "Enter The Number: ";
    cin >> num;

    cout << (num/10!=0);
    cout << (num/10!=0);
    num /= 10;
    cout << (num/10!=0);
    num /= 10;
    cout << (num/10!=0);
    num /= 10;
    cout << (num/10!=0);
    num /= 10;
    cout << (num/10!=0);
    num /= 10;
    cout << (num/10!=0);
    num /= 10;
    cout << (num/10!=0);
    num /= 10;
    cout << (num/10!=0);
    num /= 10;
    */




    // 5. İstifadəçi 3 ədəd daxil edir. Proqram , əgər birinci ədəd o birilərdən böyükdürsə  
    // ‘1-ci: True’, ikinci ədəd böyükdürsə ‘2-ci: True’, üçüncü ədəd böyükdürsə ‘3-cu: True çap olunsun.


    /*
    int num1;
    int num2;
    int num3;

    cout << "Enter The Numbers: ";
    cout << "1.";
    cin >> num1;
    cout << "2.";
    cin >> num2;
    cout << "3.";
    cin >> num3;

    cout << (num1 > num2 && num1 > num3);
    cout << (num2 > num1 && num2 > num3);
    cout << (num3 > num1 && num3 > num2);
    */




    // 6. İstifadəçi 6 rəqəmli ədəd daxil edir. Tək yerdə duranların cəmi cüt yerdə duranların cəmindən çoxdursa , True , və ya False.
    // Numune: (756189) Tək yerdə duranlar - 7,6,8 // Cüt yerdə duranlar - 5,1,9


    /*
    int num;

    cout << "Enter The Number: ";
    cin >> num;

    int FirstDig = num / 100000;
    int SecondDig = num / 10000 % 10;
    int ThirdDig = num / 1000 % 10;
    int FourthDig = num / 100 % 10;
    int FifthDig = num / 10 % 10;
    int LastDig = num % 10;

    cout << ((FirstDig + ThirdDig + FifthDig) > (SecondDig + FourthDig + LastDig));
    */

}


