#include <iostream>
#include <string>

using namespace std;

//struct for data
struct Data
{
	int id = 0;
	string name, roomType, number, address, email, checkIn, checkOut;
};

//Node class
class Node
{
public:
	Data info;
	Node* next;

	Node(Data data)
	{
		info = data;
		next = nullptr;
	}
};

//Hotel class
class Hotel
{
public:
	Node* head;

	Hotel() : head(nullptr) {}

	//fuctions prototype
	void insert();
	void menu();
	void update();
	void search();
	void del();
	void sort();
	void display();
	void list();
};

//menu function
void Hotel::menu()
{
	int choice;

	cout << endl;
	cout << "\t Welcome to Hotel Mangement system Application\n" << endl;
	cout << "\n\t______Hotel Management System______\n\n";
	cout << "\n\nS.No.\t" << "Fuctions" << "\t\t" << "Description\n\n";
	cout << "1.\t" << "Insert" << "\t\t" << "Insert a new record\n\n";
	cout << "2.\t" << "Update" << "\t\t" << "Update a record\n\n";
	cout << "3.\t" << "Search" << "\t\t" << "Search a record\n\n";
	cout << "4.\t" << "Delete" << "\t\t" << "Delete a record\n\n";
	cout << "5.\t" << "Display" << "\t\t" << "Display all records\n\n";
	cout << "6.\t" << "Exit" << "\t\t" << "Exit the program\n\n";

	cout << "\n\nEnter your choice: ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		insert();
		menu();
	case 2:
		update();
		menu();
	case 3:
		search();
		menu();
	case 4:
		del();
		menu();
	case 5:
		sort();
		display();
		menu();
	case 6:
		exit(0);
		break;
	default:
		cout << "Invalid choice\n";
		break;
	}
}

//insert function
void Hotel::insert()
{
	system("cls");
	cout << "\n\t______Hotel Management System______\n\n";
	Data data;
	//input
	cout << "Enter the following details\n";
	cout << "ID: ";
	cin >> data.id;
	cin.ignore();
	cout << "Name: ";
	getline(cin, data.name);
	cout << "Room Type: ";
	getline(cin, data.roomType);
	cout << "Number: ";
	getline(cin, data.number);
	cout << "Address: ";
	getline(cin, data.address);
	cout << "Email: ";
	getline(cin, data.email);
	cout << "Check In: ";
	getline(cin, data.checkIn);
	cout << "Check Out: ";
	getline(cin, data.checkOut);

	//create new node
	Node* newNode = new Node(data);

	//if list is empty
	if (head == nullptr)
	{
		head = newNode;
	}
	else
	{
		Node* temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}
	system("cls");
}

//search function
void Hotel::search()
{
	system("cls");
	cout << "\n\t______Hotel Management System______\n\n";
	int id;
	cout << "Enter the ID to search: ";
	cin >> id;
	cout << endl;

	Node* temp = head;
	while (temp != nullptr)
	{
		if (temp->info.id == id)
		{
			cout << "ID: " << temp->info.id << endl;
			cout << "Name: " << temp->info.name << endl;
			cout << "Room Type: " << temp->info.roomType << endl;
			cout << "Number: " << temp->info.number << endl;
			cout << "Address: " << temp->info.address << endl;
			cout << "Email: " << temp->info.email << endl;
			cout << "Check In: " << temp->info.checkIn << endl;
			cout << "Check Out: " << temp->info.checkOut << endl;
			break;
		}
		temp = temp->next;
	}
	if (temp == nullptr)
	{
		cout << "Record not found\n";
	}
	system("pause");
	system("cls");
}

//update function
void Hotel::update()
{
	system("cls");
	cout << "\n\t______Hotel Management System______\n\n";
	int id;
	cout << "Enter the ID to update: ";
	cin >> id;
	cout << endl;

	//search the record
	Node* temp = head;
	while (temp != nullptr)
	{
		if (temp->info.id == id)
		{
			cout << "ID: " << temp->info.id << endl;
			cout << "Name: " << temp->info.name << endl;
			cout << "Room Type: " << temp->info.roomType << endl;
			cout << "Number: " << temp->info.number << endl;
			cout << "Address: " << temp->info.address << endl;
			cout << "Email: " << temp->info.email << endl;
			cout << "Check In: " << temp->info.checkIn << endl;
			cout << "Check Out: " << temp->info.checkOut << endl;
			break;
		}
		temp = temp->next;
	}
	if (temp == nullptr)
	{
		cout << "Record not found\n";
	}
	else
	{
		//update the record
		int choice;
		cout << endl;
		cout << "\t1. Name\n";
		cout << "\t2. Room Type\n";
		cout << "\t3. Number\n";
		cout << "\t4. Address\n";
		cout << "\t5. Email\n";
		cout << "\t6. Check In\n";
		cout << "\t7. Check Out\n";

		cout << "\nEnter the field to update: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cin.ignore();
			cout << "Enter the new name: ";
			getline(cin, temp->info.name);
			break;
		case 2:
			cin.ignore();
			cout << "Enter the new room type: ";
			getline(cin, temp->info.roomType);
			break;
		case 3:
			cin.ignore();
			cout << "Enter the new number: ";
			getline(cin, temp->info.number);
			break;
		case 4:
			cin.ignore();
			cout << "Enter the new address: ";
			getline(cin, temp->info.address);
			break;
		case 5:
			cin.ignore();
			cout << "Enter the new email: ";
			getline(cin, temp->info.email);
			break;
		case 6:
			cin.ignore();
			cout << "Enter the new check in: ";
			getline(cin, temp->info.checkIn);
			break;
		case 7:
			cin.ignore();
			cout << "Enter the new check out: ";
			getline(cin, temp->info.checkOut);
			break;
		default:
			cout << "Invalid choice\n";
			break;
		}
		cout << "\n\n\t Record updated successfully\n";
	}
	system("pause");
	system("cls");
}

//delete function
void Hotel::del()
{
	system("cls");
	cout << "\n\t______Hotel Management System______\n\n";
	int id;
	cout << "Enter the ID to delete: ";
	cin >> id;
	cout << endl;

	//search the record
	Node* temp = head;
	Node* prev = nullptr;
	while (temp != nullptr)
	{
		if (temp->info.id == id)
		{
			cout << "ID: " << temp->info.id << endl;
			cout << "Name: " << temp->info.name << endl;
			cout << "Room Type: " << temp->info.roomType << endl;
			cout << "Number: " << temp->info.number << endl;
			cout << "Address: " << temp->info.address << endl;
			cout << "Email: " << temp->info.email << endl;
			cout << "Check In: " << temp->info.checkIn << endl;
			cout << "Check Out: " << temp->info.checkOut << endl;
			break;
		}
		prev = temp;
		temp = temp->next;
	}
	if (temp == nullptr)
	{
		cout << "Record not found\n";
	}
	else
	{
		//delete the record
		if (prev == nullptr)
		{
			head = temp->next;
		}
		else
		{
			prev->next = temp->next;
		}
		delete temp;
		cout << "\n\n\t Record deleted successfully\n";
	}
	system("pause");
	system("cls");
}

//sort function
void Hotel::sort()
{
	cout << "\n\t______Hotel Management System______\n\n";
	Node* temp = head;
	while (temp != nullptr)
	{
		Node* temp2 = temp->next;
		while (temp2 != nullptr)
		{
			if (temp->info.id > temp2->info.id)
			{
				Data data = temp->info;
				temp->info = temp2->info;
				temp2->info = data;
			}
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
}

//display function
void Hotel::display()
{
	system("cls");
	cout << "\n\t______Hotel Management System______\n\n";
	Node* temp = head;
	while (temp != nullptr)
	{
		cout << "ID: " << temp->info.id << endl;
		cout << "Name: " << temp->info.name << endl;
		cout << "Room Type: " << temp->info.roomType << endl;
		cout << "Number: " << temp->info.number << endl;
		cout << "Address: " << temp->info.address << endl;
		cout << "Email: " << temp->info.email << endl;
		cout << "Check In: " << temp->info.checkIn << endl;
		cout << "Check Out: " << temp->info.checkOut << endl;
		cout << endl;
		temp = temp->next;
	}
	system("pause");
	system("cls");
}
int main()
{
	Hotel hotel;
	hotel.menu();
}