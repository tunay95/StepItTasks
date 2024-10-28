#include<iostream>
#include<stack>
using namespace std;

#pragma region Task

#pragma endregion



class Engine
{

protected:

	int engineNo;
	string company;
	double volume;

public:

	Engine()
	{
		engineNo = 0;
		company = "";
		volume = 0;
	}

	Engine(int engineNo, string company, double volume) :Engine()
	{
		this->engineNo = engineNo;
		this->company = company;
		this->volume = volume;
	}

	int getEngineNo() const
	{
		return engineNo;
	}

	void setEngineNo(int engineNo)
	{
		while (engineNo < 0 && engineNo == this->engineNo)
		{
			cout << "Something went wrong..\nNew EngineNo: ";
			cin >> engineNo;
		}

		this->engineNo = engineNo;
	}

	string getCompany() const
	{
		return company;
	}

	void setCompany(string company)
	{
		while (company.length() < 1 || company.length() > 20)
		{
			cout << "Something went wrong..\nNew Company: ";
			cin >> company;
		}

		this->company = company;
	}

	double getVolume() const
	{
		return volume;
	}

	void setVolume(double volume)
	{
		while (volume < 0)
		{
			cout << "Something went wrong..\nNew Volume: ";
			cin >> volume;
		}

		this->volume = volume;
	}


	void ShowEngine()
	{
		cout << "EngineNo: " << engineNo << endl;
		cout << "Company: " << company << endl;
		cout << "Volume: " << volume << endl;
	}

};

class Vehicle :public Engine
{

public:

	static int id;
	int vehicleId;
	string model;
	string vendor;
	Engine engine;

public:

	Vehicle()
	{
		vehicleId = ++id;
		model = "";
		vendor = "";
	}

	Vehicle(string model, string vendor, Engine engine)
	{
		this->model = model;
		this->vendor = vendor;
		this->engine.setCompany(engine.getCompany());
		this->engine.setEngineNo(engine.getEngineNo());
		this->engine.setVolume(engine.getVolume());
	}

	int getVehicleId() const
	{
		return vehicleId;
	}

	string getModel() const
	{
		return model;
	}

	void setModel(string model)
	{
		while (model.length() < 1 || model.length() > 20)
		{
			cout << "Something went wrong..\nNew Model: ";
			cin >> model;
		}

		this->model = model;
	}

	string getVendor() const
	{
		return vendor;
	}

	void setVendor(string vendor)
	{
		while (vendor.length() < 1 || vendor.length() > 20)
		{
			cout << "Something went wrong..\nNew Vendor: ";
			cin >> vendor;
		}

		this->vendor = vendor;
	}

	void ShowVehicle()
	{
		cout << "VehicleId: " << vehicleId << endl;
		cout << "Model: " << model << endl;
		cout << "Vendor: " << vendor << endl;
		engine.ShowEngine();
	}

};

int Vehicle::id = 0;

class Car :public Vehicle
{
	int carId;
	bool hasSpoiler;

public:

	Car()
	{
		carId = ++id;
	}

	Car(string model, string vendor, Engine engine, bool hasSpoiler) :Vehicle(model, vendor, engine)
	{
		this->hasSpoiler = hasSpoiler;
	}


	bool GetHasSpoiler() const
	{
		return hasSpoiler;
	}

	void SetHasSpoiler(bool hasSpoiler)
	{
		while (this->hasSpoiler == hasSpoiler)
		{
			cout << "Something went wrong..\nNew HasSpoiler: ";
			cin >> hasSpoiler;
		}

		this->hasSpoiler = hasSpoiler;
	}

	void ShowCar()
	{
		engine.ShowEngine();
		cout << hasSpoiler << endl;
	}

};

class Ship :public Vehicle
{
	int shipId;
	bool hasSail;

public:

	Ship()
	{
		shipId = ++id;
	}

	Ship(string model, string vendor, Engine engine, bool hasSail) :Vehicle(model, vendor, engine)
	{
		this->hasSail = hasSail;
	}


	bool GetHasSail() const
	{
		return hasSail;
	}

	void SetHasSail(bool hasSpoiler)
	{
		while (this->hasSail == hasSail)
		{
			cout << "Something went wrong..\nNew HasSail: ";
			cin >> hasSail;
		}

		this->hasSail = hasSail;
	}

	void ShowShip()
	{
		engine.ShowEngine();
		cout << hasSail << endl;
	}

};

class Airplane :public Vehicle
{
	int airplaneId;
	int engineCount;
	int passengerCapacity;

public:

	Airplane()
	{
		airplaneId = ++id;
		engineCount = 0;
		passengerCapacity = 0;
	}

	Airplane(string model, string vendor, Engine engine, int engineCount, int passengerCapacity) :Vehicle(model, vendor, engine)
	{
		this->engineCount = engineCount;
		this->passengerCapacity = passengerCapacity;
	}


	int GetEngineCount() const
	{
		return engineCount;
	}

	void SetEngineCount(int engineCount)
	{
		while (engineCount < 0)
		{
			cout << "Something went wrong..\nNew EngineCount: ";
			cin >> engineCount;
		}

		this->engineCount = engineCount;
	}

	int GetPassengerCapacity() const
	{
		return passengerCapacity;
	}

	void SetPassengerCapacity(int passengerCapacity)
	{
		while (passengerCapacity < 0 || passengerCapacity > 1000)
		{
			cout << "Something went wrong..\nNew PassengerCapacity: ";
			cin >> passengerCapacity;
		}

		this->passengerCapacity = passengerCapacity;
	}


	void ShowAirplane()
	{
		engine.ShowEngine();
		cout << engineCount << endl;
		cout << passengerCapacity << endl;
	}

};


class VehicleDepo
{
	stack<Car> cars;
	stack<Ship> ships;
	stack<Airplane> airplanes;

public:

	void AddCar(Car car)
	{
		cars.push(car);
	}

	void AddShip(Ship ship)
	{
		ships.push(ship);
	}

	void AddAirplane(Airplane airplane)
	{
		airplanes.push(airplane);
	}


	void ShowAllVehicle()
	{
		cout << "Cars:\n";
		while (!cars.empty())
		{
			Car tempCar = cars.top();
			tempCar.ShowCar();
			cout << endl;
			cars.pop();
		}

		cout << "Ships:\n";
		while (!ships.empty())
		{
			Ship tempShip = ships.top();
			tempShip.ShowShip();
			cout << endl;
			ships.pop();
		}

		cout << "Airplanes:\n";
		while (!airplanes.empty())
		{
			Airplane tempAirplane = airplanes.top();
			tempAirplane.ShowAirplane();
			cout << endl;
			airplanes.pop();
		}

	}

};


void main()
{
	Engine engine1(1234, "Toyota", 3.0);
	Engine engine2(12, "Honda", 1.5);
	Engine engine3(123, "BMW", 2.5);
	Engine engine4(201, "MAN Diesel & Turbo", 5.0);
	Engine engine5(202, "Wärtsilä", 6.5);
	Engine engine6(203, "Rolls Royce Marine", 4.5);
	Engine engine7(101, "GE Aviation", 2.5);
	Engine engine8(102, "Rolls Royce", 3.0);
	Engine engine9(103, "Pratt & Whitney", 4.0);

	Car car1("M5", "BMW Cmpny", engine3, true);
	Car car2("Carolla", "Toyota Cmpny", engine1, false);
	Car car3("M5", "BMW Cmpny", engine3, true);

	Airplane airplane1("Boeing 737", "Boeing", engine7, 2, 180);
	Airplane airplane2("Airbus A320", "Airbus", engine8, 2, 200);
	Airplane airplane3("Cessna 172", "Cessna", engine9, 1, 4);

	Ship ship1("Titanic", "Harland and Wolff", engine4, true);
	Ship ship2("Queen Mary 2", "Chantiers de l'Atlantique", engine5, true);
	Ship ship3("Symphony of the Seas", "STX France", engine6, false);

	VehicleDepo vehicleDepo;
	vehicleDepo.AddCar(car1);
	vehicleDepo.AddCar(car2);
	vehicleDepo.AddCar(car3);

	vehicleDepo.AddShip(ship1);
	vehicleDepo.AddShip(ship2);
	vehicleDepo.AddShip(ship3);

	vehicleDepo.AddAirplane(airplane1);
	vehicleDepo.AddAirplane(airplane2);
	vehicleDepo.AddAirplane(airplane3);

	vehicleDepo.ShowAllVehicle();
}