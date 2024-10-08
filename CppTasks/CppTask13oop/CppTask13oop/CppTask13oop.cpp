#include<iostream>
#include<iomanip>
using namespace std;


#pragma region Task

// Book struct yaradin. Duzgun sira ile qurun, azi 4 atributu olsun. Heapde massive yigirsiniz.
// void Show_All_Book(Book * *&books, int& size)
// int& Search_Book(Book * *&books, int& size, int& book_code) index qaytaracaq
// void Delete_Book(Book * *&books, int& size, int& book_code

#pragma endregion


struct Book
{
	char* name;
	char* category;
	char* author;
	int page;
};

void ShowAllBook(Book**& books, int& size)
{
	for (int i = 0; i < size; i++)
	{
		if (books[i] == nullptr)
		{
			continue;
		}

		cout << "-------------{Product No " << i + 1 << ".}-------------\n\n";
		cout << setw(10) << "Name: " << books[i]->name << endl;
		cout << setw(10) << "Category: " << books[i]->category << endl;
		cout << setw(10) << "Author: " << books[i]->author << endl;
		cout << setw(10) << "Page: " << books[i]->page << endl << endl;
	}
}


int& SearchBook(Book**& books, int& size, int& bookCode)
{
	bool isFound = false;

	for (int i = 0; i < size; i++)
	{
		if (i + 1 == bookCode)
		{
			cout << "-------------{Product No " << i + 1 << ".}-------------\n\n";
			cout << setw(10) << "Name: " << books[i]->name << endl;
			cout << setw(10) << "Category: " << books[i]->category << endl;
			cout << setw(10) << "Author: " << books[i]->author << endl;
			cout << setw(10) << "Page: " << books[i]->page << endl << endl;

			isFound = true;

			return bookCode;
		}
	}

	if (!isFound)
	{
		cout << "\nThe book you've searched was not found.\n\n";

		bookCode = 0;

		return bookCode;
	}

}


void DeleteBook(Book**& books, int& bookCode)
{
	delete[] books[bookCode - 1]->name;
	delete[] books[bookCode - 1]->category;
	delete[] books[bookCode - 1]->author;
	delete[] books[bookCode - 1];

	books[bookCode - 1] = nullptr;

	cout << "\nBook deleted successfully.\n\n";
}


void DeleteAllBooks(Book**& books, int& size)
{
	for (int i = 0; i < size; i++)
	{
		if (books[i] != nullptr)
		{
			delete books[i]->name;
			delete books[i]->category;
			delete books[i]->author;
			delete[] books[i];
		}
	}

	delete[] books;

	books = nullptr;

	cout << "All books was deleted.\n";
}

void main()
{
	int size = 4, bookCode, choice, choice2, number;


	Book** books = new Book * [size] {
		new Book{ new char[20] {"Gorunmeyen Izler"}, new char[20] {"Detective"}, new char[20] {"Elxan Elatli"}, 282 },
			new Book{ new char[20] {"Cirtdan Ve Div"}, new char[20] {"Tale"}, new char[20] {"Nicat Eliyev"}, 27 },
			new Book{ new char[20] {"Balkan Sindromu"}, new char[20] {"Detective"}, new char[20] {"Cingiz Abdullayev"}, 305 },
			new Book{ new char[20] {"Baliqci Ve Deniz"}, new char[20] {"Adventure"}, new char[20] {"Ernest Heminquey"}, 241 },
		};

	while (true)
	{
		cout << "==============================================\n\n1) Show All Books \n2) Search Book \n3) Delete Book \n4) Delete All Book \n\nChoice: ";
		cin >> choice;
		cout << endl << endl;

		if (choice == 1)
		{
			ShowAllBook(books, size);
		}

		else if (choice == 2)
		{
			cout << "Please Enter Some Book Code: ";
			cin >> bookCode;
			cout << endl;

			bookCode = SearchBook(books, size, bookCode);

			if (bookCode != 0)
			{
				cout << "Do you want to delete this book? (1 => Yes , 0 => No)\n\nYour Choice: ";
				cin >> choice2;

				if (choice2)
				{
					DeleteBook(books, bookCode);
				}
				cout << endl;
			}
		}

		else if (choice == 3)
		{
			cout << "Enter Book Code: ";
			cin >> number;

			DeleteBook(books, number);
		}

		else if (choice == 4)
		{
			DeleteAllBooks(books, size);

			break;
		}

		else
		{
			cout << "Please Enter Valid Choice.\n\n";
		}
	}
}

