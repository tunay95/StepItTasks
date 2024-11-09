#include<iostream>
using namespace std;

class Employee
{
protected:

	string firstName;
	string lastName;

public:

	Employee(string fname, string lname) :firstName(fname), lastName(lname)
	{ }


	string getFirstName() const
	{
		return firstName;
	}

	void setFirstName(string fname)
	{
		while (fname.length() < 3)
		{
			cout << "The First Name you entered was too short.\nNew Fist Name:";
			cin >> fname;
		}

		firstName = fname;
	}


	string getLastName() const
	{
		return lastName;
	}

	void setLastName(string lname)
	{
		while (lname.length() < 3)
		{
			cout << "The Last Name you entered was too short.\nNew Last Name:";
			cin >> lname;
		}

		lastName = lname;
	}


	virtual double calculateSalary() = 0;

	virtual void display() = 0;

};


class Worker :public Employee
{
protected:

	double hoursNumber;
	double hourlyRate;

public:

	Worker(string fname, string lname, double hoursNumber, double hourlyRate)
		:Employee(fname, lname), hoursNumber(hoursNumber), hourlyRate(hourlyRate)
	{ }


	double getHoursNumber() const
	{
		return hoursNumber;
	}

	void setHoursNumber(double hoursNumber)
	{
		while (hoursNumber < 0)
		{
			cout << "Working Hours cannot be less than 0.\nHours: ";
			cin >> hoursNumber;
		}

		this->hoursNumber = hoursNumber;
	}


	double getHourlyRate() const
	{
		return hourlyRate;
	}

	void setHourlyRate(double hourlyRate)
	{
		while (hourlyRate < 0)
		{
			cout << "Hourly Rate cannot be less than 0.\nHours: ";
			cin >> hourlyRate;
		}

		this->hourlyRate = hourlyRate;
	}


	double calculateSalary() override
	{
		if (hoursNumber > 40)
		{
			return ((hoursNumber - 40) * hourlyRate * 2 + hoursNumber * hourlyRate) * 4;
		}

		return hourlyRate * hoursNumber * 4;
	}


	void display() override
	{
		cout << firstName << " " << lastName << endl;
		cout << "Working Hours(Weekly): " << hoursNumber << " , ";
		cout << "Hourly Rate(Weekly): " << hourlyRate << " , ";
		cout << "Monthly Salary: " << calculateSalary() << "$ ." << endl << endl;
	}

};


class SalaryWorker :public Employee
{
protected:

	double salary;
	double bonus;

public:

	SalaryWorker(string fname, string lname, double salary, double bonus)
		:Employee(fname, lname), salary(salary), bonus(bonus)
	{ }


	double getSalary() const
	{
		return salary;
	}

	void setSalary(double salary)
	{
		while (salary < 0)
		{
			cout << "Salary cannot be less than 0.\nNew Salary: ";
			cin >> salary;
		}

		this->salary = salary;
	}


	double getBonus() const
	{
		return bonus;
	}

	void setBonus(double bonus)
	{
		while (bonus < 0)
		{
			cout << "Bonus cannot be less than 0.\nNew Bonus: ";
			cin >> bonus;
		}

		this->bonus = bonus;
	}


	virtual double calculateBonus() = 0;


	double calculateSalary() override
	{
		return salary;
	}

};


class SalesMan :public SalaryWorker
{
	double planPercentage;

public:

	SalesMan(string fname, string lname, double salary, double bonus, double planPercentage)
		:SalaryWorker(fname, lname, salary, bonus), planPercentage(planPercentage)
	{ }


	double getPlanPercentage()
	{
		return planPercentage;
	}

	void setPlanPercentage(double planPercentage)
	{
		while (planPercentage < 0)
		{
			cout << "Plan Percentage cannot be less than 0.\nNew Percentage: ";
			cin >> planPercentage;
		}

		this->planPercentage = planPercentage;
	}


	double calculateBonus() override
	{
		return bonus = bonus * planPercentage / 100;
	}


	void display() override
	{
		cout << firstName << " " << lastName << endl;
		cout << "Salary: " << salary << " , ";
		cout << "Bonus: " << bonus << " , ";
		cout << "Plan Percentage: " << planPercentage << " , ";
		cout << "Monthly Salary: " << calculateSalary() + calculateBonus() << "$ ." << endl << endl;
	}

};


class Manager :public SalaryWorker
{
	int clientCount;

public:

	Manager(string fname, string lname, double salary, double bonus, int clientCount)
		:SalaryWorker(fname, lname, salary, bonus), clientCount(clientCount)
	{ }


	int getClientCount()
	{
		return clientCount;
	}

	void setClientCount(int clientCount)
	{
		while (clientCount < 0)
		{
			cout << "Client Count cannot be less than 0.\nNew Count: ";
			cin >> clientCount;
		}

		this->clientCount = clientCount;
	}


	double calculateBonus() override
	{
		if (clientCount > 200)
		{
			return bonus *= 3;
		}

		else if (clientCount > 100)
		{
			return bonus *= 2;
		}

		else
		{
			return bonus;
		}
	}


	void display() override
	{
		cout << firstName << " " << lastName << endl;
		cout << "Salary: " << salary << " , ";
		cout << "Bonus: " << bonus << " , ";
		cout << "Client Count: " << clientCount << " , ";
		cout << "Monthly Salary: " << calculateSalary() + calculateBonus()<< "$ ." << endl << endl;
	}

};


void PrintEmployees(Employee* employees[], const int count)
{
	for (size_t i = 0; i < count; i++)
	{
		employees[i]->display();
	}
}


void DeleteAllEmployees(Employee* employees[], const int& count)
{
	for (size_t i = 0; i < count; i++)
	{
		delete employees[i];
	}

	delete[] employees;
}


int main()
{
	const int count = 7;

	Employee* employees[count];

	employees[0] = new Worker("Kate", "Jordan", 30, 10);
	employees[1] = new Worker("Jake", "Peterson", 50, 10);
	employees[2] = new SalesMan("Peter", "Brown", 800, 100, 80);
	employees[3] = new SalesMan("Antony", "Norton", 1000, 100, 150);
	employees[4] = new Manager("Tunay", "Huseynli", 2000, 200, 50);
	employees[5] = new Manager("Remzi", "Hesenov", 1800, 200, 120);
	employees[6] = new Manager("Narmin", "Alishova", 2200, 200, 250);

	PrintEmployees(employees, count);
	DeleteAllEmployees(employees, count);
}