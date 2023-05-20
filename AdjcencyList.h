#pragma once
#include "Graph.h"
#include "VerteciesLinqedList.h"
#include <iostream>

class AdjcencyList : Graph
{
	public:
		 AdjcencyList(int numberOfVertecies, int** values);
		 ~AdjcencyList();
		 void PrintGraph() override;
		 void AddEdge(int a, int b, int weight) override;
		 int NumberOfVertecies() override;
		 int GetEdgeWeight(int a, int b) override;
		 int* GetNeighbours(int index) override;
	private:
		VerteciesLinqedList* adjecnyList;
		int numberOfVertecies;
};

