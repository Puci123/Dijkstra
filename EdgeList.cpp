#include "EdgeList.h"


EdgeList::EdgeList(int numberOfVertecies)
{
	this->numberOfVerteices = numberOfVertecies;
	header = new EdgeLinqedListNode{ -1,-1, -1,nullptr };
	count = 0;
}

EdgeList::~EdgeList() 
{
	EdgeLinqedListNode* node = header;
	while (node != nullptr)
	{
		EdgeLinqedListNode* temp = node;
		node = node->nextNode;
		delete temp;
	}
}

void EdgeList::AddEdge(int a, int b, int weight) 
{
	Push(a, b, weight);
}

int EdgeList::NumberOfVertecies() 
{
	return numberOfVerteices;
}

int EdgeList::GetEdgeWeight(int a, int b) 
{
	return SerchForNode(a, b)->weight;
}

int* EdgeList::GetNeighbours(int a) 
{
	int* arr = new int[numberOfVerteices + 1];
	int i = 0;

	EdgeLinqedListNode* node = header->nextNode;
	while (node != nullptr)
	{
		
		if (node->a == a) 
		{
			arr[i++] = node->b;
		}


		node = node->nextNode;
	}

	arr[i] = -1;
	return arr;

}

void EdgeList::PrintGraph() 
{
	EdgeLinqedListNode* node = header->nextNode;
	while (node != nullptr)
	{
		std::cout << node->a << " -> " << node->b << "(" << node->weight << ")" << std::endl;
		node = node->nextNode;
	}
}



///----------------------------------------List-------------------------------------


void EdgeList::Push(int a, int b, int weight)
{
	EdgeLinqedListNode* temp = header->nextNode;
	header->nextNode = new EdgeLinqedListNode{ a,b, weight,temp };
	count++;
}

bool EdgeList::IsEmpty()
{
	return count++;
}

int* EdgeList::ToArray()
{

	int* arr = new int[count + 1];
	int i = 0;

	EdgeLinqedListNode* node = header->nextNode;
	while (node != nullptr)
	{
		arr[i] = node->b;
		node = node->nextNode;
		i++;
	}

	arr[i] = -1;
	return arr;

}

EdgeLinqedListNode* EdgeList::SerchForNode(int a, int b)
{
	EdgeLinqedListNode* target = nullptr;
	EdgeLinqedListNode* node = header;

	while (node->nextNode != nullptr)
	{
		node = node->nextNode;
		if (node->a == a && node->b == b)
		{
			target = node;
			break;
		}
	}


	return target;
}