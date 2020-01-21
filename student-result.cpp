#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
#define size 50
struct student
{
	int regnum;
	string name;
	int marks[3];
	int total;
	char grade;
	float percentage;
};
void input(student array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Enter registration number of " << i + 1 << " Student:";
		cin >> array[i].regnum;
		while ((array[i].regnum<0) || (array[i].regnum>999999999))
		{
			cout << "Error ! Enter valid registrarion number between(1-999999999).\n";
			cout << "Enter registration number : ";
			cin >> array[i].regnum;
		}
		cout << "Enter name of " << i + 1 << " Student:";
		cin.ignore();
		getline(cin, array[i].name);
		for (int j = 0; j < 3; j++)
		{
			cout << "Enter subject " << j + 1 << " marks of " << array[i].regnum << " : ";
			cin >> array[i].marks[j];
			while ((array[i].marks[j]<0) || (array[i].marks[j]>100))
			{
				cout << "Error ! Enter marks between (1-100).\n";
				cout << "Enter marks : ";
				cin >> array[i].marks[j];
			}
		}
	}
}
void calculation(student array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		array[i].total = 0;
		for (int j = 0; j < 3; j++)
		{
			array[i].total += array[i].marks[i];
		}
		array[i].percentage = (static_cast<float>(array[i].total) / 3);
		if (array[i].percentage >= 80)
			array[i].grade = 'A';
		else if (array[i].percentage >= 70)
			array[i].grade = 'B';
		else if (array[i].percentage >= 60)
			array[i].grade = 'C';
		else if (array[i].percentage >= 50)
			array[i].grade = 'D';
		else if (array[i].percentage < 50)
			array[i].grade = 'F';
	}
}
void sorting(student array[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (array[i].regnum>array[j].regnum)
			{
				swap(array[i].regnum, array[j].regnum);
				swap(array[i].name, array[j].name);
				for (int k = 0; k < 3; k++)
				{
					swap(array[i].marks[k], array[j].marks[k]);
				}
				swap(array[i].total, array[j].total);
				swap(array[i].percentage, array[j].percentage);
				swap(array[i].grade, array[j].grade);
			}
		}
	}
}
void deletion(student array[], int &n)
{
	int num;
	cout << "Enter the registration number you want to remove from class:";
	cin >> num;
	while ((num<0) || (num>999999999))
	{
		cout << "Error ! Enter valid registrarion number between(1-999999999).\n";
		cout << "Enter registration number : ";
		cin >> num;
	}
	for (int i = 0; i < n; i++)
	{
		if (array[i].regnum == num)
		{
			for (int j = i; j < (n - 1); j++)
			{
				array[j].regnum = array[j + 1].regnum;
				array[j].name = array[j + 1].name;
				for (int k = 0; k < 3; k++)
				{
					array[j].marks[k] = array[j + 1].marks[k];
				}
				array[j].total = array[j + 1].total;
				array[j].percentage = array[j + 1].percentage;
				array[j].grade = array[j + 1].grade;
			}
			n--;
			break;
		}
	}
}
void insertion(student array[], int &n)
{
	int m;
	cout << "How many students you want to insert : ";
	cin >> m;
	while (m < 0)
	{
		cout << "Enter valide number: ";
		cin >> m;
	}
	for (int i = n; i < (n + m); i++)
	{
		cout << "Enter registration number of " << i + 1 << " Student:";
		cin >> array[i].regnum;
		while ((array[i].regnum<0) || (array[i].regnum>999999999))
		{
			cout << "Error ! Enter valid registrarion number between(1-999999999).\n";
			cout << "Enter registration number : ";
			cin >> array[i].regnum;
		}
		cout << "Enter name of " << i + 1 << " Student:";
		cin.ignore();
		getline(cin, array[i].name);
		for (int j = 0; j < 3; j++)
		{
			cout << "Enter subject " << j + 1 << " marks of " << array[i].regnum << " : ";
			cin >> array[i].marks[j];
			while ((array[i].marks[j]<0) || (array[i].marks[j]>100))
			{
				cout << "Error ! Enter marks between (1-100).\n";
				cout << "Enter marks : ";
				cin >> array[i].marks[j];
			}
		}
	}
	n = n + m;
	calculation(array, n);
	sorting(array, n);
}
void searching(student array[], int n)
{
	int search_regNumber; int flage = 1; int i;
	cout << "Enter registration number you want to search : ";
	cin >> search_regNumber;
	while ((search_regNumber<0) || (search_regNumber>999999999))
	{
		cout << "Invalid Registration number.\nEnter registration number: ";
		cin >> search_regNumber;
	}
	for (i = 0; i < n; i++)
	{
		if (search_regNumber == array[i].regnum)
		{
			flage += 1;
			break;
		}
		else if (flage == 2)
			cout << "Registration number not found." << endl;
	}
	cout << "|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%---- RESULT ----%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
	cout << "|    " << setw(20) << left << "regno." << setw(14) << left << "Name" << setw(10) << left << "S1" << setw(10) << left << "S2" << setw(10) << left << "S3" << setw(10) << left << "total" << setw(15) << left << "percentege" << setw(8) << left << "grade" << setw(1) << right << "|" << endl;
	cout << "|    " << setw(9) << left << array[i].regnum << setw(25) << left << array[i].name;
	for (int j = 0; j < 3; j++)
	{
		cout << setw(10) << left << array[i].marks[j];
	}
	cout << " " << setw(13) << left << array[i].total << setw(13) << left << array[i].percentage << array[i].grade << setw(6) << right << "|" << endl;
	cout << "|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
}
void display(student array[], int n)
{
	cout << "|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%---- RESULT ----%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
	cout << "|    " << setw(20) << left << "regno." << setw(14) << left << "Name" << setw(10) << left << "S1" << setw(10) << left << "S2" << setw(10) << left << "S3" << setw(10) << left << "total" << setw(15) << left << "percentege" << setw(8) << left << "grade" << setw(1) << right << "|" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "|    " << setw(9) << left << array[i].regnum << setw(25) << left << array[i].name;
		for (int j = 0; j < 3; j++)
		{
			cout << setw(10) << left << array[i].marks[j];
		}
		cout << " " << setw(13) << left << array[i].total << setw(13) << left << array[i].percentage << array[i].grade << setw(6) << right << "|" << endl;
	}
	cout << "|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
}
inline void maneu()
{
	cout << "%%%%%%%%%%%%%%% --- MANEU---- %%%%%%%%%%%%%%%%%%%%" << endl;
	cout << "| Press 1 to enter the data.                     |" << endl;
	cout << "| Press 2 to Process the data.                   |" << endl;
	cout << "| Press 3 to Sort the data (Acending order).     |" << endl;
	cout << "| Press 4 to Remove any studend from list.       |" << endl;
	cout << "| Press 5 to Add any Student in list.            |" << endl;
	cout << "| Press 6 to search the student.                 |" << endl;
	cout << "| Press 7 or Display the data.                   |" << endl;
	cout << "| Press Y Or y to exit the program.              |" << endl;
	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
}
int main()
{
	student array[size];
	int n;
	char choice;
	cout << "This Program will Calculate and disply the result of class." << endl;
	cout << "How many students (Data) you want to enter :";
	cin >> n;
	while (n<0 || n>50)
	{
		cout << "Error ! Enter valuse between 1-50 : ";
		cin >> n;
	}
	int flage = 0;
	do
	{
		maneu();
		cout << "Enter Your Choice : ";
		cin >> choice;
		if (choice == 'Y' || choice == 'y')
			break;
		while ((int(choice)<49 || int(choice)>55))
		{
			cout << "You are entering wrong chracter.\n";
			cout << "Error! Enter valid Charcter between 1-6 : ";
			cin >> choice;
		}
		switch (choice)
		{
		case '1':
			input(array, n);
			flage += 1;
			break;
		case '2':
			if (flage == 1)
			{
				calculation(array, n);
				flage += 1;
			}
			else
			{
				cout << "Enter data before processing." << endl;
			}
			break;
		case '3':
			if (flage == 2)
			{
				sorting(array, n);
			}
			else
			{
				cout << "Error! Enter the data and process it before sorting.\n";
				cout << "Try again latter." << endl;
			}
			break;
		case '4':
			if (flage == 2)
			{
				deletion(array, n);
			}
			else
			{
				cout << "Error! Enter the data and process it before deletion.\n";
				cout << "Try again latter." << endl;
			}
			break;
		case '5':
			if (flage == 2)
			{
				insertion(array, n);
			}
			else
			{
				cout << "Error! Enter data first bafore insertion.\n";
				cout << "Try again latter." << endl;
			}
			break;
		case '6':
			if (flage == 2)
			{
				searching(array, n);
			}
			else
			{
				cout << "Error! Enter data and process it befor searching:" << endl;
			}
			break;
		case '7':
			if (flage == 2)
			{
				display(array, n);
			}
			else
			{
				cout << "Error! Enter the data and process it before Display.\n";
				cout << "Try again latter." << endl;
			}
			break;
		default:
			cout << "Error ! Please try again latter:" << endl;
		}
	} while ((choice > 0) || (choice < 8));
	system("pause");
	return 0;
}
