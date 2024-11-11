#include<iostream>
using namespace std;


#pragma region Task

/*
void DeleteBegin() {};
void DeleteEnd() {};
void DeleteByValue(const string& value) {};

Linked List ile özünüz yazırsınız.
*/

#pragma endregion


class DoublyLinkedList
{
	struct Node
	{
		string data;
		Node* next;
		Node* previous;

		Node(const string& data) :data(data), next(nullptr), previous(nullptr)
		{ }
	};

	Node* head = nullptr;

public:

	void AddBegin(const string& data)
	{
		Node* node = new Node(data);

		if (head == nullptr)
		{
			head = node;
		}

		else
		{
			node->next = head;
			head->previous = node;
			head = node;
		}

		cout << "Element " << data << " was added.\n\n";
	}

	void AddEnd(const string& data)
	{
		Node* node = new Node(data);

		if (head == nullptr)
		{
			head = node;
		}

		else
		{
			Node* tail = head;

			while (tail->next != nullptr)
			{
				tail = tail->next;
			}

			tail->next = node;
			node->previous = tail;
		}

		cout << "Element " << data << " was added.\n\n";
	}

	void DeleteBegin()
	{
		if (head == nullptr)
		{
			cout << "List is Empty !!\n";
		}

		else if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
		}

		else
		{
			head = head->next;
			head->previous->next = nullptr;

			delete head->previous;
			head->previous = nullptr;
		}

		cout << "First Element was deleted.\n\n";
	
	}

	void DeleteEnd()
	{

		if (head == nullptr)
		{
			cout << "List is Empty !!\n";

			return;
		}

		else
		{
			Node* tail = head;

			while (tail->next != nullptr)
			{
				tail = tail->next;
			}

			if (tail == head)
			{
				delete tail;

				tail = nullptr;
			}

			else
			{
				tail = tail->previous;
				tail->next->previous = nullptr;
				delete tail->next;
				tail->next = nullptr;
			}

			cout << "Last Element was deleted.\n\n";
		}
	}

	void DeleteByValue(const string& data)
	{
		Node* temp = head;

		if (head == nullptr)
		{
			cout << "List is Empty !!\n";
		}

		else
		{
			while (temp != nullptr)
			{
				if (temp->data == data)
				{
					if (temp->previous == nullptr)
					{
						DeleteBegin();

						return;
					}

					if (temp->next == nullptr)
					{
						DeleteEnd();

						return;
					}

					if (temp->previous != nullptr && temp->next != nullptr)
					{
						temp->previous->next = temp->next;
						temp->next->previous = temp->previous;
					}

					delete temp;

					cout << "Element " << data << " was deleted.\n\n";

					return;
				}

				else
				{
					temp = temp->next;
				}
			}

		}

	}


	void PrintList()
	{
		Node* temp = head;

		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}

		cout << endl;

		delete temp;
	}


	~DoublyLinkedList()
	{
		Node* temp = head;

		while (temp != nullptr)
		{
			Node* next = temp->next;

			delete temp;
			temp = next;
		}

		head = nullptr;
	}
};


int main()
{

	DoublyLinkedList dll;

	dll.AddEnd("tunay");
	dll.AddEnd("remzi");
	dll.AddEnd("narmin");
	dll.AddEnd("ilkin");
	dll.AddEnd("kerem");

	//dll.AddEnd("tunay");

	//dll.DeleteBegin();
	
	//dll.DeleteEnd();

	//dll.DeleteByValue("narmin");

	dll.PrintList();

}