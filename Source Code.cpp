//This is a simple program that determines the matric numbers for a scrambled list of students
//It must receive:
//1. A comma separated file (.csv) containing the student names and matric numbers [data]
//2. A comma separated file (.csv) containing the list of scrambled student names which
//you want to find the matric numbers for
//This program makes it easy to list the matric number for every different student
//instead of looking for each student, then copy and paste their numbers yourself

//Program fully coded by Abdulkader Sardini
//sardini@graduate.utm.my

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student
{
public:
	string name, matric;
};

//To display header screen
void screen();

//Function to display welcome screen and instructions,
//and acquire the number of students
int getNum();

//Function to read the input files
void read(Student[], Student[], int);

//Function to write the matric numbers in an output file
void write(Student[], Student[], int);


int main()
{

	char choice;

	do {

		system("cls");

		int num = getNum();

		Student* list, * glist;

		list = new Student[num];

		glist = new Student[num];

		read(list, glist, num);

		write(list, glist, num);

		cout << "Run again? (Y/N)\n";

		cout << "=> ";

		cin >> choice;

		choice = toupper(choice);

	} while (choice != 'N');
	
	return 0;
}


void screen()
{
	cout << "*************************************************************************************\n";

	cout << "This program is coded and brought to you by ABDULKADER SARDINI. All rights reserved �\n";

	cout << "*************************************************************************************\n";

	cout << endl;

	cout << "This program receives: \n";

	cout << "1. A comma separated file (.csv) containing student names and matric numbers\n";

	cout << "2. A student group list which you wish to find the matric numbers for\n";

	cout << endl;

	cout << "Please make sure that:\n";

	cout << "- Your files are in the same directory as this program executable.\n";

	cout << "- You type the file names correctly.\n";

	cout << "*************************************************************************************\n";

	cout << endl;
}

int getNum()
{
	screen();

	int num;

	cout << "Please enter the number of total students.\n";

	cout << "It must match the number of students both lists => ";

	cin >> num;

	cout << endl;

	return num;
}

void read(Student list[], Student glist[], int num)
{
	screen();

	fstream data, input;
	string filename1, filename2;

	//To get the name of the data and group list and open the files
	do {
		system("cls");

		screen();

		cout << "Please enter the names of your files.\n";

		cout << "Do not include the file extension. Must be a (.csv) file:\n";

		cout << endl;

		cout << "Student data file => ";

		cin >> filename1;

		cout << endl;

		filename1.append(".csv");

		data.open(filename1, ios::in);

		cout << "Student group list => ";

		cin >> filename2;

		cout << endl;

		filename2.append(".csv");

		input.open(filename2, ios::in);

	} while (data.fail() && input.fail());

	system("cls");
	
	if (data.is_open() && input.is_open())
	{
		//To store the data of the students
		for (int i = 0; i < num; i++)
		{
			getline(data, list[i].name, ',');

			getline(data, list[i].matric);
		}

		//To store the names in the group list
		for (int i = 0; i < num; i++)
		{
			getline(input, glist[i].name);
		}
	}

	else
		exit(EXIT_FAILURE);

	data.close();
	input.close();
}

void write(Student list[], Student glist[], int num)
{
	screen();

	string filename;

	cout << "Please name your output file. Don not include any file extensions => ";

	cin.ignore();

	getline(cin, filename);

	cout << endl;

	filename.append(".csv");


	fstream output(filename, ios::out);

	for (int j = 0; j < num; j++)
	{ 
		for (int i = 0; i < num; i++)
		{
			if (glist[j].name == list[i].name)
			{
				glist[j].matric = list[i].matric;
			}

			else
				continue;
		}

		output << j + 1 << ',' << glist[j].name << ',' << glist[j].matric << endl;
	}

	output.close();

	system("cls");

	cout << "****************************\n";

	cout << "Output processing succeeded.\n";

	cout << "****************************\n";
}