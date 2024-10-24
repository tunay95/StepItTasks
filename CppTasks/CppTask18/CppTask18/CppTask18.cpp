#include<iostream>
#include<iomanip>
#include<chrono>
#include<thread>
using namespace std;

class Computer
{
	double diskSize, cpuHz;
	bool isSSD;
	int objectId, ram;
	static int id;
	char* model;
	char* vendor;
	char* videoCard;

public:

	Computer()
	{
		objectId = ++id;
		model = new char[20];
		vendor = new char[20];
		videoCard = new char[20];
		diskSize = 0;
		cpuHz = 0;
		ram = 0;
		isSSD = false;
	}

	Computer(const char* model, const char* vendor, const char* videoCard, double diskSize, double cpuHz, int ram, bool isSSD) : Computer()
	{
		this->model = new char[strlen(model) + 1] {};
		this->model[strlen(model)] = '\0';
		for (int i = 0; model[i] != '\0'; i++)
		{
			this->model[i] = model[i];
		}

		this->vendor = new char[strlen(vendor) + 1] {};
		this->vendor[strlen(vendor)] = '\0';
		for (int i = 0; vendor[i] != '\0'; i++)
		{
			this->vendor[i] = vendor[i];
		}

		this->videoCard = new char[strlen(videoCard) + 1] {};
		this->videoCard[strlen(videoCard)] = '\0';
		for (int i = 0; videoCard[i] != '\0'; i++)
		{
			this->videoCard[i] = videoCard[i];
		}

		this->diskSize = diskSize;

		this->cpuHz = cpuHz;

		this->ram = ram;

		this->isSSD = isSSD;
	}


	char* getModel() const
	{
		return model;
	}

	char* getVendor() const
	{
		return vendor;
	}

	char* getVideoCard() const
	{
		return videoCard;
	}

	int getObjectId() const
	{
		return objectId;
	}

	int getRam() const
	{
		return ram;
	}

	double getCpuHz() const
	{
		return cpuHz;
	}

	double getDiskSize() const
	{
		return diskSize;
	}

	bool getIsSSD() const
	{
		return isSSD;
	}


	void setModel(char* model)
	{
		while (strlen(model) < 1 || strlen(model) > 20 || model == this->model)
		{
			cout << "\nEnter Model Again:";
			cin.getline(model, 20);
		}

		this->model = model;
	}

	void setVendor(char* vendor)
	{
		while (strlen(vendor) < 1 || strlen(vendor) > 20)
		{
			cout << "\nEnter Vendor Again:";
			cin.getline(vendor, 20);
		}

		this->vendor = vendor;
	}

	void setVideoCard(char* videoCard)
	{
		while (strlen(videoCard) < 1 || strlen(videoCard) > 20)
		{
			cout << "\nEnter VideoCard Again:";
			cin.getline(videoCard, 20);
		}

		this->videoCard = videoCard;
	}

	void setRam(int ram)
	{
		while (ram > 0 || ram == this->ram)
		{
			cout << "\nEnter Ram Again:";
			cin >> ram;
		}

		this->ram = ram;
	}

	void setCpuHz(double cpuHz)
	{
		while (cpuHz > 0 || cpuHz == this->cpuHz)
		{
			cout << "\nEnter CpuHz Again:";
			cin >> cpuHz;
		}

		this->cpuHz = cpuHz;
	}

	void setDiskSize(double diskSize)
	{
		while (diskSize > 0 || diskSize == this->diskSize)
		{
			cout << "\nEnter DiskSize Again:";
			cin >> diskSize;
		}

		this->diskSize = diskSize;
	}

	void setIsSSD(bool isSSD)
	{
		while (isSSD == this->isSSD)
		{
			cout << "\nEnter SSD Again:";
			cin >> isSSD;
		}

		this->isSSD = isSSD;
	}

	friend ostream& operator<<(ostream& output, const Computer& object)
	{
		cout << endl;
		cout << "\033[36m" << setw(13) << "Id: " << "\033[0m" << object.objectId << endl;
		cout << "\033[36m" << setw(13) << "Model: " << "\033[0m" << object.model << endl;
		cout << "\033[36m" << setw(13) << "Vendor: " << "\033[0m" << object.vendor << endl;
		cout << "\033[36m" << setw(13) << "VideoCard: " << "\033[0m" << object.videoCard << endl;
		cout << "\033[36m" << setw(13) << "CpuHz: " << "\033[0m" << object.cpuHz << endl;
		cout << "\033[36m" << setw(13) << "DiskSize: " << "\033[0m" << object.diskSize << endl;
		cout << "\033[36m" << setw(13) << "Have SSD: " << "\033[0m" << object.isSSD << endl;
		cout << endl;
		cout << "---------------------------------------";

		return output;
	}

	friend istream& operator>>(istream& input, Computer& object)
	{
		input.ignore();

		cout << "\nComputer Model: ";
		input.getline(object.model, 20);

		cout << "\nComputer Vendor: ";
		input.getline(object.vendor, 20);

		cout << "\nComputer VideoCard: ";
		input.getline(object.videoCard, 20);

		cout << "\nComputer CpuHZ: ";
		input >> object.cpuHz;

		cout << "\nComputer Ram: ";
		input >> object.ram;

		cout << "\nComputer DiskSize: ";
		input >> object.diskSize;

		cout << "\nHave SSD: ";
		input >> object.isSSD;

		return input;
	}



	~Computer()
	{
		delete[] videoCard;
		videoCard = nullptr;

		delete[] model;
		model = nullptr;

		delete[] vendor;
		vendor = nullptr;
	}
};

int Computer::id = 0;

class ComputerStore
{
	char* storeName;
	char* storeAddress;
	Computer** computers;
	int count;

public:

	ComputerStore()
	{
		storeName = new char[20];
		storeAddress = new char[20];
		computers = new Computer*;
		count = 0;
	}

	ComputerStore(const char* storeName, const char* storeAddress, Computer**& computers, int& count) :ComputerStore()
	{
		this->count = count;

		this->storeName = new char[strlen(storeName) + 1] {};

		this->storeName[strlen(storeName)] = '\0';

		for (int i = 0; storeName[i] != '\0'; i++)
		{
			this->storeName[i] = storeName[i];
		}

		this->storeAddress = new char[strlen(storeAddress) + 1] {};

		this->storeAddress[strlen(storeAddress)] = '\0';

		for (int i = 0; storeAddress[i] != '\0'; i++)
		{
			this->storeAddress[i] = storeAddress[i];
		}

		this->computers = new Computer * [count] {};

		for (int i = 0; i < count; i++)
		{
			this->computers[i] = new Computer(*computers[i]);
		}

	}


	ComputerStore& operator=(const ComputerStore& object)
	{
		storeName = new char[20] {*object.storeName};
		storeAddress = new char[20] {*object.storeAddress};

		for (int i = 0; i < count; i++)
		{
			this->computers[i] = new Computer(*object.computers[i]);
		}

		return *this;
	}

	void setStoreName(char* storeName)
	{
		while (strlen(storeName) < 1 || strlen(storeName) > 20 || storeName == this->storeName)
		{
			cout << "\nEnter StoreName Again:";
			cin.getline(storeName, 20);
		}

		this->storeName = storeName;
	}

	void setStoreAdress(char* storeAddress)
	{
		while (strlen(storeAddress) < 1 || strlen(storeAddress) > 20)
		{
			cout << "\nEnter StoreAddress Again:";
			cin.getline(storeAddress, 20);
		}

		this->storeAddress = storeAddress;
	}


	char* getStoreName() const
	{
		return storeName;
	}

	char* getstoreAddress() const
	{
		return storeAddress;
	}

	int getCount() const
	{
		return count;
	}


	friend ostream& operator<<(ostream& output, const ComputerStore& object)
	{

		output << object.storeName << endl;
		output << object.storeAddress << endl;

		for (int i = 0; i < object.count; i++)
		{
			if (object.computers[i] == nullptr)
			{
				continue;
			}
			cout << "\n-------------{ " << "\033[33m" << "Product " << i + 1 << "\033[0m" << " }------------- \n";
			output << *object.computers[i] << endl;
		}

		return output;
	}

	friend istream& operator>>(istream& input, ComputerStore& object)
	{
		cout << "ComputerStore Name: ";
		input.getline(object.storeName, 20);

		cout << "Computer Address: ";
		input.getline(object.storeAddress, 20);

		return input;
	}

	void AddComputer()
	{
		Computer* newComputer = new Computer;
		cin >> *newComputer;

		Computer** temp = new Computer * [count + 1];

		for (int i = 0; i < count; i++)
		{
			temp[i] = computers[i];
		}

		temp[count] = newComputer;

		delete[] computers;
		computers = temp;
		count++;
	}

	void DeleteComputer(int id)
	{
		delete computers[id - 1];

		computers[id - 1] = nullptr;

		cout << "\nProduct " << id << " was deleted.\n";
	}

	~ComputerStore()
	{
		delete[] storeName;
		delete[] storeAddress;

		delete[] computers;
	}
};


void main()
{
	int size = 3, choice, searchId;

	Computer* computer1 = new Computer{ "XPS 15", "Dell", "NVIDIA GTX 1650", 512, 3.6, 16, true };
	Computer* computer2 = new Computer{ "MacBook Pro", "Apple", "Apple M1", 256, 2.9, 8, false };
	Computer* computer3 = new Computer{ "ROG Strix", "ASUS", "NVIDIA RTX 3080", 1024, 4.2, 32, true };

	Computer** computers = new Computer * [size] {computer1, computer2, computer3};

	ComputerStore store1("Caspian", "Nizami metrosu", computers, size);


	while (true)
	{
		system("cls");

		cout << "\n==============================================\n\n1) Show All Computers \n2) Show Computer \n3) Create Computer Product \n4) Delete Computer Product \n5) Exit \n\nChoice: ";
		cin >> choice;
		cout << endl;


		if (choice == 1)
		{
			cout << store1;
		}

		else if (choice == 2)
		{
			cout << "Enter Id: ";
			cin >> searchId;

			while (searchId < 0 || searchId > store1.getCount())
			{
				cout << "\nId was not found.\n\nNew Id: ";
				cin >> searchId;
				cout << endl;
			}
			cout << *computers[searchId - 1];
		}

		else if (choice == 3)
		{
			store1.AddComputer();
		}

		else if (choice == 4)
		{
			cout << "Enter Id: ";
			cin >> searchId;

			while (searchId < 0 || searchId > store1.getCount())
			{
				cout << "\nId was not found.\n\nNew Id: ";
				cin >> searchId;
				cout << endl;
			}
			store1.DeleteComputer(searchId);
		}

		else
		{
			cout << "\n\nEnter Correct Choise !! \n\n";
		}

		this_thread::sleep_for(chrono::seconds(5));		// Ekranda qalmaq saniyesi 

	}

	delete[] computers;
}