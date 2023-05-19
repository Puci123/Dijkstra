#pragma once
#include <limits.h>
#include <iostream>
#include "Graph.h"

class IncidenceMatrix : Graph
{
	private:
		int** _incidenceMatrix;
		int _numberOfVertecies = -1;
		int _edgeCount = 0;

	public:
		IncidenceMatrix(int numberOfVertecies);
		~IncidenceMatrix();

		void PrintGraph();
		void AddEdge(int a, int b, int weight) override;
		int  NumberOfVertecies() override;
		int	 GetEdgeWeight(int a, int b) override;
		int* GetNeighbours(int index) override;

	
};

