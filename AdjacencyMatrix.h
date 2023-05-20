#pragma once
#include <iostream>
#include "Graph.h"


class AdjacencyMatrix : public Graph
{
	private:
		int** _neighbourMatrix;
		int _numberOfVertecies =-1;

	public:
			AdjacencyMatrix(int numberOfVertecies, int** values);
			~AdjacencyMatrix();

			void PrintGraph();
			void AddEdge(int a, int b, int weight) override;
			int  NumberOfVertecies() override;
			int	 GetEdgeWeight(int a, int b) override;
			int* GetNeighbours(int index) override;

};

