#include <iostream>
#include<iomanip>
using namespace std;

void main()
{


#pragma region Task 1

    // 1. 5x5 ölçüsündə ikiölçülü massivi 0-20 aralığında random ədədlərlə
    // doldurun. Massivdəki ədədlərin cəmini tapın.
   
    /*
    srand(time(NULL));
    const int size1 = 5;
    int numbers[size1][size1],max=20,min=0;

    for (int i = 0; i < size1; i++)
    {
        for (int k = 0; k < size1; k++)
        {
            numbers[i][k] = rand() % (max - min + 1) + min;
        }
    }
    
    int sum=0;
    
    for (int i = 0; i < size1; i++)
    {
        for (int k = 0; k < size1; k++)
        {
            sum+=numbers[i][k];
        }
    }

    for (int i = 0; i < size1; i++)
    {
        for (int k = 0; k < size1; k++)
        {
            cout << setw(4)<< numbers[i][k] << "  ";
        }
        cout << endl << endl;
    }

    cout << endl << "The Sum of The Elements is " << sum << " .\n";
    */
    
#pragma endregion




#pragma region Task 2

    // 2. 5x5 ölçüsündə ikiölçülü massivi 0-20 aralığında random ədədlərlə
    // doldurun. Əsas və əks dioqanalda yerləşən rəqəmlərin cəmini hesablayan program yazın.

    /*
    srand(time(NULL));
    const int size1 = 5;
    int numbers[size1][size1],max=20,min=0;

    for (int i = 0; i < size1; i++)
    {
        for (int k = 0; k < size1; k++)
        {
            numbers[i][k] = rand() % (max - min + 1) + min;
        }
    }

    int sum1=0;

    for (int i = 0; i < size1; i++)
    {
        for (int k = 0; k < size1; k++)
        {
            if (i == k || i + k == size1 - 1) {
                sum1 += numbers[i][k];
            }
        }
    }

    for (int i = 0; i < size1; i++)
    {
        for (int k = 0; k < size1; k++)
        {
            cout << setw(4)<< numbers[i][k] << "  ";
        }
        cout << endl << endl;
    }

    cout << endl << "The Sum of The Dioganal Elements is " << sum1 << " .\n";
    */

#pragma endregion




#pragma region Task 3

    // 3. 5x5 ölçüsündə ikiölçülü massivi (-100) və (100) aralığında random
    // ədədlərlə doldurun. Massivdəki minimal və maksimal elementləri tapan program yazın.

    /*
    srand(time(NULL));
    const int size1 = 5;
    int numbers[size1][size1],max=100,min=-100;

    for (int i = 0; i < size1; i++)
    {
        for (int k = 0; k < size1; k++)
        {
            numbers[i][k] = rand() % (max - min + 1) + min;
        }
    }

    int minEl=0,maxEl=0;

    for (int i = 0; i < size1; i++)
    {
        for (int k = 0; k < size1; k++)
        {
            if (maxEl < numbers[i][k]) {
                maxEl = numbers[i][k];
            }
            if (minEl > numbers[i][k]) {
                minEl = numbers[i][k];
            }
        }
    }

    for (int i = 0; i < size1; i++)
    {
        for (int k = 0; k < size1; k++)
        {
            cout << setw(4)<< numbers[i][k] << "  ";
        }
        cout << endl << endl;
    }

    cout << endl << "The Maximal Element is " << maxEl << " .\n";
    cout << "The Minimal Element is " << minEl << " .\n";
    */

#pragma endregion




#pragma region Task 4

    // 4. 5x5 ölçüsündə ikiölçülü massivi -5 və 5 aralığında random ədədlərlə
    // doldurun. Massivdəki mənfi, müsbət, və sıfır olan elementlərin sayını tapın.

    /*
    srand(time(NULL));
    const int size1 = 5;
    int numbers[size1][size1],max=5,min=-5;

    for (int i = 0; i < size1; i++)
    {
        for (int k = 0; k < size1; k++)
        {
            numbers[i][k] = rand() % (max - min + 1) + min;
        }
    }

    int countNeg=0,countPos=0,countZero=0;

    for (int i = 0; i < size1; i++)
    {
        for (int k = 0; k < size1; k++)
        {
            if (numbers[i][k] > 0) {
                countPos ++ ;
            }
            else if (numbers[i][k] < 0) {
                countNeg++;
            }
            else {
                countZero++;
            }
        }
    }

    for (int i = 0; i < size1; i++)
    {
        for (int k = 0; k < size1; k++)
        {
            cout << setw(4)<< numbers[i][k] << "  ";
        }
        cout << endl << endl;
    }

    cout << endl << "The Count of The Positive Elements is " << countPos << " .\n";
    cout << endl << "The Count of The Negative Elements is " << countNeg << " .\n";
    cout << endl << "The Count of Zero is " << countZero << " .\n";
    */

#pragma endregion




#pragma region Task 5

    // 5. 5x5 ölçüsündə ikiölçülü massivi 0-20 aralığında random ədədlərlə
    // doldurun. Hər bir sətirdəki elementlərin cəmini tapın.

    /*
    srand(time(NULL));
    const int size1 = 5;
    int numbers[size1][size1],max=20,min=0;


    for (int i = 0; i < size1; i++)
    {
        for (int k = 0; k < size1; k++)
        {
            numbers[i][k] = rand() % (max - min + 1) + min;
        }
    }

    cout << "\nArray:\n\n";

    for (int i = 0; i < size1; i++)
    {
        for (int k = 0; k < size1; k++)
        {
            cout << setw(4)<< numbers[i][k] << "  ";
        }
        cout << endl << endl;
    }

    cout << "\n\n\n";

    int sum2=0;
    int numbers2[size1][1];

    for (int i = 0; i < size1; i++)
    {
        sum2 = 0;
        for (int k = 0; k < size1; k++)
        {
            sum2 += numbers[i][k];
        }
        numbers2[0][i] = sum2;
    }

    cout << "Sum Array:\n\n";

    for (int i = 0; i < size1; i++)
    {
        for (int k = 0; k < 1; k++)
        {
            cout << "  " << numbers2[i][k] << "  ";
        }
        cout << endl << endl;
    }
    */

#pragma endregion




#pragma region Task 6

    // 6. 5x5 ölçüsündə ikiölçülü massivi 0-20 aralığında random ədədlərlə
    // doldurun. Hər bir sütundakı elementlərin cəmini tapın.

    /*
    srand(time(NULL));
    const int size1 = 5;
    int numbers[size1][size1],max=20,min=0;

    for (int i = 0; i < size1; i++)
    {
        for (int k = 0; k < size1; k++)
        {
            numbers[i][k] = rand() % (max - min + 1) + min;
        }
    }


    for (int i = 0; i < size1; i++)
    {
        for (int k = 0; k < size1; k++)
        {
            cout << setw(4)<< numbers[i][k] << "  ";
        }
        cout << endl << endl;
    }

    int sum3=0;

    for (int k = 0; k < size1; k++)
    {
        sum3 = 0;
        for (int i = 0; i < size1; i++)
        {
            sum3 += numbers[i][k];
        }
        cout << "The Sum of The " << k + 1 << " column is " << sum3 << endl;
    }
    */

#pragma endregion




#pragma region Task 7

    // 7. 5x5 ölçüsündə ikiölçülü massivi -10 və 40 aralığında random
    // ədədlərlə doldurun. Bütün sətirdə mənfi ədəd yoxdursa, bu sətirin cəmini toplayın.

    /*
    srand(time(NULL));
    const int size1 = 5;
    int numbers[size1][size1],max=40,min=-10;

    for (int i = 0; i < size1; i++)
    {
        for (int k = 0; k < size1; k++)
        {
            numbers[i][k] = rand() % (max - min + 1) + min;
        }
    }


    for (int i = 0; i < size1; i++)
    {
        for (int k = 0; k < size1; k++)
        {
            cout << setw(4)<< numbers[i][k] << "  ";
        }
        cout << endl << endl;
    }

    int sum4=0,counter=0,negativeNum=0;

    for (int i = 0; i < size1; i++)
    {
        sum4 = 0,counter=0,negativeNum=0;
        for (int k = 0; k < size1; k++)
        {
            if (numbers[i][k]<0)
            {
                counter++;                                         // Çap ücün ayrı 'for'-da yazsam, hər sətir bitəndə çap edə bilməyəcəkdim.                    
                negativeNum = numbers[i][k];                       // Ona görə eyni 'for' daxilində yazdım.(Mənfi ədədi çap edə bilmək üçün)
            }
            else {
                sum4 += numbers[i][k];
            }
        }

        if (counter == 0)
        {
            cout << "The Sum of The Elements in Row No" << i + 1 << " is " << sum4 << endl;
        }
        else {
            cout << "There's Negative Number in Row No" << i + 1 << " , The Number is " << negativeNum << endl;
        }
    }
    */

#pragma endregion




#pragma region Task 8

    // 8. N x M ölçülü massivi elə ikirəqəmli ədədlərlə doldurun ki , birinci
    // rəqəm sətirin, ikinci rəqəm sütun nömrəsini göstərsin.

    /*
    const int columnSize = 3, rowSize = 4;
    int numbers[columnSize][rowSize];


    for (int i = 1; i <= columnSize; i++)
    {
        for (int k = 1; k <= rowSize; k++)
        {
            cout << setw(4) << i << k << " ";
        }
        cout << endl << endl;

    }
    */

#pragma endregion




#pragma region Task 9

    // 9. N x M ölçülü massivdə, birinci və sonuncu sütunun, ikinci və sondan
    // əvvəlki sütunun və s.yerini dəyişin.

    /*
    srand(time(NULL));
    const int columnSize = 6, rowSize = 6;
    int numbers[columnSize][rowSize];
    int numbers2[columnSize][rowSize], max = 100, min = 0;

    for (int i = 0; i < columnSize; i++)
    {
        for (int k = 0; k < rowSize; k++)
        {
            numbers[i][k] = rand() % (max - min + 1) + min;
        }
    }

    cout << "\n  Before\n\n";

    for (int i = 0; i < columnSize; i++)
    {
        for (int k = 0; k < rowSize; k++)
        {
            cout << setw(4)<< numbers[i][k] << "  ";
        }
        cout << endl << endl;
    }

    for (int i = 0; i < columnSize; i++)
    {
        for (int k = 0; k < rowSize; k++)
        {
            numbers2[i][rowSize-1-k] = numbers[i][k];
        }
    }
    
    cout << "\n\n  After\n\n";

    for (int i = 0; i < columnSize; i++)
    {
        for (int k = 0; k < rowSize; k++)
        {
            cout << setw(4) << numbers2[i][k] << "  ";
        }
        cout << endl << endl;
    }
    */

#pragma endregion




#pragma region Task 10

    // 10. 6 x 6 ölçülü massivdə , qonşu sətirlərin yerini dəyişin.

    /*
    srand(time(NULL));
    const int columnSize = 6, rowSize = 6;
    int numbers[columnSize][rowSize];
    int numbers2[columnSize][rowSize]{}, max = 100, min = 1;

    for (int i = 0; i < columnSize; i++)
    {
        for (int k = 0; k < rowSize; k++)
        {
            numbers[i][k] = rand() % (max - min + 1) + min;
        }
    }

    cout << "\n  Before\n\n";

    for (int i = 0; i < columnSize; i++)
    {
        for (int k = 0; k < rowSize; k++)
        {
            cout << setw(4)<< numbers[i][k] << "  ";
        }
        cout << endl << endl;
    }

    for (int i = 1; i < columnSize; i=i+2)
    {
        for (int k = 0; k < rowSize ; k++)
        {
            numbers2[i][k] = numbers[i][k];
        }
    }

    //cout << "\n\n";

    //for (int i = 0; i < columnSize; i++)
    //{
    //    for (int k = 0; k < rowSize; k++)
    //    {
    //        cout<<setw(4)<<numbers2[i][k]<<"  ";
    //    }
    //    cout << endl<<endl;
    //}

    for (int i = 1; i < columnSize; i=i+2)
    {
        for (int k = 0; k < rowSize; k++)
        {
            numbers[i][k] = numbers[i-1][k];
            numbers[i - 1][k] = numbers2[i][k];
        }
    }

    cout << "\n\n  After\n\n";


    for (int i = 0; i < columnSize; i++)
    {
        for (int k = 0; k < rowSize; k++)
        {
            cout << setw(4) << numbers[i][k] << "  ";
        }
        cout << endl << endl;
    }
    */

#pragma endregion




}


