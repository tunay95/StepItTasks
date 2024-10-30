#include<iostream>
using namespace std;

#pragma region Task

// Polymorphism, virtual methods
//
// Əsas "Device" sinfi və ondan törəmə "Kettle", "Microwave", "Car", "Ship" siniflərini yaradın.
// Konstruktor vasitəsilə hər bir cihazın adını və onun xüsusiyyətlərini təyin edin.
// Hər bir sinif üçün aşağıdakı metodları həyata keçirin :
//
//■ Sound — cihazın səsini çıxarır(konsolda mətn şəklində yazır);
//■ Show — cihazın adını göstərir;
//■ Desc — cihazın təsvirini göstərir.
//
// Reference or Pointer to Base class ilə obyektlər yaradın və hər obyekt yuxarıdakı metodlardan birini çağırdıqda öz metodunu çağırmış olsun.

#pragma endregion


class Device
{
protected:

	string name;

public:

	Device()
	{
		name = "";
	}

	Device(string name)
	{
		this->name = name;
	}

	virtual void Sound()
	{
		cout << "The Sound of Device";
	}

	virtual void Show()
	{
		cout << "Name: " << name;
	}

	virtual void Desc()
	{
		cout << "Some Device Description";
	}

};

class Kettle :public Device
{
protected:

	string name;

public:

	Kettle()
	{
		name = "";
	}

	Kettle(string name)
	{
		this->name = name;
	}

	void Sound() override
	{
		cout << "Kettle Sound";
	}

	void Show() override
	{
		cout << "Name: " << name;
	}

	void Desc() override
	{
		cout << "Some Kettle Description";
	}

};

class Microwave :public Device
{
protected:

	string name;

public:

	Microwave()
	{
		name = "";
	}

	Microwave(string name)
	{
		this->name = name;
	}

	void Sound() override
	{
		cout << "Microwave Sound";
	}

	void Show() override
	{
		cout << "Name: " << name;
	}

	void Desc() override
	{
		cout << "Some Microwave Description";
	}

};

class Car
{
protected:

	string name;

public:

	Car()
	{
		name = "";
	}

	Car(string name)
	{
		this->name = name;
	}

	void Sound()
	{
		cout << "Car Sound";
	}

	void Show()
	{
		cout << "Name: " << name;
	}

	void Desc()
	{
		cout << "Some Car Description";
	}

};

class Ship
{
protected:

	string name;

public:

	Ship()
	{
		name = "";
	}

	Ship(string name)
	{
		this->name = name;
	}

	void Sound()
	{
		cout << "Ship Sound";
	}

	void Show()
	{
		cout << "Name: " << name ;
	}

	void Desc()
	{
		cout << "Some Ship Description";
	}

};

void getInfo(Device* device)
{
	device->Show();
	cout << endl;
	device->Sound();
	cout << endl;
	device->Desc();
	cout << endl;
}

void getInfo(Device& device)
{
	device.Show();
	cout << endl;
	device.Sound();
	cout << endl;
	device.Desc();
	cout << endl;
}

int main()
{
	Microwave mw1("MicroWave");

	Device& deviceR = mw1;
	getInfo(deviceR);

	cout << endl;

	Device* kettle1 = new Kettle("kettle1");
	getInfo(kettle1);

	return 0;
}