#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int Find_Max_Even(int* arr, int size);

void Search(int* arr, int search_element, int size);

void Binary_Search(int* arr, int search_element, int size);

void Show_Array(int* arr, int size, char split = ' ');

void Print_Splitter(int amount = 10, bool flag = false);

void Selection_Sort(int*, int size);

int* Get_Random_Array(int, int start = 0, int end = 100);

int main()
{
	system("chcp 1251");
	srand(time(NULL));
	int size = 10;
	for (; size < 110; size += 10) {
		cout << "Array size " << size << endl;
		int* my_array = Get_Random_Array(size, -100, 100);
		int max_even = Find_Max_Even(my_array, size);
		Show_Array(my_array, size);
		Search(my_array, max_even, size);
		Selection_Sort(my_array, size);
		Show_Array(my_array, size);
		Binary_Search(my_array, max_even, size);
		delete[] my_array;
		system("pause");
		system("cls");
	}
	return 0;
}

int Find_Max_Even(int* arr, int size)
{
	int max_even = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] % 2 == 0 && max_even < arr[i])
		{
			max_even = arr[i];
		}
	}
	return max_even;
}

void Search(int* arr, int search_element, int size)
{
	int compare_count = 0;
	for (int i = 0; i < size; i++)
	{
		compare_count++;
		if (arr[i] == search_element)
		{
			cout << "Индекс искомого элемента ( " << search_element << " ) = " << i << endl
				<< "Кол-во сравнений в линейном поиске = " << compare_count << endl;
			break;
		}
	}
}

void Binary_Search(int* arr, int search_element, int size)
{
	cout << "Binary search:\n";
	int left = 0,
		right = size - 1,
		mid = 0,
		compare_count = 0;
	bool is_found = false;
	while (right >= left) {
		mid = left + (right - left) / 2;
		if (arr[mid] == search_element) {
			compare_count++;
			is_found = true;
			Print_Splitter(10, true);
			cout << "Результат поиска:\n";
			cout << "Индекс искомого элемента ( " << search_element << " ) = " << mid << endl
				<< "Кол-во сравнений в бинарном поиске = " << compare_count << endl;
			Print_Splitter(10, true);
			break;
		}
		if (arr[mid] > search_element)
		{
			compare_count += 2;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	if (!is_found)
	{
		cout << "Элемент " << search_element << " не найден!\n";
	}
}

void Show_Array(int* arr, int size, char split) {
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
			if (arr[j] < arr[small])
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