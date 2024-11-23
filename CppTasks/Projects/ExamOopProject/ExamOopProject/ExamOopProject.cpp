#include<iostream>
#include<memory>
#include<map>
#include<cstring>
#include<cctype>
#include <vector>
#include <cmath>

using namespace std;


class Question
{
protected:

	string statement;
	string answer;
	char userAnswer;

public:
	Question(const string& statement, string answer) :statement(statement), answer(answer)
	{ }

	virtual void ShowQuestion() {};

	virtual bool CheckAnswer() = 0;


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


	char GetUserAnswer() const
	{
		return userAnswer;
	}

	void SetUserAnswer(char userAnswer)
	{
		this->userAnswer = userAnswer;
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

		cout << "\nYour Anwser: ";

		cin >> userAnswer;
	}

	bool CheckAnswer() override
	{
		if (toupper(userAnswer) == 'A')
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

	void ShowQuestion() override
	{
		cout << "Question: " << statement << endl << endl;

		cout << "\nYour Anwser: ";
		cin >> userAnswer;
		userAnswer[0] = toupper(userAnswer[0]);
	}

	bool CheckAnswer() override
	{
		return userAnswer == answer;
	}

};


class FourOptionQuestion :public Question
{
	vector<string> questionOptions;

	map<char, string> questionOptions2;


public:

	FourOptionQuestion(vector<string> questionOptions, const string& statement, string answer)
		: Question(statement, answer), questionOptions(questionOptions) {}


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

		cout << "\nYour Anwser: ";

		cin >> userAnswer;
		userAnswer = toupper(userAnswer);
	}

	bool CheckAnswer() override
	{
		if (questionOptions2[userAnswer] == answer)
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
	int countCorrectAnswers = 0;
	double score = 0;
	int grade = 0;

public:

	Test(vector<shared_ptr<Question>> questions, const string& name) :questions(questions), name(name)
	{ }


	void ShowAllQuestions() const
	{
		for (shared_ptr<Question> object : questions)
		{
			object->ShowQuestion();
			cout << endl << endl;
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


	double GetScore() const
	{
		return round(countCorrectAnswers * 10000 / questions.size()) / 100;
	}

	void SetScore(double score)
	{
		while (score > 100 || score < 0)
		{
			cout << "\nThe Score should be between 0 and 100.\n\nNew Score: ";
			cin >> score;
		}

		this->score = score;
	}


	void CheckTest()
	{
		for (int i = 0; i < questions.size(); i++)
		{
			if (questions[i]->CheckAnswer()) countCorrectAnswers++;
		}

	}

};


class Category
{
	vector<shared_ptr<Test>> tests;
	string name;

public:

	Category(vector<shared_ptr<Test>> tests, const string& name) :tests(tests), name(name)
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


};


class User
{
	string name, surname, username, password, paternalName, address, phoneNumber;
	vector<shared_ptr<Category>> categories;

public:

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

	void GetPaternalName(string paternalName)
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
			cout << "\nThe Phone Number Length should be between 3 and 15.\n\nNew Phone Number: ";
			cin >> phoneNumber;
		}

		this->phoneNumber = phoneNumber;
	}


	void ShowAllCategories()
	{
		for (shared_ptr<Category> object : categories)
		{
			cout << object->GetCategoryName() << endl;
		}
	}

	void ShowTestResult()
	{

	}
};


int main()
{

	srand(time(NULL));

	vector<string> options = { "10","5","1","4" };


	shared_ptr<Question> question1 = make_shared<FourOptionQuestion>(options, "Mesele: Funksiya f(x) = (x^2 - 4) / (x - 2)\nFunksiyanin x -> 2 limitini tapin.\n\n", "4");
	shared_ptr<Question> question2 = make_shared<TrueFalseQuestion>("Mesele: Eger bir funksiya f(x) noqtesinde davamlidirsa, o zaman bu funksiyanin hemin noqtede limit deyeri de movcuddur.\n\n", "True");
	shared_ptr<Question> question3 = make_shared<OpenEndedQuestion>("Mesele: Eger bir funksiya f(x) noqtesinde davamlidirsa, o zaman bu funksiyanin hemin noqtede limit deyeri de movcuddur.\n\n", "True");

	vector<shared_ptr<Question>> questions;
	questions.push_back(question1);
	questions.push_back(question2);
	questions.push_back(question3);

	Test test1(questions, "Riyazi Analiz");
	Test test2(questions, "Riyazi Analiz 2");
	Test test3(questions, "Kompleks Analiz");

	test1.ShowAllQuestions();
	test1.CheckTest();

	cout << "CountCorrectAnswers: " << test1.GetCountCorrectAnswers() << endl;
	cout << "Score: " << test1.GetScore() << endl;
	cout << "Grade: " << test1.GetGrade() << endl;


}