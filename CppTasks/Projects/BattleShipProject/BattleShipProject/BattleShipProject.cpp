#include<iostream>
#include<iomanip>
using namespace std;



int& RandomCoordinate()
{
	int min = 0, max = 9;
	int randNum = min + rand() % (max - min + 1);

	return randNum;
}

bool CheckShipsBorder(int**& array, int& randY, int& randX, int& size, bool& randomBool)
{
	int borderLeft = 0, borderUp = 0, borderRight = 0, borderDown = 0;

	if (randX + size > 10 && randY + size > 10)
	{
		return false;
	}

	if ((randX + size > 10 && !randomBool) || (randY + size > 10 && randomBool))
	{
		if (randomBool == true)
		{
			randomBool = false;
		}

		else
		{
			randomBool = true;
		}
	}

	if ((randX == 9 && randomBool) || (randX + size > 9 && !randomBool))
	{
		borderRight = 1;
	}

	if ((randY == 9 && !randomBool) || (randY + size > 9 && randomBool))
	{
		borderDown = 1;
	}

	if (randY == 0)
	{
		borderUp = 1;
	}
	if (randX == 0)
	{
		borderLeft = 1;
	}

	if (randomBool)
	{
		for (int i = randY - 1 + borderUp; i <= randY + size - borderDown; i++)
		{
			for (int j = randX - 1 + borderLeft; j <= randX + 1 - borderRight; j++)
			{
				if (array[i][j] == 2)
				{																// Vertical Checking
					randomBool = false;
					return false;
				}
			}
		}

		return true;
	}

	if (!randomBool)
	{
		for (int i = randY - 1 + borderUp; i <= randY + 1 - borderDown; i++)
		{
			for (int j = randX - 1 + borderLeft; j <= randX + size - borderRight; j++)
			{
				if (array[i][j] == 2)
				{																 // Horizontal Checking
					randomBool = true;
					return false;
				}
			}
		}

		return true;
	}

}



void CreateShipsBorder(int**& array, int& randY, int& randX, int& size, int randomBool)
{
	int borderLeft = 0, borderUp = 0, borderRight = 0, borderDown = 0;

	if ((randX == 9 && randomBool) || (randX + size > 9 && !randomBool))
	{
		borderRight = 1;
	}

	if ((randY == 9 && !randomBool) || (randY + size > 9 && randomBool))
	{
		borderDown = 1;
	}

	if (randX == 0)
	{
		borderLeft = 1;
	}

	if (randY == 0)
	{
		borderUp = 1;
	}

	if (randomBool)
	{
		for (int i = randY - 1 + borderUp; i <= randY + size - borderDown; i++)
		{
			for (int j = randX - 1 + borderLeft; j <= randX + 1 - borderRight; j++)
			{
				if (array[i][j] == 0 || array[i][j] == 4)							 // Vertical Locating Bombs	
				{
					array[i][j] = 5;
				}
			}
		}
	}

	else
	{
		for (int i = randY - 1 + borderUp; i <= randY + 1 - borderDown; i++)
		{
			for (int j = randX - 1 + borderLeft; j <= randX + size - borderRight; j++)
			{
				if (array[i][j] == 0 || array[i][j] == 4)							  // Horizontal Locating Bombs
				{
					array[i][j] = 5;
				}
			}
		}
	}
}

int**& LocateShips(int**& array, int**& arrayShips)
{
	int size = 4;
	int countMove = 0;
	int attempsFailed = 0;

	while (countMove < 10 && attempsFailed < 100)
	{
		bool randomBool = rand() % 2;
		int randX = RandomCoordinate();
		int randY = RandomCoordinate();

		bool isChecked = CheckShipsBorder(array, randY, randX, size, randomBool);
		if (isChecked == false)
		{
			isChecked = CheckShipsBorder(array, randY, randX, size, randomBool);
		}

		if (!isChecked)
		{
			attempsFailed++;
			continue;
		}

		else
		{
			arrayShips[countMove][0] = randY;
			arrayShips[countMove][1] = randX;
			arrayShips[countMove][2] = size;
			arrayShips[countMove][3] = randomBool;

			if (randomBool)					// Vertical Ordering
			{
				for (int i = randY; i < randY + size; i++)
				{
					array[i][randX] = 2;
				}
			}
			else						     // Horizontal Ordering
			{
				for (int j = randX; j < randX + size; j++)
				{
					array[randY][j] = 2;
				}
			}

			if (countMove == 0 || countMove == 2 || countMove == 5)
			{
				size--;
			}

			countMove++;
			attempsFailed = 0;
		}
	}

	return array;
}

void LocateBombs(int**& array, int coordinateY, int coordinateX)
{
	int borderLeft = 0, borderUp = 0, borderRight = 0, borderDown = 0;


	if (coordinateX == 9)
	{
		borderRight = 2;
	}

	if (coordinateY == 9)
	{
		borderDown = 2;
	}

	if (coordinateX == 0)
	{
		borderLeft = 2;
	}

	if (coordinateY == 0)
	{
		borderUp = 2;
	}

	for (int i = coordinateY - 1 + borderUp; i <= coordinateY + 1 - borderDown; i += 2)
	{
		for (int j = coordinateX - 1 + borderLeft; j <= coordinateX + 1 - borderRight; j += 2)			// Only Diagonal Locating Bombs
		{
			array[i][j] = 5;
		}

	}
}

void BotTurn(int**& array, int& botShotCounter, int**& arrayShips)
{
	int isShootedX = RandomCoordinate(), isShootedY = RandomCoordinate();
	bool randomBoolCopy;
	bool returnCheck;

	cout << "Opponenet's Turn(Player 2)";

	while (array[isShootedY][isShootedX] == 3 || array[isShootedY][isShootedX] == 4 || array[isShootedY][isShootedX] == 5)
	{
		isShootedY = RandomCoordinate();
		isShootedX = RandomCoordinate();
	}

	if (array[isShootedY][isShootedX] == 2)
	{
		array[isShootedY][isShootedX] += 1;
		botShotCounter++;

		cout << "\n\nYour Ship was Heat.\n\n";

		LocateBombs(array, isShootedY, isShootedX);

		for (int i = 0; i < 10; i++)
		{
			randomBoolCopy = bool(arrayShips[i][3]);
			returnCheck = CheckShipsBorder(array, arrayShips[i][0], arrayShips[i][1], arrayShips[i][2], randomBoolCopy);

			if (returnCheck)
			{																														// The Border Bomb Testing of The Bot's Grid
				CreateShipsBorder(array, arrayShips[i][0], arrayShips[i][1], arrayShips[i][2], arrayShips[i][3]);
			}
		}

		BotTurn(array, botShotCounter, arrayShips);
	}

	else
	{
		array[isShootedY][isShootedX] = 4;
	}
}

bool UserTurn(int**& array2, int& userShotCounter, int**& arrayShips2)
{
	int shootX;
	int shootY;
	bool randomBoolCopy = false;
	bool returnCheck = false;

	cout << "\n*Your Turn(Player 1)*\n\nThe Coordinate that you want to heat (Between 0 and 9).\n\nY (Row): ";
	cin >> shootY;
	cout << "\nX (Column): ";
	cin >> shootX;

	while ((int(shootX) < 0 || int(shootX) > 9) || (int(shootY) < 0 || int(shootY) > 9) || (array2[shootY][shootX] == 3 || array2[shootY][shootX] == 4 || array2[shootY][shootX] == 5))
	{
		cout << "\n\n---#{" << "\033[33m" << "Warning" << "\033[0m" << "}#--- \n\nYou Should Enter the New Coordinate or Enter Correct Numbers !!!!\n\n";

		cout << "The Coordinate that you want to heat.\n\nY (Row): ";
		cin >> shootY;

		cout << "\nX (Column): ";
		cin >> shootX;
	}

	if (array2[shootY][shootX] == 2)
	{
		array2[shootY][shootX] += 1;
		userShotCounter++;

		LocateBombs(array2, shootY, shootX);

		for (int i = 0; i < 10; i++)
		{
			randomBoolCopy = bool(arrayShips2[i][3]);
			returnCheck = CheckShipsBorder(array2, arrayShips2[i][0], arrayShips2[i][1], arrayShips2[i][2], randomBoolCopy);

			if (returnCheck)
			{																																// The Border Bomb Testing of The User's Grid
				CreateShipsBorder(array2, arrayShips2[i][0], arrayShips2[i][1], arrayShips2[i][2], arrayShips2[i][3]);
			}
		}

		return true;
	}

	else
	{
		array2[shootY][shootX] = 4;
	}

	cout << "\n\nAhh You Missed !!\n\n";

	return false;
}

void PrintArray(int**& array, int**& array2)
{
	int element = 0;

	cout << "\n\n		 " << "\033[32m" << "Your Grid:" << "\033[0m" << "							      " << "\033[31m" << " Opponent's Grid:" << "\033[0m" << "\n\n";
	cout << "\033[33m" << "     0   1   2   3   4   5   6   7   8   9\t\t\t\t     0   1   2   3   4   5   6   7   8   9 " << "\033[0m" << "\n  + --- --- --- --- --- --- --- --- --- ---                               + --- --- --- --- --- --- --- --- --- ---  \n";

#pragma region User Grid

	for (int i = 0; i < 10; i++)
	{
		element++;

		cout << "\033[33m" << " " << i << "\033[0m" << "|";
		for (int k = 0; k < 10; k++)
		{
			if (array[i][k] == 2)
			{
				cout << "\033[31m" << setw(4) << " * " << "\033[0m";
			}

			else if (array[i][k] == 4)
			{
				cout << setw(4) << " O ";

			}

			else if (array[i][k] == 3)
			{
				cout << setw(4) << "\033[35m" << "  X " << "\033[0m";

			}

			else if (array[i][k] == 5)
			{
				cout << setw(4) << "\033[33m" << "  ! " << "\033[0m";
			}

			else
			{
				cout << "\033[36m" << setw(4) << " ~ " << "\033[0m";
			}

			/* cout << array[i][k] << "   "; */
		}

#pragma endregion

		cout << "\t   ";

		switch (element)
		{

		case 1:
		{
			cout << "\033[33m" << "1. " << setw(2) << "! " << "\033[0m" << "- Bomb";
			break;
		}

		case 3:
		{
			cout << "\033[35m" << "2." << setw(3) << "X " << "\033[0m" << "- Heat";
			break;
		}

		case 4:
		{
			cout << "\033[36m" << "3." << setw(3) << "~ " << "\033[0m" << "- Water";
			break;
		}

		case 6:
		{
			cout << "\033[31m" << "4." << setw(3) << "* " << "\033[0m" << "- Ship";
			break;
		}

		case 7:
		{
			cout << "\033[35m" << "5." << setw(3) << "? " << "\033[0m" << "- UnDef";
			break;
		}

		case 9:
		{
			cout << setw(2) << "6." << " O " << "- Miss";
			break;
		}

		default:
			cout << "\t ";
			break;
		}

		cout << "\t\t";

#pragma region Bot Grid

		cout << "\033[33m" << " " << i << "\033[0m" << "|";
		for (int j = 0; j < 10; j++)
		{
#pragma region Bot Print Test

			//if (array2[i][j] == 2)
			//{
			//	cout << "\033[31m" << setw(4) << " * " << "\033[0m";
			//}
			// 
			//else
			//{
			//	cout << "\033[34m" << setw(4) << " ~ " << "\033[0m";
			//}

#pragma endregion

			if (array2[i][j] == 4)
			{
				cout << setw(4) << " O ";

			}

			else if (array2[i][j] == 3)
			{
				cout << setw(4) << "\033[31m" << "  X " << "\033[0m";

			}

			else if (array2[i][j] == 5)
			{
				cout << setw(4) << "\033[33m" << "  ! " << "\033[0m";
			}

			else
			{
				cout << setw(4) << "\033[35m" << "  ? " << "\033[0m";
			}
		}

		cout << endl << endl;

	}

#pragma endregion

}


void DeleteArray(int**& array)
{
	for (int i = 0; i < 10; ++i)
	{
		delete[] array[i];
	}
	delete[] array;
}


void main()
{
	srand(time(NULL));

	int** array = new int* [10] {
		new int [10] {}, new int[10] {}, new int[10] {}, new int[10] {}, new int[10] {},
			new int[10] {}, new int[10] {}, new int[10] {}, new int[10] {}, new int[10] {} };

	int** array2 = new int* [10] {
		new int [10] {}, new int[10] {}, new int[10] {}, new int[10] {}, new int[10] {},
			new int[10] {}, new int[10] {}, new int[10] {}, new int[10] {}, new int[10] {} };

	int** arrayShips = new int* [10] {
		new int [4] {}, new int[4] {}, new int[4] {}, new int[4] {}, new int[4] {},
			new int[4] {}, new int[4] {}, new int[4] {}, new int[4] {}, new int[4] {} };

	int** arrayShips2 = new int* [10] {
		new int [4] {}, new int[4] {}, new int[4] {}, new int[4] {}, new int[4] {},
			new int[4] {}, new int[4] {}, new int[4] {}, new int[4] {}, new int[4] {} };

	cout << "\n\n\n";
	array = LocateShips(array, arrayShips);
	array2 = LocateShips(array2, arrayShips2);

	int userShotCounter = 0;
	int botShotCounter = 0;


#pragma region ShipArray Print Test
	//for (int i = 0; i < 10; i++)
	//{
	//	for (int k = 0; k < 4; k++)
	//	{
	//		cout << arrayShips[i][k] << "  ";
	//	}

	//	cout << "     ";

	//	for (int k = 0; k < 4; k++)
	//	{
	//		cout << arrayShips2[i][k] << "  ";
	//	}

	//	cout << endl;

	//}
#pragma endregion


	while (true)
	{
		/*system("cls");*/

		cout << "\t\t\t\t\t               " << "\033[31m" << "/" << "\033[0m" << "\033[34m" << "~~~~" << "\033[0m" << "\033[31m" << "\\" << "\033[0m";
		cout << "\n\t\t\t\t\t \t\t\b\b\b\b\b\b " << "\033[31m" << "< BATTLE" << "\033[0m" << "\033[34m" << "SHIP >	     					" << "\033[0m";
		cout << "\t\t\t\t\t\t\t                                                        " << "\033[31m" << "\\" << "\033[0m" << "\033[34m" << "~~~~" << "\033[0m" << "\033[31m" << "/" << "\033[0m";
		
		PrintArray(array, array2);

		bool isHeat = UserTurn(array2, userShotCounter, arrayShips2);
		PrintArray(array, array2);

		if (userShotCounter == 20)
		{
			cout << "\n\n---#{" << "\033[32m" << "Victory" << "\033[0m" << "}#---\n\nYou Won !! Congratss !!\n\n";
			break;
		}

		if (isHeat)
		{
			cout << "\n\nNice shot!\n\n";
			continue;
		}

		BotTurn(array, botShotCounter, arrayShips);
		PrintArray(array, array2);

		if (botShotCounter == 20)
		{
			cout << "\n\n---#{" << "\033[31m" << "Defeat" << "\033[0m" << "}#---\n\nYou're Defeated !! Computer Won !!\n\n";
			break;
		}

		cout << "\n\nOppenent has Missed !!\n\n";
	
	}

	DeleteArray(array);
	DeleteArray(array2);
	DeleteArray(arrayShips);
	DeleteArray(arrayShips2);

}