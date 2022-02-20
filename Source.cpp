#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

class List
{
	Node* Head;
	Node* Tail;
	int Count = 0;
public:
	virtual void Print() = 0;
	virtual void Add(int data) = 0;
	virtual void Del() = 0;
	virtual void DellAll() = 0;
	virtual int GetCount() = 0;
};

class Steck:public List
{
	Node* Head;
	Node* Tail;
	int Count = 0;

public:

	Steck()
	{
		Head = Tail = NULL;
		Count = 0;
	}

	~Steck()
	{
		DellAll();
	}

	virtual void Print()
	{
		Node* temp = Head;
		while (temp != 0)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << "\n\n";
	}

	virtual void Add(int data)
	{
		Node* temp = new Node;
		temp->data = data;
		temp->next = NULL;
		if (Head != NULL)
		{
			Tail->next = temp;
			Tail = temp;
		}
		else
		{
			Head = Tail = temp;
		}
		Count++;
	}

	virtual void Del()
	{
		Node* temp = Head;
		Head = Head->next;
		delete[]temp;
		Count--;
	}

	virtual void DellAll()
	{
		while (Head != 0)
		{
			Del();
		}
	}

	virtual int GetCount()
	{
		return Count;
	}

};

class Queue :public List
{
	int* Wait;
	int MaxQueueLength;
	int QueueLength;

public:

	Queue()
	{
		Wait = nullptr;
		MaxQueueLength = 0;
		QueueLength = 0;
	}

	Queue(int m)
	{
		MaxQueueLength = m;
		Wait = new int[MaxQueueLength];
		QueueLength = 0;
	}

	~Queue()
	{
		delete[]Wait;

	}

	virtual void Add(int c)
	{
		Wait[QueueLength] = c;
		QueueLength++;
	}

	virtual void Del()
	{

		for (int i = 0; i < QueueLength; i++)
		{
			Wait[i] = Wait[i + 1];
		}
		QueueLength--;
	}

	virtual void DellAll()
	{
		QueueLength = 0;
	}

	virtual int GetCount()
	{
		return QueueLength;
	}

	virtual void Print()
	{
		for (int i = 0; i < QueueLength; i++)
		{
			cout << Wait[i] << " ";

		}
		cout << "\n";
	}

};

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	cout << "\n—тек\n";
	Steck steck;
	for (int i = 0; i < 10; i++)
	{
		steck.Add(rand() % 10 + 1);
	}
	steck.Print();

	for (int i = 0; i < 10; i++)
	{
		steck.Del();
		cout << i + 1 << " Ёлемент извлечен осталось " << steck.GetCount() << "\n\n";
	}

	cout << "\nќчередь\n";
	Queue ochered(10);
	for (int i = 0; i < 10; i++)
	{
		ochered.Add(rand() % 10 + 1);
	}

	ochered.Print();
	cout << "\n";
	for (int i = 0; i < 10; i++)
	{
		ochered.Del();
		cout << i + 1 << " Ёлемент извлечен осталось " << ochered.GetCount() << "\n\n";
	}

	return 0;
}