#include <iostream>

using namespace std;

template<class T> struct Node 
{
public :Node(T data) 
	{
		Data = data;
	}
	T Data;
	Node* next;
	Node* previous;
};

template<class T> struct TwoWayLinkedList 
{
	Node<T>* FirstNode;
	Node<T>* Tail;
	int count;

	void Add(T data, int index) 
	{
		if (count != 0 && (index < 0 || index > count)) 
		{
			return;
		}
        if (index == count + 1)
        {
            AddToTail(data);
            return;
        }
        else if (index == 1)
        {
            AddToHead(data);
            return;
        }
        int i = 1;
		Node<T>* current = FirstNode;

        while (i < index)
        {
            current = current->next;
            i++;
        }
        Node<T>* previousCurrentElement = current->previous;
        Node<T>* newNode = new Node<T>(data);
        if (previousCurrentElement != nullptr && count != 1)
            previousCurrentElement->next = newNode;

        newNode->next = current;
        newNode->previous = previousCurrentElement;
        current->previous = newNode;
        count++;
	}

	void DeleteList() 
	{
		Node<T>* deleteElement, *current = FirstNode;
		while (current != Tail) 
		{
			deleteElement = current;
			current = current->next;
			delete deleteElement;
		}
		delete current;
	}

	void AddToHead(T data) 
	{
		Node<T>* newNode = new Node<T>(data);
		newNode->previous = nullptr;
		newNode->next = FirstNode;
		if (FirstNode != nullptr) 
		{
			FirstNode->previous = newNode;
		}
		if (count == 0) 
		{
			FirstNode = Tail = newNode;
		}
		else 
		{
			FirstNode = newNode;
		}
		count++;
	}

	void AddToTail(T data)
	{
		Node<T>* newNode = new Node<T>(data);
		newNode->next = nullptr;
		newNode->previous = Tail;
		if (Tail != nullptr)
		{
			Tail->next = newNode;
		}
		if (count == 0)
		{
			Tail = FirstNode = newNode;
		}
		else
		{
			Tail = newNode;
		}
		count++;
	}

	void Print() 
	{
		Node<T>* current = FirstNode;
		while (current != Tail) 
		{
			cout << current->Data << endl;
			current = current->next;
		}
		cout << current->Data << endl;
	}

	/*Node<T>* GetNode(int index) 
	{
		Node<T>* current = FirstNode;
		if (index == 1) 
		{
			retru
		}
		while (current != Tail)
		{
			cout << current->Data << endl;
			current = current->next;
		}
		cout << current->Data << endl;
	}*/

	
};

int main() 
{
	TwoWayLinkedList<string>* List = new TwoWayLinkedList<string>();
	List->Add(string("hello world!1"), 1);
	List->Add(string("hello world!2"), 1);
	List->Add(string("hello world!3"), 1);
	List->Print();
	List->DeleteList();
	return 0;
}