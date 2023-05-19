#include "AdjcencyList.h"

AdjcencyList::AdjcencyList(int numberOfVertecies) 
{
	this->numberOfVertecies = numberOfVertecies;
	adjecnyList = new VerteciesLinqedList[numberOfVertecies];
}

AdjcencyList::~AdjcencyList() 
{
	delete[] adjecnyList;
}

void AdjcencyList::AddEdge(int a, int b, int weight) 
{
	adjecnyList[a].Push(b, weight);
}

void AdjcencyList::PrintGraph() 
{
	for (int i = 0; i < numberOfVertecies; i++)
	{
		int* list2array = adjecnyList[i].ToArray();
		int j = 0;

		while (list2array[j] != - 1)
		{
			std::cout << i << "->" << list2array[j] << " ";
			j++;
		}

		std::cout << std::endl;
	}

}

int AdjcencyList::GetEdgeWeight(int a, int b) 
{
	VerteciesLinqedListNode* node = adjecnyList[a].SerchForNode(b);
	if (node != nullptr)
		return node->weight;
	else
		return -1;
}

int AdjcencyList::NumberOfVertecies() 
{
	return numberOfVertecies;
}

int * AdjcencyList::GetNeighbours(int index) 
{
	return adjecnyList[index].ToArray();
}