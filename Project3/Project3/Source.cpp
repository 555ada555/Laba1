#include <iostream>
#include <fstream>
#define N 3
using namespace std;

struct Data
{
	char surname[32], name[32], addres[32];
	int	phoneNumber;
	char gender[32];
	int course;
	char group[32];

};
void CreateData(struct Data *student, int i)
{
	for (int j = 0; j < i; j++)
	{
		Data *st = &student[j];
		cout << endl << "STUDENT" << j + 1 << endl;
		cout << "Surname : " << endl;
		cin >> st->surname;
		cout << "Name : " << endl;
		cin >> st->name;
		cout << "Adress :" << endl;
		cin >> st->addres;
		cout << "Phone number : " << endl;
		cin >> st->phoneNumber;
		cout << "Gender : " << endl;
		cin >> st->gender;
		cout << "Course : " << endl;
		cin >> st->course;
		cout << "Group : " << endl;
		cin >> st->group;
	}
}
void RW(struct Data *student, int i, int j) //Функція запису RW() у типізований файл INFO.TXT у вигляді структури
{
	ofstream info;
	info.open("INFO.TXT");
	if (!info.is_open())
	{
		cout << "ERROR";
	}
	else
	{
		for (j = 0; j < i; j++)
		{
			Data *st = &student[j];
			info << st->surname << " " << st->name << " " << st->addres << " " << st->phoneNumber << endl;
		}
	}
	info.close();
}


void RD(struct Data *student1, int i, int m) //Функція читання RD() з файлу INFO.TXT для виведення вмысту файлу на екран
{
	struct Data t1;
	char street[32];
	ifstream file;
	file.open("INFO.TXT");
	if (!file.is_open())
	{
		cout << "ERROR";
	}
	else
	{
		for (int j = 0; j < i; j++)
		{
			Data *st = &student1[j];
			file >> st->surname;

			file >> st->name;

			file >> st->addres;

			file >> st->phoneNumber;
		}

		cout << endl << " To search, enter an address : " << endl;
		cin >> street;
		for (int n = 0; n < i; n++)
		{
			if (strstr(student1[n].addres, street) != NULL)
			{
				Data *st = &student1[n];
				cout << endl << st->surname << endl;

				cout << st->name << endl;

				cout << st->addres << endl;

				cout << st->phoneNumber << endl;

				m++;
			}
		}
	}
	cout << endl << "Results searching: " << m << endl;
	file.close();
}
void RW(struct Data *student, int i) //Функція запису RW() у типізований файл INFO.DAT у вигляді структури
{
	struct Data t1;
	ofstream info;
	info.open("INFO.DAT");
	if (!info.is_open())
	{
		cout << "ERROR";
	}
	else
	{
		for (int n = 0; n < i; n++)
			for (int m = n + 1; m < i; m++)
				if (strcmp(student[n].surname, student[m].surname) > 0)
				{
					t1 = student[n];
					student[n] = student[m];
					student[m] = t1;
				}
		for (int j = 0; j < i; j++)
		{
			Data *st = &student[j];
			info << st->surname << " " << st->name << " " << st->gender << " " << st->course << " " << st->group << endl;;
		}
	}
	info.close();
}
void RD(struct Data *student1, int i) //Функція читання RD() з файлу INFO.DAT для виведення вмысту файлу на екран
{

	ifstream file;
	file.open("INFO.DAT");
	if (!file.is_open())
	{
		cout << "ERROR";
	}
	else
	{

		for (int j = 0; j < i; j++)
		{
			Data *st = &student1[j];
			file >> st->surname;

			file >> st->name;

			file >> st->gender;

			file >> st->course;

			file >> st->group;

		}
		for (int n = 0; n < i; n++)
		{
			Data *st = &student1[n];
			cout << endl << st->surname << endl;

			cout << st->name << endl;

			cout << st->gender << endl;

			cout << st->course << endl;

			cout << st->group << endl;
		}
	}
	file.close();
}
void main()
{
	struct Data student[N];
	CreateData(student, N);
	RW(student, N, 0);
	RW(student, N);
	RD(student, N);
	RD(student, N, 0);
	getchar();
	cin.get();
}