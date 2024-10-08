#include<iostream>
#include<iomanip>
using namespace std;


#pragma region Task

// Library database - dən Update, Delete funksiyasını yazın.

// Qeyd: Drive-dakı kod yox en basşdan özüm yazmışam ona görə fərqlidir kod(Library əvəzinə Books).

#pragma endregion


struct Book
{
	char* name;
	char* category;
	char* author;
	int page;
};


void CreateBook(Book**& books, int& size)
{
	char* bookName = new char[20] {};
	char* bookCategory = new char[20] {};
	char* authorName = new char[20] {};
	int page = 0;

	cin.ignore();

	cout << "\033[33m" << "Enter Book Name: " << "\033[0m";
	cin.getline(*(&bookName), 20, '$');

	cin.ignore();

	cout << "\033[33m" << "\nEnter Book Category: " << "\033[0m";
	cin.getline(*(&bookCategory), 20, '$');

	cin.ignore();

	cout << "\033[33m" << "\nEnter Author Name: " << "\033[0m";
	cin.getline(*(&authorName), 20, '$');

	cin.ignore();

	cout << "\033[33m" << "\nEnter Page Count: " << "\033[0m";
	cin >> page;

	size += 1;
	Book* book = new Book[4]{ bookName,bookCategory,authorName,page };

	books[size - 1] = book;

	cout << "\nYour Product Successfully Added.\n\n";

}

void UpdateBook(Book**& books, int number2)
{
	char* bookName = new char[20] {};
	char* bookCategory = new char[20] {};
	char* authorName = new char[20] {};
	int page = 0, choice;

	cout << "\nEdit what?\n\n1) Book Name \n2) Book Category \n3) Author Name \n4) Page Count\n\nChoice: ";
	cin >> choice;
	

	cin.ignore();

	if (choice == 1)
	{
		cout << "\033[33m" << "\nEnter Book Name: " << "\033[0m";
		cin.getline(*(&bookName), 20, '$');
		cin.ignore();
		books[number2 - 1]->name = bookName;
	}

	else if (choice == 2)
	{
		cout << "\033[33m" << "\nEnter Book Category: " << "\033[0m";
		cin.getline(*(&bookCategory), 20, '$');
		cin.ignore();
		books[number2 - 1]->category = bookCategory;
	}

	else if (choice == 3)
	{
		cout << "\033[33m" << "\nEnter Author Name: " << "\033[0m";
		cin.getline(*(&authorName), 20, '$');
		cin.ignore();
		books[number2 - 1]->author = authorName;
	}

	else if (choice == 4)
	{
		cout << "\033[33m" << "\nEnter Page Count: " << "\033[0m";
		cin >> page;
		books[number2 - 1]->page = page;
	}

	else {
		cout << "Enter The Correct Choice !!";
	}

	cout << endl;

}

void ShowAllBook(Book**& books, int& size)
{
	for (int i = 0; i < size; i++)
	{
		if (books[i] == nullptr)
		{
			continue;
		}

		cout << "\033[35m" << "-------------{ " << "\033[32m" << "Product No " << i + 1 << ". " << "\033[35m" << "}------------\n\n";
		cout << setw(10) << "\033[33m" << "Name: " << "\033[0m" << books[i]->name << endl;
		cout << setw(10) << "\033[33m" << "Category: " << "\033[0m" << books[i]->category << endl;
		cout << setw(10) << "\033[33m" << "Author: " << "\033[0m" << books[i]->author << endl;
		cout << setw(10) << "\033[33m" << "Page: " << "\033[0m" << books[i]->page << endl << endl;
	}
}


int& SearchBook(Book**& books, int& size, int& bookCode)
{
	bool isFound = false;

	for (int i = 0; i < size; i++)
	{
		if (i + 1 == bookCode)
		{
			cout << "\033[35m" << "-------------{ " << "\033[32m" << "Product No " << i + 1 << ". " << "\033[35m" << "}------------\n\n";
			cout << setw(10) << "\033[33m" << "Name: " << "\033[0m" << books[i]->name << endl;
			cout << setw(10) << "\033[33m" << "Category: " << "\033[0m" << books[i]->category << endl;
			cout << setw(10) << "\033[33m" << "Author: " << "\033[0m" << books[i]->author << endl;
			cout << setw(10) << "\033[33m" << "Page: " << "\033[0m" << books[i]->page << endl << endl;

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
	int size = 4, bookCode, choice, choice2, number, number2;


	Book** books = new Book * [size] {
		new Book{ new char[20] {"Gorunmeyen Izler"}, new char[20] {"Detective"}, new char[20] {"Elxan Elatli"}, 282 },
			new Book{ new char[20] {"Cirtdan Ve Div"}, new char[20] {"Tale"}, new char[20] {"Nicat Eliyev"}, 27 },
			new Book{ new char[20] {"Balkan Sindromu"}, new char[20] {"Detective"}, new char[20] {"Cingiz Abdullayev"}, 305 },
			new Book{ new char[20] {"Baliqci Ve Deniz"}, new char[20] {"Adventure"}, new char[20] {"Ernest Heminquey"}, 241 },
		};

	while (true)
	{
		cout << "==============================================\n\n1) Show All Books \n2) Search Book \n3) Delete Book \n4) Delete All Books\n5) Create Book \n6) Update Book \n\nChoice: ";
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

		else if (choice == 5)
		{
			CreateBook(books, size);
		}

		else if (choice == 6)
		{
			cout << "Enter The Number of The Product that you want to update: ";
			cin >> number2;
			if (number2<1 || number2>size)
			{
				cout << "\033[31m" << "\nProduct " << number2 << " doesn't exsist.\n\n" << "\033[0m";
			}
			else
			{
				UpdateBook(books, number2);
			}
		}

		else
		{
			cout << "Please Enter Valid Choice.\n\n";
		}
	}
}

