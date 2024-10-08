#include <iostream>
using namespace std;

void main()
{   
    int day, month, year;

    cout << "Please Enter A Date.\n\nDay: ";
    cin >> day;
    cout << "Month: ";
    cin >> month;
    cout << "Year: ";
    cin >> year;
    cout << endl;
    enum eMonth { LongMonths=1, ShortMonths, February, December };
    eMonth option;

    if (1 < day && day > 31) {
        cout << "Enter Correct Day !!";
    }
    else {
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10) {
            option = LongMonths;
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11) {
            option = ShortMonths;
        }
        else if (month == 2) {
            option = February;
        }
        else if (month == 12) {
            option = December;
        }
        else {
            cout << "Enter Correct Month !!";
        }

        switch (option){
             case LongMonths:
                 if (1 <= day && day<= 30) {
                     cout << day + 1 << "/" << month << "/" << year;
                 }
                 else {
                     day = 1;
                     cout << day << "/" << month + 1 << "/" << year;
                 }
                 break;
            
             case ShortMonths:
                 if (1 <= day && day <= 29) {
                     cout << day + 1 << "/" << month << "/" << year;
                 }
                 else {
                     day = 1;
                     cout << day << "/" << month + 1 << "/" << year;
                 }
                 break;
            
             case February:
                 if (year % 4 == 0) {
                     if (1 <= day && day <= 28) {
                         cout << day + 1 << "/" << month << "/" << year;
                     }
                     else if(day == 29){
                         day = 1;
                         cout << day << "/" << month + 1 << "/" << year;
                     }
                     else {
                         cout << "The February has 29 days in " << year << "!!";
                     }
                 }
                 else {
                     if (1 <= day && day <= 27) {
                         cout << day + 1 << "/" << month << "/" << year;
                     }
                     else if (day == 28) {
                         day = 1;
                         cout << day << "/" << month + 1 << "/" << year;
                     }
                     else {
                         cout << "The February has 28 days in "<< year <<"!!";
                     }
                 }
                 break;
            
             case December:
                 if (1 <= day && day <= 30) {
                     cout << day + 1 << "/" << month << "/" << year;
                 }
                 else {
                     day = 1;
                     month = 1;
                     cout << day << "/" << month << "/" << year+1;
                 }
                 break;
             default:
            
                 break;
             }
            
    }
    

}

