#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

void displayRecords() // Method for displaying Records
{
	string line;
	
	ifstream myFile("student-file.txt");
	if(myFile.is_open())
	{
		while(getline(myFile, line))
		{
			cout << line << endl;
		}	
		myFile.close();
	}
}

void sortLastname() // Method for sorting by last name
{
	string line;
	string temp;
	vector<string> names;
	ifstream myFile("student-file.txt");
	
	if(myFile.is_open())
	{
		while(myFile.good())
		{
			getline(myFile, line);
			names.push_back(line);
		}
		myFile.close();
	}
	else
	{
		cout << "unable to open file" << endl;
	}
	
	int size = names.size();
	int i;
	
	for(i = 1; i < size; i++)
	{
		temp = names.at(i);
		
		int j;
		
		for(j = i - 1; j >= 0 && names.at(j) > temp; j--)
		{
			names.at(j+1) = names.at(j);
		}
		names.at(j+1) = temp;
	}
	
	for(i = 0; i < size; i++)
	{
		cout << names.at(i) << endl;
	}
}

void print(const string& item)
{
	cout << item << endl;
}

void sortFirstname() // Method for sorting by first name
{
	ifstream myFile;
	string lastname;
	string firstname;
	string grades;
	set<string> sortedItems;
	
	myFile.open("student-file.txt");
	
	if(!myFile)
	{
		cout << "Error" << endl;
	}
	else
	{
		myFile >> lastname >> firstname >> grades;
		
		while(!myFile.eof())
		{
			string name = firstname + " " + lastname + " " + grades;
			for(int i = 1; i < 20; i++)
			{
				sortedItems.insert(name);
			}
			
			myFile >> lastname >> firstname >> grades;
		}
		for_each(sortedItems.begin(), sortedItems.end(), &print);
		
		myFile.close();
	}
}

void displayDeansList() // Method for displaying Dean's Listers
{
	ifstream myFile;
	string lastname;
	string firstname;
	string grades;
	set<string> sortedItems;
	
	myFile.open("student-file.txt");
	
	if(!myFile)
	{
		cout << "Error" << endl;
	}
	else
	{
		myFile >> lastname >> firstname >> grades;
		
		while(!myFile.eof())
		{
			string name = grades + " " + lastname + " " + firstname;
			for(int i = 1; i < 20; i++)
			{
				if(grades > "90")
				{
					sortedItems.insert(name);
				}
			}
			
			myFile >> lastname >> firstname >> grades;
		}
		for_each(sortedItems.begin(), sortedItems.end(), &print);	
		
		myFile.close();
	}
}


int main()
{
	int choice;
	string line;
	
	while(choice != 5)
	{
		cout << "1. Display All Records" << endl;
		cout << "2. Sort by Last Name" << endl;
		cout << "3. Sort by First Name" << endl;
		cout << "4. Display Dean's List" << endl;
		cout << "5. Exit" << endl;
		
		cout << "Enter choice: ";
		cin >> choice;
		cout << endl;
		
		if(choice == 1)
		{
			displayRecords();
			cout << endl;
		}
		else if(choice == 2)
		{
			sortLastname();
			cout << endl;
		}
		else if(choice == 3)
		{
			sortFirstname();
			cout << endl;
		}
		else if(choice == 4)
		{
			displayDeansList();
			cout << endl;
		}
		else
		{
			cout << "Input Invalid!!" << endl << endl;
		}
	}
}
