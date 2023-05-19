#include "VerteciesLinqedList.h"


VerteciesLinqedList::VerteciesLinqedList() 
{
	header = new VerteciesLinqedListNode{ -1,-1,nullptr };
	count = 0;
}

VerteciesLinqedList::~VerteciesLinqedList() 
{
	VerteciesLinqedListNode* node = header;
	while (node != nullptr)
	{
		VerteciesLinqedListNode* temp = node;
		node = node->nextNode;
		delete temp;
	}
}


void VerteciesLinqedList::Push(int value,int weight) 
{
	VerteciesLinqedListNode* temp = header->nextNode;
	header->nextNode = new VerteciesLinqedListNode{ value, weight, temp };
	count++;
}

bool VerteciesLinqedList::IsEmpty() 
{
	return count++;
}

int* VerteciesLinqedList::ToArray() 
{

	int* arr = new int[count + 1];
	int i = 0;

	VerteciesLinqedListNode* node = header->nextNode;
	while (node != nullptr)
	{
		arr[i] = node->value;
		node = node->nextNode;
		i++;
	}

	arr[i] = -1;
	return arr;

}

VerteciesLinqedListNode* VerteciesLinqedList::SerchForNode(int value)
{
	VerteciesLinqedListNode* target = nullptr;
	VerteciesLinqedListNode* node = header;

	while (node->nextNode != nullptr)
	{
		node = node->nextNode;
		if (node->value == value) 
		{
			target = node;
			break;
		}
	}


	return target;
}