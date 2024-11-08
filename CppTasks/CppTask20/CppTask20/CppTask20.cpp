#include<iostream>
#include<queue>
#include <chrono>		 // Zaman aralığını təyin etmək üçün
#include <thread>		 // Gözləmə (sleep) üçün

using namespace std;

class Worker;


#pragma region Task

/*
QUEUE
1. Worker class yaradirisiniz. (fullname, age, salary, speciality) (keçdiyimiz hər şeydən istifadə edirsiniz)
2. Printer class olacaq, count, Workers(data structure queue)
Butun Workerleri cap etmek isteseniz Print methodu cagirin ve yavas yavas ekrana cap olunsun
*/

#pragma endregion


class CircularQueue
{
	int front, rear, capacity;
	Worker** workers;

public:

	CircularQueue()
	{
		capacity = 5;
		workers = new Worker * [capacity] {};
		front = -1;
		rear = -1;
	}

	CircularQueue(int capacity) :CircularQueue()
	{
		this->capacity = capacity;
	}


	int& GetCapacity() 
	{
		return capacity;
	}


	void EnQueue(Worker* worker)
	{
		if (IsEmpty())
		{
			front++;
			rear++;
			workers[rear] = worker;
		}

		else if (IsFull())
		{
			cout << "Queue is fulled.\n\n";
		}

		else
		{
			rear = (rear + 1) % capacity;
			workers[rear] = worker;
		}

	}


	bool IsFull() const
	{
		return front == (rear + 1) % capacity;
	}

	bool IsEmpty() const
	{
		return (front == -1 && rear == -1);
	}


	Worker*& Peek() const
	{
		return workers[front];
	}


	void DeQueue()
	{
		if ((rear + 1) % capacity == 0 && rear == front)
		{
			rear = -1;
			front = -1;
		}

		if (IsEmpty())
		{
			cout << "Queue is empty.\n\n";
		}

		else
		{
			delete workers[front];
			workers[front] = nullptr;
			front = (front + 1) % capacity;
		}
	}

	//~CircularQueue()
	//{
	//	delete[] workers;
	//}

};


class Worker
{
	string fullname, speciality;
	double salary;
	int age;

public:

	Worker(string fullname, string speciality, double salary, int age)
		:fullname(fullname), speciality(speciality), salary(salary), age(age)
	{ }


	string GetFullname() const
	{
		return fullname;
	}

	void SetFullname(string fullname)
	{
		while (fullname.length() < 5)
		{
			cout << "\nInvalid Fullname, Please Enter Again.\nFullname: ";
			cin >> fullname;
		}

		this->fullname = fullname;
	}


	string GetSpeciality() const
	{
		return speciality;
	}

	void SetSpeciality(string speciality)
	{
		while (speciality.length() < 5)
		{
			cout << "\nInvalid Speciality, Please Enter Again.\nSpeciality: ";
			cin >> speciality;
		}

		this->speciality = speciality;
	}


	double GetSalary() const
	{
		return salary;
	}

	void SetSalary(double salary)
	{
		while (salary < 300)
		{
			cout << "\nInvalid Salary, Please Enter Again.\nSalary: ";
			cin >> salary;
		}

		this->salary = salary;
	}


	int GetAge() const
	{
		return age;
	}

	void SetAge(int age)
	{
		while (age < 18)
		{
			cout << "\nInvalid Age, Please Enter Again.\nAge: ";
			cin >> age;
		}

		this->age = age;
	}

};


class Printer
{
	int count;
	CircularQueue& workerss;

public:

	Printer(int count, CircularQueue workerss) :count(count), workerss(workerss)
	{ }


	void Print()
	{
		for (size_t i = 0; i < count; i++)
		{
			Worker* worker = workerss.Peek();

			if (worker)
			{
				cout << "------------<Worker No" << i + 1 << ">-------------\n\n";
				cout << "|~       Fullname: " << worker->GetFullname()  << endl;
				cout << "|~     Speciality: " << worker->GetSpeciality()  << endl;
				cout << "|~            Age: " << worker->GetAge()  << endl;
				cout << "|~         Salary: " << worker->GetSalary()  << endl << endl;
				cout << "-------------------------------------" << endl << endl << endl;

				workerss.DeQueue();
			}

			else
			{
				continue;
			}

			this_thread::sleep_for(std::chrono::seconds(1));
			cout << "Loading...";

			this_thread::sleep_for(std::chrono::seconds(2));
			cout << "\b\b\b\b\b\b\b\b\b\b";
		}

		cout << "\033[A\33[2K";			// Sonuncu sətiri silmək üçün

	}

};


int main()
{
	Worker* worker1 = new Worker("Tunay", "BackEnd", 1500, 20);
	Worker* worker2 = new Worker("Remzi", "BackEnd", 1500, 20);
	Worker* worker3 = new Worker("Narmin", "Pilot", 5500, 20);
	Worker* worker4 = new Worker("Aytac", "Doctor", 4000, 20);
	Worker* worker5 = new Worker("Ilkin", "Influencer", 700, 20);

	CircularQueue queue1;

	queue1.EnQueue(worker1);
	queue1.EnQueue(worker2);
	queue1.EnQueue(worker3);
	queue1.EnQueue(worker4);
	queue1.EnQueue(worker5);


	//queue1.DeQueue();
	//queue1.DeQueue();
	//queue1.DeQueue();
	//queue1.DeQueue();
	//queue1.DeQueue();

	Printer printer(queue1.GetCapacity(), queue1);

	printer.Print();

	return 0;
}