
#include<iostream>
#include<string>
#include<limits>
using namespace std;

// Structure to store patient information
struct Patient
{
	int id;
	string name;
	int age;
	string disease;
	Patient* next;      // Pointer for linked list
	Patient* hashNext;  // Pointer for hash table chaining
};

// Head pointer for the linked list
Patient* head = NULL;

// Hash table configuration
const int SIZE = 10;
Patient* hashTable[SIZE] = {NULL};

// Hash function to calculate the index using patient ID
int hashFunction(int id)
{
	return id % SIZE;
}

// Function to register a new patient
void registerPatient()
{
	Patient* p = new Patient;

	cout << "Enter Patient ID: ";
	cin >> p->id;

	// Calculate hash table index
	int index = hashFunction(p->id);

	// Check whether the patient ID already exists
	Patient* temp = hashTable[index];
	while(temp != NULL)
	{
		if(temp->id == p->id)
		{
			cout << "Patient ID already exists!\n";
			delete p;
			return;
		}
		temp = temp->hashNext;
	}

	// Clear input buffer before reading strings
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Enter Patient Name: ";
	getline(cin, p->name);

	cout << "Enter Age: ";
	cin >> p->age;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Enter Disease: ";
	getline(cin, p->disease);

	// Insert patient at the beginning of linked list
	p->next = head;
	head = p;

	// Insert patient into hash table using chaining
	p->hashNext = hashTable[index];
	hashTable[index] = p;

	cout << "\nPatient Register Sucessfully!\n";
}

// Function to search for a patient using patient ID
void searchPatient()
{
	int id;

	cout << "Enter Patient ID to Search: ";
	cin >> id;

	// Find the corresponding hash table index
	int index = hashFunction(id);

	// Search for the patient in the hash chain
	Patient* temp = hashTable[index];
	while(temp != NULL)
	{
		if(temp->id == id)
		{
			cout << "\nPatient Found!\n";
			cout << "ID: " << temp->id << endl;
			cout << "Name: " << temp->name << endl;
			cout << "Age: " << temp->age << endl;
			cout << "Disease: " << temp->disease << endl;
			return;
		}
		temp = temp->hashNext;
	}

	cout << "Patient not found!\n";
}

// Function to display all registered patients
void displayPatient()
{
	Patient* temp = head;

	// Check whether the linked list is empty
	if(temp == NULL)
	{
		cout << "No patient records available.\n";
		return;
	}

	cout << "\n---All Patient Records---\n";

	// Traverse the linked list and display patient details
	while(temp != NULL)
	{
		cout << "\nPatient ID: " << temp->id << endl;
		cout << "Name: " << temp->name << endl;
		cout << "Age: " << temp->age << endl;
		cout << "Disease: " << temp->disease << endl;

		temp = temp->next;
	}
}

// Main function: Controls the hospital management menu
int main()
{
	int choice;

	do
	{
		cout << "\n--- Hospital Management System ---\n";
		cout << "1. Register Patient\n";
		cout << "2. Search Patient\n";
		cout << "3. Display All Patients\n";
		cout << "4. Exit\n";
		cout << "Enter your choice: ";

		cin >> choice;

		// Perform operation according to user's choice
		switch(choice)
		{
			case 1:
				registerPatient();
				break;

			case 2:
				searchPatient();
				break;

			case 3:
				displayPatient();
				break;

			case 4:
				cout << "Thank you...!\n";
				break;

			default:
				cout << "Invalid choice!\n";
		}
	}
	while(choice != 4);

	return 0;
}
