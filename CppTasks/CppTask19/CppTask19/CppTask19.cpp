#include<iostream>
#include<cassert>
#include<string>
#include<vector>

using namespace std;

class String {

	char* array = nullptr;
	int size = 0;
	int capacity = 10;

public:

	String()
	{
		this->array = new char [capacity] {};
	};

	String(size_t capacity) :String()
	{
		while (this->capacity < capacity)
		{
			this->capacity += 10;
		}
	}


	char* GetData() const
	{
		return array;
	}

	size_t GetSize() const
	{
		return size;
	}

	size_t GetCapacity() const
	{
		return capacity;
	}


	char& operator[](size_t index)
	{
		if (index >= 0 && index < size)
		{
			return array[index];
		}

		else
		{
			assert(!"Index Out of Range");
		}
	}


	String& PushBack(const char value)
	{
		if (size == capacity)
		{
			capacity += 10;
			char* newArray = new char[capacity] {};

			for (size_t i = 0; i < size; i++)
			{
				newArray[i] = array[i];
			}
			newArray[size] = value;
			delete[] array;

			array = newArray;;
			size++;
		}
		else
		{
			array[size] = value;
			size++;
		}

		return *this;
	}


	int Compare(const char* object)
	{
		if (strlen(this->array) > strlen(object))
		{
			return -1;
		}

		else if (strlen(this->array) == strlen(object))
		{
			return 0;
		}

		else
		{
			return 1;
		}
	}


	void Substr(int startIndex, int step)
	{
		if (startIndex + step >= strlen(this->array))
		{
			cout << "\nEnter Correct Index or Step.\n";
		}

		else
		{
			for (int i = startIndex; i < startIndex + step; i++)
			{
				cout << this->array[i];
			}
		}
	}


	void Erase(int startIndex, int step)
	{
		char* newArray = new char[capacity] {};
		int newIndex = 0;

		if (startIndex + step >= strlen(this->array))
		{
			cout << "\nEnter Correct Index or Step.\n";
		}

		else
		{
			for (int i = 0; i < capacity; i++)
			{
				if (i < startIndex || i>startIndex + step)
				{
					newArray[newIndex] = this->array[i];
					newIndex++;

				}
			}

			delete[] this->array;
			this->array = newArray;
		}
	}


	char* Find(const char object)
	{
		int newIndex = 0;

		for (int i = 0; i < capacity; i++)
		{
			if (array[i] == object)
			{
				return &(array[i]);
			}
		}

		return nullptr;
	}


	friend ostream& operator<<(ostream& output, const String& obj)
	{
		for (int i = 0; i < obj.size; i++)
		{
			output << obj.array[i];
		}

		output << endl;
		return output;
	}

	~String()
	{
		delete[] array;
	}

};

void main()
{

#pragma region Own String

	String string1;

	string1.PushBack('s');
	string1.PushBack('a');
	string1.PushBack('l');
	string1.PushBack('a');
	string1.PushBack('m');
	string1.PushBack(' ');
	string1.PushBack('T');
	string1.PushBack('u');
	string1.PushBack('n');
	string1.PushBack('a');
	string1.PushBack('y');
	string1.PushBack('!');

	string name1 = "taysadas";
	string name2 = "ssss";

	//cout << name1.compare(name2);
	//string1.Substr(2, 5);
	/*string1.Erase(6, 0);*/
	char* address = string1.Find('s');
	cout << address;

	/*cout << string1 << endl;*/

#pragma endregion
}