#ifndef LL_H
#define LL_H
#include <iostream>
using namespace std;

struct NodeL
{
	int Data;
	NodeL* Next;
	NodeL* EofNext;
	NodeL* Down;
	bool visited;

	NodeL(int d)
	{
		Data = d;
		Next = NULL;
		EofNext = NULL;
		Down = NULL;
		visited = false;
	}
};

class LinkedList
{
private:
	NodeL* Head;
	NodeL* Tail;
public:
	LinkedList()
	{
		Head = NULL;
		Tail = NULL;
	}

	NodeL* getHead()
	{
		return Head;
	}

	NodeL* getTail()
	{
		return Tail;
	}

	void InsertN(NodeL* Index, int V)
	{
		//NodeL* ptr = Head;
		//ptr = Index;
		//while (ptr->Next != NULL)
		//{
		//	ptr = ptr->Next;
		//}
		//NodeL* temp = new NodeL(V);
		//ptr->Next = temp;
		NodeL* ptr = Index;


		NodeL* temp = new NodeL(V);
		if (ptr->EofNext != NULL)
		{
			ptr->EofNext->Next = temp;
			ptr->EofNext = ptr->EofNext->Next;
		};
	}

	NodeL* InsertD(int V)
	{
		if (Head == NULL)
		{
			Head = new NodeL(V);
			Tail = Head;
			Head->EofNext = Head;
			return Head;
		}
		else
		{
			NodeL* ptr = Tail;
			NodeL* temp = new NodeL(V);
			Tail->Down = temp;
			Tail = Tail->Down;
			Tail->EofNext = Tail;
			return Tail;
		}

	}

	void Display()
	{
		NodeL* ptr = Head;
		while (ptr != NULL)
		{
			NodeL* ptr2 = ptr;
			while (ptr2 != NULL)
			{
				cout << ptr2->Data << " ";
				ptr2 = ptr2->Next;
			}
			ptr = ptr->Down;
			cout << endl;
		}
	}

	//~LinkedList()
	//{
	//	NodeL* ptr = Head;
	//	while (ptr != NULL)
	//	{


	//		NodeL* ptrr = ptr->Down;
	//		NodeL* ptr2 = ptr;
	//		delete ptr;
	//		while (ptr2 != NULL)
	//		{
	//			NodeL* ptr22 = ptr2->Next;
	//			delete ptr2;
	//			ptr2 = ptr22;

	//		}

	//		ptr = ptrr;
	//	}
	//}
};

#endif
