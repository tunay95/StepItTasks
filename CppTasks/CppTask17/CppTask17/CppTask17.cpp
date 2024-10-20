#include<iostream>
#include<string>
#include<string>
#include<chrono>
#include<thread>
#include<iomanip>
using namespace std;

class Product
{
	static int id;
	int productId;
	string name;
	string description;
	double price;
	double discount;

public:

	Product()
	{
		name = "";
		description = "";
		price = 0;
		discount = 0;
	}

	Product(const string& name, const string& description, double price, double discount) :Product()
	{
		productId = ++id;
		this->name = name;
		this->description = description;
		this->price = price;
		this->discount = discount;
	}

	string& getName()
	{
		return name;
	}

	string& getDescription()
	{
		return description;
	}

	double& getPrice()
	{
		return price;
	}

	double& getDiscount()
	{
		return discount;
	}


	void setName(string name)
	{
		if (name.length() < 2 || name.length() > 20)
		{
			cout << "The Name of Product is too concise.";
		}

		else
		{
			this->name = name;
		}
	}

	void setDescription(string description)
	{
		if (description.length() < 3 || description.length() > 20)
		{
			cout << "The Name of Product is too concise.";
		}

		else
		{
			this->description = description;
		}
	}

	void setPrice(double price)
	{
		if (price <= 0)
		{
			cout << "Price should be greater than 0.";
		}

		else
		{
			this->price = price;
		}
	}

	void setDiscount(double discount)
	{
		if (discount < 0 || discount > 100)
		{
			cout << "Price must be between 0% and 100%.";
		}

		else
		{
			this->discount = discount;
		}
	}


	void ShowProduct()
	{
		cout << endl;
		cout << "\033[36m" << setw(13) << "Id: " << "\033[0m" << productId << endl;
		cout << "\033[36m" << setw(13) << "Name: " << "\033[0m" << name << endl;
		cout << "\033[36m" << setw(13) << "Description: " << "\033[0m" << description << endl;
		cout << "\033[36m" << setw(13) << "Price: " << "\033[0m" << price << " - " << "\033[31m" << discount << " % " << "\033[0m" << "=  " << this->GetPriceWithDiscount() << "\033[32m" << " $" << "\033[0m" << endl;
		cout << "\033[36m" << setw(13) << "Discount: " << "\033[0m" << discount << " %" << endl;
		cout << endl;
		cout << "---------------------------------------";
	}


	double GetPriceWithDiscount()
	{
		double priceWithDiscountt = 0;
		priceWithDiscountt = price - (price * discount) / 100;

		return priceWithDiscountt;
	}

};


int Product::id = 0;


class Stock
{
	char* address;
	Product** products;
	int count;

public:

	Stock()
	{
		this->address = new char[20] {};
		products = nullptr;
		count = 0;
	}

	Stock(char* address, Product** products, int& count) :Stock()
	{
		this->address = new char[strlen(address) + 1] {};

		this->address[strlen(address)] = '\0';

		for (size_t i = 0; address[i] != '\0'; i++)
		{
			this->address[i] = address[i];
		}

		this->count = count;
		this->products = new Product * [count];

		for (size_t i = 0; i < count; i++)
		{
			this->products[i] = new Product(*products[i]);
		}
	}

	Stock(const Stock& other)
	{
		address = new char[strlen(other.address) + 1] {};

		address[strlen(other.address)] = '\0';

		for (size_t i = 0; other.address[i] != '\0'; i++)
		{
			this->address[i] = other.address[i];
		}

		this->count = other.count;
		products = new Product * [count] {};

		for (size_t i = 0; i < count; i++)
		{
			this->products[i] = new Product(*other.products[i]);
		}
	}

	//Stock& operator=(const Stock& other)
	//{
	//	address = new char[strlen(other.address) + 1] {};

	//	address[strlen(other.address)] = '\0';

	//	for (size_t i = 0; other.address[i] != '\0'; i++)
	//	{
	//		this->address[i] = other.address[i];
	//	}

	//	this->count = other.count;
	//	products = new Product * [count] {};

	//	for (size_t i = 0; i < count; i++)
	//	{
	//		this->products[i] = new Product(*other.products[i]);
	//	}
	//	
	//	return *this;
	//}


	void ShowStock()
	{
		for (size_t i = 0; i < count; i++)
		{
			if (products[i] == nullptr)
			{
				continue;
			}

			else
			{
				cout << "\n-------------{ " << "\033[33m" << "Product " << i + 1 << "\033[0m" << " }------------- \n";
				products[i]->ShowProduct();
			}
		}
	}


	void DeleteProduct(int id)
	{
		delete products[id - 1];
		products[id - 1] = nullptr;

		cout << "\nProduct " << id << " was deleted.";
	}


	void SearchProduct(int id)
	{
		cout << "\n-------------{ Product " << id << " }-------------\n";
		products[id - 1]->ShowProduct();
	}


	void ChangeProductDiscount(int id, double newDiscount)
	{
		products[id - 1]->setDiscount(newDiscount);
	}


	void CreateProduct(Product* newProduct)
	{
		count++;
		Product** newProducts = new Product * [count];

		for (size_t i = 0; i < count; i++)
		{
			newProducts[i] = this->products[i];
		}

		newProducts[count - 1] = new Product(*newProduct);

		delete[] products;
		products = newProducts;
	}

	~Stock() {
		delete[] address;

		for (int i = 0; i < count; i++) {
			delete products[i];
		}

		delete[] products;
	}
};


void main()
{
	int size = 3, choice, searchId;
	string name, description;
	double price, discount, discount2;

	Product* product1 = new Product{ "Lays", "Ici boshdur", 3.70, 10 };
	Product* product2 = new Product{ "Sprite", "Limon Lezzeti", 1.10, 5 };
	Product* product3 = new Product{ "Milla", "Ineklerin Secimi", 1.50, 40 };
	Product* newProduct = new Product{ "", "", 0, 0 };

	Product** products = new Product * [size] {product1, product2, product3};

	char* address = new char[20] {"Babek Avenue"};
	Stock stock1(address, products, size);
	stock1.ShowStock();

	while (true)
	{
		system("cls");

		cout << "\n==============================================\n\n1) Show All Products \n2) Search Product \n3) Create Product \n4) Update Product Discount \n5) Delete Product \n6) Exit \n\nChoice: ";
		cin >> choice;
		cout << endl;


		if (choice == 1)
		{
			stock1.ShowStock();
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

			stock1.SearchProduct(searchId);
		}

		else if (choice == 3)
		{
			cin.ignore();

			cout << "\nEnter Product Name: ";
			getline(cin, name);

			cout << "\nEnter Description: ";
			getline(cin, description);

			cout << "\nEnter Price: ";
			cin >> price;

			cout << "\nEnter Discount: ";
			cin >> discount;

			newProduct->setName(name);
			newProduct->setDescription(description);
			newProduct->setPrice(price);
			newProduct->setDiscount(discount);

			cout << endl;

			stock1.CreateProduct(newProduct);
		}

		else if (choice == 4)
		{
			cout << "Enter Id: ";
			cin >> searchId;

			while (searchId < 0 || searchId > size)
			{
				cout << "\nId was not found.\n\nNew Id: ";
				cin >> searchId;
				cout << endl;
			}

			cout << "\nEnter Discount: ";
			cin >> discount;

			while (discount < 0 || discount > 100)
			{
				cout << "\nEnter Correct Discount.\n\nNew Discount: ";
				cin >> discount;
				cout << endl;
			}

			stock1.ChangeProductDiscount(searchId, discount);
		}

		else if (choice == 5)
		{
			cout << "Enter Id: ";
			cin >> searchId;

			while (searchId < 0 || searchId > size)
			{
				cout << "\nId was not found.\n\nNew Id: ";
				cin >> searchId;
				cout << endl;
			}

			stock1.DeleteProduct(searchId);
		}

		else if (choice == 6)
		{
			break;
		}

		else
		{
			cout << "\n\nEnter Correct Choise !! \n\n";
		}

		this_thread::sleep_for(chrono::seconds(5));		// Ekranda qalmaq saniyesi 
	}

}