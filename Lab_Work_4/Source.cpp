#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

void Show_Array(int* arr, int size, char split=' ');

void Print_Splitter(int amount = 10, bool flag=false);

void Selection_Sort(int *, int size);

int* Get_Random_Array(int, int start = 0, int end = 100);

int main() 
{
	system("chcp 1251");
	srand(time(NULL));
	int size = 10;
	for (; size < 110; size += 10) {
		cout << "Array size " << size << endl;
		int* my_array = Get_Random_Array(size, -100, 100);
		Show_Array(my_array, size);
		Selection_Sort(my_array, size);
		Show_Array(my_array, size);
		delete[] my_array;
		system("pause");
		system("cls");
	}
	return 0;
}

void Show_Array(int *arr, int size, char split) {
	Print_Splitter();
	for (int i = 0; i < size; i++) {
		cout << fixed << setprecision(2) << arr[i] << split;
	}
	cout << endl;
	Print_Splitter();
}

void Print_Splitter(int amount, bool flag) 
{

	for (int i = 0; i < amount; i++) 
	{
		if (flag) 
		{
			cout << "****";
		}
		else 
		{
			cout << "====";
		}
	}
	cout << endl;
}

void Selection_Sort(int* arr, int size) 
{
	unsigned int 
		change = 0,
		compare = 0;
	for (int i = 0; i < size - 1; i++) 
	{
		int small = i;
		for (int j = i + 1; j < size; j++) 
		{
			if (arr[j] < arr[small] ) 
			{
				small = j;
			}
			compare++;
		}
		swap(arr[i], arr[small]);
		change++;
	}
	cout << "Selection sort:\n";
	cout << "Кол-во сравнений: " << compare << endl;
	cout << "Кол-во изменений: " << change << endl;
}

int* Get_Random_Array(int size, int start, int end)
{
	int* new_array = new int[size];
	if (start < 0)
	{
		end *= 2;
	}
	for (int i = 0; i < size; i++)
	{
		new_array[i] = start + rand() % end;
	}
	return new_array;
}