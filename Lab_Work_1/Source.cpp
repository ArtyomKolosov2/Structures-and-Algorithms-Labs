#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

struct AnalisysResult
{
	int amount;
	double percent;
};

enum OperationCode { NegativeNums = -1, Zero = 0, PositiveNums = 1 };

void Show_Array(int* arr, int size);

int Find_Sum(int*, int);

bool Get_Operation_Result(int, int);

AnalisysResult Find_Array_Percent(int*, int, int);

int* Get_Random_Array(int, int start = 0, int end = 100);

int main()
{

	srand(time(NULL));
	int array_size = 1000;
	int* arr = Get_Random_Array(array_size, -100, 100);
	Show_Array(arr, array_size);
	cout << "Sum of negative numbers = " << Find_Sum(arr, array_size) << endl;;
	AnalisysResult result_one = Find_Array_Percent(arr, array_size, NegativeNums);
	AnalisysResult result_two = Find_Array_Percent(arr, array_size, Zero);
	AnalisysResult result_three = Find_Array_Percent(arr, array_size, PositiveNums);
	cout << "1.Negative Nums Percent - " << result_one.percent << "%, Amount - " << result_one.amount << endl;
	cout << "2.Zero Nums Percent - " << result_two.percent << "%, Amount - " << result_two.amount << endl;
	cout << "3.Positive Nums Percent - " << result_three.percent << "%, Amount - " << result_three.amount << endl;
	delete[] arr;
	system("pause");
	return 0;
}

void Show_Array(int *arr, int size) 
{
	for (int i = 0; i < size; i++) 
	{
		if (i % 10 == 0)
		{
			cout << endl;
		}
		cout << fixed << setprecision(4) << arr[i] << ' ';
	}
	cout << endl;
}

int Find_Sum(int* arr, int size)
{
	int result = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < 0)
		{
			result += arr[i];
		}
	}
	return result;
}

bool Get_Operation_Result(int num, int operationCode)
{
	bool result = 0;
	switch (operationCode)
	{
	case NegativeNums:
		result = num < 0;
		break;
	case Zero:
		result = num == 0;
		break;
	case PositiveNums:
		result = num > 0;
		break;
	default:
		throw new exception("Error: Incorrect code!");
	}
	return result;
}

AnalisysResult Find_Array_Percent(int* arr, int size, int operationCode)
{
	AnalisysResult result;
	int amount = 0;
	double onePercent = (double)100 / size;
	double percentResult = 0;
	for (int i = 0; i < size; i++)
	{
		if (Get_Operation_Result(arr[i], operationCode))
		{
			amount++;
			percentResult += onePercent;
		}
	}
	result.amount = amount;
	result.percent = percentResult;
	return result;

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