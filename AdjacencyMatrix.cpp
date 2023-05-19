#include "AdjacencyMatrix.h"

AdjacencyMatrix::AdjacencyMatrix(int numberOfVertecies)
{
	_numberOfVertecies = numberOfVertecies;
	_neighbourMatrix = new int*[_numberOfVertecies];

	for (int i = 0; i < _numberOfVertecies; i++)
	{
		_neighbourMatrix[i] = new int[_numberOfVertecies];
		for (int j = 0; j < _numberOfVertecies; j++)
		{
			_neighbourMatrix[i][j] = -1;
		}
	}
}

AdjacencyMatrix::~AdjacencyMatrix()
{
	for (int i = 0; i < _numberOfVertecies; i++)
	{
		delete[] _neighbourMatrix[i];
	}

	delete[] _neighbourMatrix;
}

void AdjacencyMatrix::AddEdge(int a, int b, int weight)
{
	_neighbourMatrix[a][b] = weight;
}


int* AdjacencyMatrix::GetNeighbours(int a)
{
	int* neighbours = new int[_numberOfVertecies + 1];
	int j = 0;
	

	for (int i = 0; i < _numberOfVertecies; i++)
	{
		if (_neighbourMatrix[a][i] != -1) 
		{
			neighbours[j++] = i;
		}
	}

	neighbours[j] = -1;
	return neighbours;

}

int AdjacencyMatrix::NumberOfVertecies()
{
	return _numberOfVertecies;
}

int AdjacencyMatrix::GetEdgeWeight(int a, int b)
{
	return _neighbourMatrix[a][b];
}

void AdjacencyMatrix::PrintGraph()
{
	
	for (int i = 0; i < _numberOfVertecies; i++)
	{
		for (int j = 0; j < _numberOfVertecies; j++)
		{
			std::cout << _neighbourMatrix[i][j] << " ";
		}

		std::cout << std::endl;
	}
	
}

