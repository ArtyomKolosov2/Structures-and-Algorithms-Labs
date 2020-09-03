#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <fstream>

using namespace std;

const int MARKS_SIZE = 5,
		  SURNAME_OFILE_SIZE = 20,
	      GROUP_OFILE_SIZE = 5,
		  MARKS_OFILE_SIZE = 15;

struct Student 
{
	string surname;
	int group_number;
	int marks[MARKS_SIZE];
};

int Get_Random_Number(int, int);

void Show_Student_Array(Student*, int);

double Get_Average_Mark(Student);

void Sort_Students_Array(Student*, int);

void Show_Student(Student);

void Print_Splitter(int, char split_symbol='=');

void Fill_With_Random_Data(Student*, int);

void Write_Students_To_File(ofstream&, Student*, int);

void Write_To_File(ofstream&, int*, int, int);

void Write_To_File(ofstream& , int , int );

void Write_To_File(ofstream&, string, int);


int main() 
{
	srand((unsigned int)(time(NULL)));
	int size = 10;
	Student *students = new Student[size];
	ofstream file_one("students.txt");

	Fill_With_Random_Data(students, size);
	Show_Student_Array(students, size);

	Write_Students_To_File(file_one, students, size);
	file_one.close();

	ofstream file_two("students1.txt");
	Sort_Students_Array(students, size);
	Write_Students_To_File(file_two, students, size);
	delete[] students;
	return 0;
}

int Get_Random_Number(int start, int end) 
{
	const double fraction = 1.0 / ((double)(RAND_MAX) + 1.0);
	return (int)(rand() * fraction * ((double)end - start + 1) + start);
}

void Show_Student_Array(Student* students, int size)
{
	bool flag = false;
	double average_mark_limit = 4.0;
	for (int i = 0; i < size; i++) 
	{
		double average_mark = Get_Average_Mark(students[i]);
		if (average_mark >= average_mark_limit) 
		{
			cout << fixed << setprecision(2) << "Average mark " << average_mark << endl;
			Show_Student(students[i]);
			flag = true;
		}
	}
	if (!flag) 
	{
		cout << "There are no students with average mark more then " << average_mark_limit << endl;
	}
}

double Get_Average_Mark(Student student) 
{
	int mark_sum=0;
	for (int i = 0; i < MARKS_SIZE; i++) 
	{
		mark_sum += student.marks[i];
	}
	return (double)mark_sum / MARKS_SIZE;
}

void Sort_Students_Array(Student* students, int size) 
{
	for (int i = 0; i < size; i++) 
	{
		for (int j = i+1; j < size; j++) 
		{
			if (students[i].group_number > students[j].group_number) 
			{
				swap(students[i], students[j]);
			}
		}
	}
}

void Show_Student(Student student) 
{
	cout << "Surname: " << student.surname << endl;
	cout << "Group Number: " << student.group_number << endl;
	cout << "Marks: ";
	for (int j = 0; j < MARKS_SIZE; j++)
	{
		cout << fixed << setprecision(2) << student.marks[j] << ' ';
	}
	cout << endl;
	Print_Splitter(35);
}

void Print_Splitter(int split_size, char split_symbol) 
{
	for (int i = 0; i < split_size; i++) 
	{
		cout << split_symbol;
	}
	cout << endl;
}

void Fill_With_Random_Data(Student* students, int size) 
{
	int surnames_size = 15,
		group_number_start = 10000,
		group_number_end = 99999,
		mark_start = 1,
		mark_end = 10;
	string *surnames = new string[surnames_size]
	{
		"Kolosov",
		"Kuzmich",
		"House",
		"Katlinsky",
		"Sharp",
		"Jhonson",
		"Peterson",
		"Ivanov",
		"Wilson",
		"Black",
		"Trump",
		"Einstein",
		"Newton",
		"Svenson",
		"Lennon"
	};
	string* initials = new string[surnames_size]
	{
		"A.A.",
		"I.A.",
		"K.A.",
		"F.L.",
		"P.S.",
		"E.X.",
		"F.G.",
		"A.V.",
		"H.H.",
		"E.A.",
		"J.J.",
		"P.N.",
		"F.F.",
		"G.G.",
		"L.H."
	};
	for (int i = 0; i < size; i++) 
	{
		int rnd_index = Get_Random_Number(0, surnames_size-1);
		students[i].surname = surnames[rnd_index] +" "+ initials[rnd_index];
		students[i].group_number = Get_Random_Number(group_number_start, group_number_end);
		for (int j = 0; j < MARKS_SIZE; j++) 
		{
			students[i].marks[j] = Get_Random_Number(mark_start, mark_end);
		}
	}
	delete[] surnames;
	delete[] initials;
}

void Write_Students_To_File(ofstream&file_stream, Student* students, int size)
{
	for (int i = 0; i < size; i++)
	{ 
		Write_To_File(file_stream, students[i].surname, SURNAME_OFILE_SIZE);
		Write_To_File(file_stream, students[i].marks, MARKS_SIZE, MARKS_OFILE_SIZE);
		Write_To_File(file_stream, students[i].group_number, GROUP_OFILE_SIZE);
		file_stream << '\n';
	}
}

void Write_To_File(ofstream& file_stream, int* marks, int marks_size, int data_size) 
{
	for (int i = 0; i < marks_size; i++) 
	{
		file_stream << ' ' << marks[i];
	}
	file_stream << ' ';
}

void Write_To_File(ofstream& file_stream, int group_number, int data_size) 
{
	file_stream << group_number;
}

void Write_To_File(ofstream& file_stream, string data, int data_size) 
{
	for (int i = 0; i < data_size; i++) 
	{
		if (i > data.length()) {
			file_stream << ' ';
		}
		else
		{
			file_stream << data[i];
		}
	}
}

