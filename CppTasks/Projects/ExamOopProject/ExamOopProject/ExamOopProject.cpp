#include<iostream>
#include<memory>
#include<map>
#include<cstring>
#include<string>
#include<cctype>
#include <vector>
#include <cmath>

using namespace std;


class Question;
class TrueFalseQuestion;
class OpenEndedQuestion;
class FourOptionQuestion;
class Test;
class Category;
class User;
class Database;
class Admin;
class UserManager;
class AdminManager;


class Question
{
protected:

	string statement;
	string answer;

public:

	Question(const string& statement, string answer) :statement(statement), answer(answer)
	{ }

	virtual void ShowQuestion() {};

	virtual bool CheckAnswer(string userAnswer) = 0;

	virtual vector<string>& GetQuestionOptions() {};

	string GetStatement() const
	{
		return statement;
	}

	void SetStatement()
	{
		this->statement = statement;
	}


	string GetAnswer() const
	{
		return answer;
	}

	void SetAnswer()
	{
		this->answer = answer;
	}

};


class TrueFalseQuestion :public Question
{
public:

	TrueFalseQuestion(const string& statement, string answer)
		: Question(statement, answer) {}

	void ShowQuestion() override
	{
		cout << "Question: " << statement << endl;

		cout << "\nA) True \nB) False\n";
	}

	bool CheckAnswer(string userAnswer) override
	{
		if (toupper(userAnswer[0]) == 'A')
		{
			return answer == "True";
		}

		else
		{
			return answer == "False";
		}
	}
};


class OpenEndedQuestion :public Question
{
	string userAnswer;

public:

	OpenEndedQuestion(const string& statement, string answer)
		: Question(statement, answer) {}


	string& GetUserAnswer()
	{
		return userAnswer;
	}

	void SetUserAnswer(string userAnswer)
	{
		while (userAnswer.length() > 20)
		{
			cout << "\nYour Answer's too long.\n";
			cin >> userAnswer;
		}

		this->userAnswer = userAnswer;
	}


	void ShowQuestion() override
	{
		cout << "Question: " << statement << endl << endl;
	}

	bool CheckAnswer(string userAnswer) override
	{
		return userAnswer == answer;
	}

};


class FourOptionQuestion :public Question
{
	vector<string> questionOptions;

	map<char, string> questionOptions2;

public:

	FourOptionQuestion(const string& statement, const string& answer)
		: Question(statement, answer)
	{ }


	vector<string>& GetQuestionOptions() override
	{
		return questionOptions;
	}


	void ShowQuestion() override
	{
		int randIndex = 0;

		cout << "Question: " << statement << endl << endl;

		for (size_t i = 0; i < 4; i++)
		{
			randIndex = rand() % questionOptions.size();
			cout << char(65 + i) << ") " << questionOptions[randIndex] << endl;
			questionOptions2[char(65 + i)] = questionOptions[randIndex];
			questionOptions.erase(questionOptions.begin() + randIndex);
		}
	}

	bool CheckAnswer(string userAnswer) override
	{
		if (questionOptions2[userAnswer[0]] == answer)
		{
			return true;
		}

		return false;
	}

};


class Test
{
	vector<shared_ptr<Question>> questions;
	string name;
	bool hasPassed;
	int countCorrectAnswers = 0;
	double score = 0;
	int grade = 0;

public:

	Test(const string& name) : name(name)
	{ }


	void ShowAllTestQuestions() {
		string userAnswer;

		for (shared_ptr<Question> object : questions)
		{
			object->ShowQuestion();
			cout << "\nYour Answer: ";
			getline(cin, userAnswer);

			if (object->CheckAnswer(userAnswer)) countCorrectAnswers++;
		}
	}


	string GetName() const
	{
		return name;
	}

	void SetName(string name)
	{
		while (name.length() < 2 || name.length() > 15)
		{
			cout << "Enter Name Again.\n\nNew Name: ";
			cin >> name;
		}

		name[0] = toupper(name[0]);
		this->name = name;
	}


	int GetCountCorrectAnswers() const
	{
		return countCorrectAnswers;
	}

	void SetCountCorrectAnswers(int countCorrectAnswers)
	{
		while (countCorrectAnswers > questions.size())
		{
			cout << "\nThe Count of The Correct Aswers should be less than The Count of The All Questions.\n\nEnter New Count: ";
			cin >> countCorrectAnswers;
		}

		this->countCorrectAnswers = countCorrectAnswers;
	}


	int GetGrade() const
	{
		return countCorrectAnswers * 12 / questions.size();
	}

	void SetGrade(int grade)
	{
		while (grade > 13 || grade < 0)
		{
			cout << "\nThe Grade should be between 0 and 12.\n\nEnter New Grade: ";
			cin >> grade;
		}

		this->grade = grade;
	}


	double GetPercentCorrectAnswers() const
	{
		return countCorrectAnswers * 100 / questions.size();
	}

	void SetPercentCorrectAnswers()
	{
		while (score > 100 || score < 0)
		{
			cout << "\nThe Score should be between 0 and 100.\n\nNew Score: ";
			cin >> score;
		}

		this->score = score;
	}


	bool GetHasPassed() const
	{
		return hasPassed;
	}

	void SetHasPassed()
	{
		hasPassed = (!hasPassed);
	}


};


class Category
{
	vector<shared_ptr<Test>> tests;
	string name;

public:

	Category(const string& name) : name(name)
	{ }


	string GetCategoryName() const
	{
		return name;
	}

	void SetCategoryName(string name)
	{
		while (name.length() < 2 || name.length() > 15)
		{
			cout << "\nThe Name Char should be between 3 and 15.\n\nNew Name: ";
			cin >> name;
		}

		this->name = name;
	}


	shared_ptr<Test> SelectRandomTest()
	{
		return tests[rand() % tests.size()];
	}


	vector<shared_ptr<Test>> GetTests() const
	{
		return tests;
	}

};


class User
{
	string name, surname, username, password, paternalName, address, phoneNumber;
	vector<shared_ptr<Test>> takenExams;

public:

	User() :name{}, surname{}, username{}, password{}, paternalName{}, address{}, phoneNumber{}
	{ }

	User(const string& name, const string& surname, const string& username, const string& paternalName, const string& address, const string& phoneNumber)
		:name(name), surname(surname), username(username), paternalName(paternalName), address(address), phoneNumber(phoneNumber)
	{ }


	string GetName() const
	{
		return name;
	}

	void SetName(string name)
	{
		while (name.length() < 3 || name.length() > 15)
		{
			cout << "\nThe Name Length should be between 3 and 15.\n\nNew Name: ";
			cin >> name;
		}

		this->name = name;
	}


	string GetSurame() const
	{
		return surname;
	}

	void SetSurname(string surname)
	{
		while (surname.length() < 3 || surname.length() > 15)
		{
			cout << "\nThe Surname Length should be between 3 and 15.\n\nNew Surname: ";
			cin >> surname;
		}

		this->surname = surname;
	}


	string GetUsername() const
	{
		return username;
	}

	void SetUsername(string username)
	{
		while (username.length() < 3 || username.length() > 15)
		{
			cout << "\nThe Username Length should be between 3 and 15.\n\nNew Username: ";
			cin >> username;
		}

		this->username = username;
	}


	string GetPaternalName() const
	{
		return paternalName;
	}

	void SetPaternalName(string paternalName)
	{
		while (paternalName.length() < 3 || paternalName.length() > 15)
		{
			cout << "\nThe Paternal Name Length should be between 3 and 15.\n\nNew PaternalName: ";
			cin >> paternalName;
		}

		this->paternalName = paternalName;
	}


	string GetAddress() const
	{
		return address;
	}

	void SetAddress(string address)
	{
		while (address.length() < 4 || address.length() > 25)
		{
			cout << "\nThe Address Length should be between 4 and 25.\n\nNew Address: ";
			cin >> address;
		}

		this->address = address;
	}


	string GetPhoneNumber() const
	{
		return phoneNumber;
	}

	void SetPhoneNumber(string phoneNumber)
	{
		while (phoneNumber.length() != 10 && phoneNumber.length() != 13)
		{
			cout << "\nThe Phone Number Length should be between 10 or 13.\n\nNew Phone Number: ";
			cin >> phoneNumber;
		}

		this->phoneNumber = phoneNumber;
	}


	string GetPassword() const
	{
		return password;
	}

	void SetPassword(string password)
	{
		while (password.length() < 6 || password.length() > 15)
		{
			cout << "\nThe Password Length should be between 6 and 20.\n\nNew Password: ";
			cin >> password;
		}

		this->password = password;
	}


	void ShowPreviousTestResults()
	{
		for (const auto& exams : takenExams)
		{
			cout << exams->GetName() << endl;
			cout << exams->GetHasPassed() << endl;
			cout << exams->GetCountCorrectAnswers() << endl;
			cout << exams->GetPercentCorrectAnswers() << endl;
			cout << exams->GetGrade() << endl << endl;
		}
	}


	void NewTest(shared_ptr<Test> test)
	{
		test->ShowAllTestQuestions();
		takenExams.push_back(test);

		cout << "Username: " << username << endl;
		ShowPreviousTestResults();
	}

};


class Database
{
	vector<shared_ptr<Category>> categories;
	vector<shared_ptr<User>> users;
	shared_ptr<Admin> admin;

public:

	Database() :categories{}, users{}, admin{}
	{ }


	vector<shared_ptr<Category>>& GetCategories()
	{
		return categories;
	}


	vector< shared_ptr<User>>& GetUsers()
	{
		return users;
	}


	shared_ptr<Admin>& GetAdmin()
	{
		return admin;
	}



	void ShowAllUsers() const
	{
		for (shared_ptr<User> user : users)
		{
			cout << user->GetName() << endl;
			cout << user->GetSurame() << endl;
			cout << user->GetUsername() << endl;
			cout << user->GetPaternalName() << endl;
			cout << user->GetPassword() << endl;
			cout << user->GetAddress() << endl;
			cout << user->GetPhoneNumber() << endl;
		}
	}


	void ShowAllTests()
	{
		for (const auto& item : categories)
		{

		}
	}

};


class Admin
{
	string username, password;
	Database& db;

public:

	Admin(Database& database) :username{}, password{}, db(database)
	{ }

	Admin(string username, string password, Database& database) :username(username), password(password), db(database)
	{ }


	string GetAdminUsername() const
	{
		return username;
	}

	void SetAdminUsername(string username)
	{
		while (username.length() < 3 || username.length() > 15)
		{
			cout << "Enter Straight Length Admin Username.";
			cin >> username;
		}

		this->username = username;
	}


	string GetAdminPassword() const
	{
		return password;
	}

	void SetAdminPassword(string password)
	{
		while (password.length() < 6 || password.length() > 15)
		{
			cout << "Enter Straight Length Admin Password.";
			cin >> password;
		}

		this->password = password;
	}


	void AddCategory(string categoryName)
	{
		shared_ptr<Category> category = make_shared<Category>(categoryName);

		db.GetCategories().push_back(category);
	}


	void AddTest(string testName, int categoryInput)
	{
		shared_ptr<Test> test = make_shared<Test>(testName);

		db.GetCategories()[categoryInput - 1]->GetTests().push_back(test);
	}


	void AddQuestion(int categoryInput, int testInput, int questionTypeInput)
	{
		string statement, correctAnswer, optionInput;
		shared_ptr<Question> question;

		cout << "Enter Question Statement: ";
		cin >> statement;

		cout << "Enter Correct Answer: ";
		cin >> correctAnswer;

		switch (questionTypeInput)
		{

		case 1:

			question = make_shared<TrueFalseQuestion>(statement, correctAnswer);
			break;

		case 2:

			question = make_shared<OpenEndedQuestion>(statement, correctAnswer);
			break;

		case 3:

			question = make_shared<FourOptionQuestion>(statement, correctAnswer);

			for (size_t i = 0; i < 3; i++)
			{
				cout << "Enter False Answer No" << i + 1 << ": ";
				cin >> optionInput;

				question->GetQuestionOptions().push_back(optionInput);
			}

			break;

		default:

			cout << "\nChoose Correct Option.\n";

			break;
		}

	}


	shared_ptr<User>& CreateUser(string name, string surname, string username, string password, string paternalName, string address, string phoneNumber)
	{


	}


	shared_ptr<User>& FindUserByUsername(string username)
	{
		for (auto& user : db.GetUsers())
		{
			if (user->GetUsername() == username)
			{
				return user;
			}
		}

		throw runtime_error("\nUser Not Found.\n");
	}
};


class UserManager
{
	Database& db;

public:

	UserManager(Database& database) :db(database)
	{ }


	void UserRegister(string name, string surname, string username, string password, string paternalName, string address, string phoneNumber)
	{
		shared_ptr<User> user = make_shared<User>();

		user->SetName(name);
		user->SetSurname(surname);
		while (!ValidationUser(username))
		{
			cin >> username;
			ValidationUser(username);
		}
		user->SetUsername(username);
		user->SetPassword(password);
		user->SetPaternalName(paternalName);
		user->SetAddress(address);
		user->SetPhoneNumber(phoneNumber);

		db.GetUsers().push_back(user);
	}


	bool ValidationUser(string username)
	{
		for (const auto& user : db.GetUsers())
		{
			if (user->GetUsername() == username) return false;
		}

		return true;
	}


	shared_ptr<User> UserLogin(string username, string password)
	{
		for (const auto& user : db.GetUsers())
		{
			if (user->GetUsername() == username && user->GetPassword() == password)
			{
				cout << "Login is Successful.";
				return user;
			}
		}

		cout << "Invalid Password or Username";
		return nullptr;
	}

};


class AdminManager
{
	Database& db;

public:

	AdminManager(Database& database) :db(database)
	{ }


	void AdminRegister(string username, string password)
	{
		if (db.GetAdmin())
		{
			cout << "\nThere's an Admin in DB.\n";

			return;
		}

		shared_ptr<Admin> admin = make_shared<Admin>(db);

		admin->SetAdminUsername(username);
		admin->SetAdminPassword(password);
	}


	shared_ptr<Admin> AdminLogin(shared_ptr<Admin> admin)
	{
		if (admin->GetAdminUsername() == db.GetAdmin()->GetAdminUsername() && admin->GetAdminPassword() == db.GetAdmin()->GetAdminPassword())
		{
			cout << "\nLogin is Successful for Admin.\n";
			return admin;
		}

		cout << "\nInvalid Password or Username for Admin.\n";
		return nullptr;
	}

};


int main()
{

	//srand(time(NULL));

	//vector<string> options1 = { "10","5","1","4" };
	//vector<string> options2 = { "4","5","6","7" };
	//vector<string> options3 = { "4","3.5","5.5","7" };
	//vector<string> options4 = { "f(x) = x^n","f(x) = sin(nx)","f(x) = 1/1+nx","f(x) = e^(-nx)" };


	//shared_ptr<Question> question1 = make_shared<FourOptionQuestion>(options1, "Funksiya f(x) = (x^2 - 4) / (x - 2)\nFunksiyanin x -> 2 limitini tapin.\n\n", "4");
	//shared_ptr<Question> question2 = make_shared<FourOptionQuestion>(options2, "Bir funksiya f(x) = x^3 - 3x^2 + 4 noqtesinde x = 2 ucun toreme f'(x)-in deyeri nedir?\n\n", "5");
	//shared_ptr<Question> question3 = make_shared<FourOptionQuestion>(options3, "lim_{x -> 0} (sin(x) / x) limitinin qiymeti nedir?\n\n", "3.5");
	//shared_ptr<Question> question4 = make_shared<FourOptionQuestion>(options4, "Hansi funksiya uniform sekilde yaxinlasir?\n\n", "f(x) = 1/1+nx");
	//shared_ptr<Question> question5 = make_shared<TrueFalseQuestion>("Bir funksiya əgər hər yerdə diferensialdırsa, o, mütləq kəsilməzdir.\n\n", "True");
	//shared_ptr<Question> question6 = make_shared<TrueFalseQuestion>("Bir limitin mövcud olması üçün sol və sağ limitlər həmişə fərqli ola bilər.\n\n", "False");
	//shared_ptr<Question> question7 = make_shared<TrueFalseQuestion>("Bir funksiya yalnız bir ekstremum nöqtəsinə sahibdirsə, bu nöqtə lokal minimum və ya maksimumdur.\n\n", "True");
	//shared_ptr<Question> question8 = make_shared<OpenEndedQuestion>("lim_{x -> 2} (x^2 - 4) / (x - 2) limitinin qiymeti nedir?", "4");
	//shared_ptr<Question> question9 = make_shared<OpenEndedQuestion>("Bir funksiya f(x) = x^2 + 3x - 5 ucun f(3)-un deyeri nedir?\n\n", "13");
	//shared_ptr<Question> question10 = make_shared<OpenEndedQuestion>("f(x) = x^3 - 6x^2 + 9x + 1 funksiyasinin x = 2 noqtesindeki toremesinin qiymeti nedir?\n\n", "-3");

	//vector<shared_ptr<Question>> questions;
	//questions.push_back(question1);
	//questions.push_back(question2);
	//questions.push_back(question3);

	//Test test1(questions, "Riyazi Analiz");
	//Test test2(questions, "Riyazi Analiz 2");
	//Test test3(questions, "Kompleks Analiz");

	//test1.ShowAllTestQuestions();
	//test1.CheckTest();


	Database database;
	UserManager usermanager(database);
	shared_ptr<Admin> admin;

	int userChoice, userChoice2, userChoice3, userChoice4, adminChoice, adminChoice2, adminChoice3, adminChoice4, adminChoice5, adminChoice6;

	while (true)
	{
		cout << "1.User\n2.Admin\n\nYour Choice: ";
		cin >> userChoice;
		system("cls");

		while (true)
		{
			switch (userChoice)
			{

			case 1:    // User

				cout << "1.Login\n2.Register\n3.Back\n\nYour Choice: ";

				cin >> userChoice2;
				system("cls");

				switch (userChoice2)
				{

				case 1:	  // Login
				{
					while (true)
					{
						string usernameUserInput, passwordUserInput;
						int	categoryChoice, testChoice;

						cout << "\nEnter Username: ";
						cin >> usernameUserInput;

						cout << "\nEnter Password: ";
						cin >> passwordUserInput;

						shared_ptr<User> currentlyUser = usermanager.UserLogin(usernameUserInput, passwordUserInput);

						if (currentlyUser)
						{
							system("cls");
							cout << "1.Previous Results\n2.New Test\n\nYour Choice: ";
							cin >> userChoice3;

							switch (userChoice3)
							{

							case 1:   // Previous Results

								currentlyUser->ShowPreviousTestResults();

							case 2:   // New Test

								for (size_t i = 0; i < database.GetCategories().size();i++)
								{
									cout << i + 1 << "." << database.GetCategories()[i]->GetCategoryName() << endl;
								}

								cout << "\nSelect Categories: ";
								cin >> categoryChoice;

								for (size_t i = 0;i < database.GetCategories()[categoryChoice - 1]->GetTests().size();i++)
								{
									cout << i + 1 << "." << database.GetCategories()[categoryChoice - 1]->GetTests()[i]->GetName() << endl;
								}

								cout << "\nSelect Test: ";
								cin >> testChoice;

								currentlyUser->NewTest(database.GetCategories()[categoryChoice - 1]->GetTests()[testChoice - 1]);

							default:
								cout << "\nChoice Correct Choice.\n";
								break;
							}
						}

						else
						{
							continue;
						}

						break;
					}
				}   // Login

				case 2:	  // Register
				{
					string nameUserInput, surnameUserInput, usernameUserInput, passwordUserInput, paternalUserInput, addressUserInput, phoneNumberUserInput;
					system("cls");

					cout << "\nEnter Name: ";
					cin >> nameUserInput;

					cout << "\nEnter Surname: ";
					cin >> surnameUserInput;

					cout << "\nEnter Username: ";
					cin >> usernameUserInput;

					cout << "\nEnter Password: ";
					cin >> passwordUserInput;

					cout << "\nEnter Paternal Name: ";
					cin >> paternalUserInput;

					cout << "\nEnter Address: ";
					cin >> addressUserInput;

					cout << "\nEnter Phone Number: ";
					cin >> phoneNumberUserInput;

					usermanager.UserRegister(nameUserInput, surnameUserInput, usernameUserInput, passwordUserInput, paternalUserInput, addressUserInput, phoneNumberUserInput);
					cout << "Register is Successful";

					break;
				}

				case 3:	  // Back
				{
					break;
				}

				default:

					cout << "\nChoice Correct Choice.\n";

					break;
				}

			case 2:    // Admin

				cout << "1.Login\n2.Register\n3.Back\n\nYour Choice: ";
				cin >> adminChoice;
				system("cls");

				switch (adminChoice)
				{

				case 1:	   // User Management

					cout << "1. Create User\n2. Update User\n3. Delete User\n\nYour Choice: ";
					cin >> adminChoice2;

					switch (adminChoice2)
					{

					case 1:	   // Create User	 
					{
						string nameUserInput, surnameUserInput, usernameUserInput, passwordUserInput, paternalUserInput, addressUserInput, phoneNumberUserInput;
						system("cls");

						cout << "\nEnter Name: ";
						cin >> nameUserInput;

						cout << "\nEnter Surname: ";
						cin >> surnameUserInput;

						cout << "\nEnter Username: ";
						cin >> usernameUserInput;

						cout << "\nEnter Password: ";
						cin >> passwordUserInput;

						cout << "\nEnter Paternal Name: ";
						cin >> paternalUserInput;

						cout << "\nEnter Address: ";
						cin >> addressUserInput;

						cout << "\nEnter Phone Number: ";
						cin >> phoneNumberUserInput;

						usermanager.UserRegister(nameUserInput, surnameUserInput, usernameUserInput, passwordUserInput, paternalUserInput, addressUserInput, phoneNumberUserInput);
					}

					case 2:	   // Update User
					{
						string usernameInput2;
						int updateOption;

						cout << "Which User's Data you want to update ?\n\nUsername: ";
						cin >> usernameInput2;

						shared_ptr<User>& tempUser = admin->FindUserByUsername(usernameInput2);

						cout << "What specifically would you like to update?\n\n1.Name\n2.Surname\n\n3.Username\n4.Password\n5.\Paternal Name\n6.Address\n7.Phone Number\n\nYour Choice: ";
						cin >> updateOption;

						switch (updateOption)
						{

						case 1:
						{
							string newName;
							cout << "New Name: ";
							cin >> newName;
							tempUser->SetName(newName);

							break;
						}

						case 2:
						{
							string newSurname;
							cout << "New Surname: ";
							cin >> newSurname;
							tempUser->SetSurname(newSurname);
						}

						case 3:
						{
							string newUsername;
							cout << "New Username: ";
							cin >> newUsername;
							tempUser->SetUsername(newUsername);
						}

						case 4:
						{
							string newPassword;
							cout << "New Password: ";
							cin >> newPassword;
							tempUser->SetPassword(newPassword);

							break;
						}

						case 5:
						{
							string newPaternalName;
							cout << "New Paternal Name: ";
							cin >> newPaternalName;
							tempUser->SetPaternalName(newPaternalName);

							break;
						}

						case 6:
						{
							string newAddress;
							cout << "New Address: ";
							cin >> newAddress;
							tempUser->SetAddress(newAddress);

							break;
						}

						case 7:
						{
							string newPhoneNumber;
							cout << "New Phone Number: ";
							cin >> newPhoneNumber;
							tempUser->SetPhoneNumber(newPhoneNumber);

							break;
						}

						default:

							cout << "\nChoice Correct Choice.\n";

							break;
						}
					}

					case 3:	   // Delete User



					default:
						cout << "\nChoice Correct Choice.\n";
						break;
					}

				case 2:	   // Statistics

					switch (adminChoice3)
					{

					case 1:	   // All Test Results 



					case 2:	   // All Category Test Results



					case 3:	   // Test Result



					case 4:	   // User Results	



					default:
						cout << "\nChoice Correct Choice.\n";
						break;
					}

				case 3:	   // Test Management

					cout << "1.Add Category\n2.Add Test\n3.Add Question\n\nYour Choice: ";
					cin >> adminChoice4;

					switch (adminChoice4)
					{

					case 1:	   // Add Category
					{
						string categoryName;

						cout << "Enter Category Name: ";
						cin >> categoryName;

						admin->AddCategory(categoryName);
					}

					case 2:	   // Add Test
					{
						string testName;
						int categoryInput;

						for (size_t i = 0; i < database.GetCategories().size();i++)
						{
							cout << i + 1 << "." << database.GetCategories()[i] << endl;
						}

						cout << "\nYour Choice: ";
						cin >> categoryInput;

						cout << "Enter Test Name: ";
						cin >> testName;

						admin->AddTest(testName, categoryInput);

						break;
					}

					case 3:	   // Add Question
					{
						string questionName;
						int categoryInput2, testInput, questionTypeInput;

						for (size_t i = 0; i < database.GetCategories().size();i++)
						{
							cout << i + 1 << "." << database.GetCategories()[i] << endl;
						}

						cout << "\nYour Category Choice: ";
						cin >> categoryInput2;

						for (size_t i = 0; i < database.GetCategories()[categoryInput2 - 1]->GetTests().size(); i++)
						{
							cout << i + 1 << "." << database.GetCategories()[categoryInput2 - 1]->GetTests()[i] << endl;
						}

						cout << "Your Test Choice: ";
						cin >> testInput;

						cout << "\n1. True/False Question\n2. Open-Ended Question\n3. Four-Options Question\n\nYour Choice: ";
						cin >> questionTypeInput;

						admin->AddQuestion(categoryInput2, testInput, questionTypeInput);
					}

					case 4:	   // Category Export/Import

						switch (adminChoice5)
						{

						case 1:	  // Category Export



						case 2:	  // Category Import



						default:
							break;
						}

					case 5:	   // Test Export/Import

						switch (adminChoice6)
						{

						case 1:	  // Test Export



						case 2:	  // Test Import



						default:
							break;
						}

					default:
						break;
					}

				default:
					break;
				}



			default:
				break;


				break;
			}
		}


	}

}