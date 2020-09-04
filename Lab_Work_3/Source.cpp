#include <iostream>

using namespace std;

template<class T> struct Node 
{
	T Data;
	Node* next;
	Node* previous;
};

template<class T> struct TwoWayLinkedList 
{
	Node<T>* FirstNode;

	int Length() 
	{
		int result = 0;
		if (FirstNode != nullptr) 
		{
			Node<T>* temp = FirstNode;
			do
			{
				result++;
				temp = temp->next;
			} while (temp != FirstNode)
		}
	}

	void PrintNode() 
	{
		if (FirstNode != nullptr)
		{
			Node<T>* temp = FirstNode;
			do 
			{
				cout << temp->Data << endl;
				temp = temp->next;
			} while(temp != FirstNode)
		}
	}

	void AddToEnd(T data) 
	{

	}

	void DeleteList() 
	{
		if (FirstNode != nullptr)
		{
			Node<T>* temp = FirstNode;
			Node<T>* delete_temp;
			do
			{
				delete_temp = temp;
				temp = temp->next;
				delete temp;
			} while (temp != nullptr)
		}
	}
};

int main() 
{
	return 0;
}