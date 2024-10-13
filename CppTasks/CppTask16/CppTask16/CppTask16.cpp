#include<iostream>
#include<iomanip>
#include<string>
#include<chrono>
#include<thread>
using namespace std;

class User
{
private:

	int userId;
	static int id;
	string fullname;
	string mail;
	int age;
	double height;

public:


	User(string fullname, string mail, int age, double height)
	{
		userId = ++id;
		this->fullname = fullname;
		this->mail = mail;
		this->age = age;
		this->height = height;
	}

	int getUserId() const
	{
		return userId;
	}

	string getFullName() const
	{
		return fullname;
	}

	string getMail() const
	{
		return mail;
	}

	int getAge() const
	{
		return age;
	}

	double getHeight() const
	{
		return userId;
	}



	void setFullName(string& fullname)
	{
		while (fullname.length() < 6)
		{
			cout << "The Fullname should be longer than you entered.\n\nNew Fullname:";
			cin >> fullname;
		}

		this->fullname = fullname;
	}

	void setMail(string& mail)
	{
		while (mail.length() < 6)
		{
			cout << "The Mail should be longer than you entered.\n\nNew Mail:";
			cin >> mail;
		}

		this->mail = mail;
	}

	void setAge(int& age)
	{
		while (age < 8)
		{
			cout << "Your Age should be more than you entered.\n\nNew Age:";
			cin >> age;
		}

		this->age = age;
	}

	void setHeight(double& height)
	{
		while (height < 0)
		{
			cout << "Your Height should be more than you entered.\n\nNew Height:";
			cin >> height;
		}

		this->height = height;
	}

	void ShowUser() 
	{
		cout << "|" << setw(12) << "Id : " << userId << endl;
		cout << "|" << setw(12) << "Fullname : " << fullname << endl;
		cout << "|" << setw(12) << "Mail : " << mail << endl;
		cout << "|" << setw(12) << "Age : " << age << endl;
		cout << "|" << setw(12) << "Height : " << height << endl;
		cout << setw(10) << "--------------------------------\n\n";
	}

};


void ShowAllUsers(User**& users, int& size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (users[i] == nullptr)
		{
			continue;
		}

		cout << "-------------< " << i + 1 << " >--------------\n";
		users[i]->ShowUser();
	}
}


void SearchUser(User**& users, int& id)
{
	cout << "\n-------------< " << id << " >--------------\n";
	users[id - 1]->ShowUser();
}


void DeleteUser(User**& users, int& id)
{
	delete users[id - 1];
	users[id - 1] = nullptr;

	cout << "\nProduct " << id << " was successfully deleted.\n\n";
}


void DeleteAllUsers(User**& users, int& size)
{
	for (size_t i = 0; i < size; i++)
	{
		delete users[i];
		users[i] = nullptr;
	}

	delete[] users;
	users = nullptr;
}


void CreateUser(User**& users, int& size, string& fullname, string& mail, int& age, double& height)
{
	User* newUser = new User{ fullname, mail, age, height };

	newUser->setFullName(fullname);
	newUser->setMail(mail);
	newUser->setAge(age);
	newUser->setHeight(height);

	size += 1;

	User** newUsers = new User * [size] {};

	for (int i = 0; i < size; i++)
	{
		newUsers[i] = users[i];
	}

	newUsers[size - 1] = newUser;

	delete[] users;

	users = newUsers;
}

int User::id = 0;

void main()
{
	string fullname, mail;
	int size = 5, age, searchId, deleteId, updateId, choice, choice2;
	double height;

	User* user1 = new User{ "Tunay Huseynli", "tunayhus@gmail.com", 20, 1.76 };
	User* user2 = new User{ "Remzi Hesenov", "remzihes@gmail.com", 19, 1.75 };
	User* user3 = new User{ "Ilkin Recebov", "ilkinrec@gmail.com", 20, 1.82 };
	User* user4 = new User{ "Kerem Memmedli", "Keremmem@gmail.com", 20, 1.83 };
	User* user5 = new User{ "Xeyal Sadiqov", "xeyalsad@gmail.com", 20, 1.76 };

	User** users = new User * [size] {user1, user2, user3, user4, user5};


	while (true)
	{
		system("cls");

		cout << "\n==============================================\n\n1) Show All Users \n2) Search User \n3) Create User \n4) Update User \n5) Delete User \n6) Delete All Users \n7) Exit \n\nChoice: ";
		cin >> choice;
		cout << endl;


		if (choice == 1)
		{
			ShowAllUsers(users, size);
		}

		else if (choice == 2)
		{
			cout << "Enter Id: ";
			cin >> searchId;

			while (searchId < 0 || searchId > size)
			{
				cout << "\nId was not found.\n\nNew Id: ";
				cin >> searchId;
				cout << endl;
			}

			SearchUser(users, searchId);
		}

		else if (choice == 3)
		{
			cin.ignore();

			cout << "\nEnter Fullname: ";
			getline(cin, fullname);

			cout << "\nEnter Mail: ";
			cin >> mail;

			cout << "\nEnter Age: ";
			cin >> age;

			cout << "\nEnter Height: ";
			cin >> height;

			cout << endl;

			CreateUser(users, size, fullname, mail, age, height);
		}

		else if (choice == 4)
		{
			string newFullname, newMail;
			int newAge;
			double newHeight;

			cout << "Enter Id: ";
			cin >> updateId;

			while (updateId < 0 || updateId > size)
			{
				cout << "\nId was not found.\n\nNew Id: ";
				cin >> updateId;
				cout << endl;
			}

			cout << "\nWhat do you want to update ?\n\n1) Fullname \n2) Mail \n3) Age \n4) Height \n\nChoice: ";
			cin >> choice2;

			switch (choice2)
			{
			case 1:
				cin.ignore();

				cout << "\nEnter Fullname: ";
				getline(cin, newFullname);

				users[updateId - 1]->setFullName(newFullname);
				break;

			case 2:
				cout << "\nEnter New Mail: ";
				cin >> newMail;
				
				users[updateId - 1]->setMail(newMail);
				break;

			case 3:
				cout << "\nEnter New Age: ";
				cin >> newAge;
				
				users[updateId - 1]->setAge(newAge);
				break;

			case 4:
				cout << "\nEnter New Height: ";
				cin >> newHeight;
				
				users[updateId - 1]->setHeight(newHeight);
				break;

			default:
				
				cout << "Enter Correct Field !!";
				break;
			}

			cout << "\n\nField Successfully Changed.\n";
		}

		else if (choice == 5)
		{
			cout << "Enter Id: ";
			cin >> deleteId;
			while (deleteId < 0 || deleteId > size)
			{
				cout << "\nId was not found.\n\nNew Id: ";
				cin >> deleteId;
				cout << endl;
			}
			DeleteUser(users, deleteId);
		}

		else if (choice == 6)
		{
			cout << "All Users was successfully deleted.\n";
			break;
		}

		else if (choice == 7)
		{
			break;
		}

		else
		{
			cout << "\n\nEnter Correct Choise !! \n\n";
		}

		this_thread::sleep_for(chrono::seconds(5));		// Ekranda qalmaq saniyesi 
	}

	DeleteAllUsers(users, size);
}