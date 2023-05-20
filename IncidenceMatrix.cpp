#include "IncidenceMatrix.h"




IncidenceMatrix::IncidenceMatrix(int numberOfVertecies, int edgeCount, int** values) 
{
	_edgeCount = edgeCount;
	_numberOfVertecies = numberOfVertecies;

	_incidenceMatrix = new int* [_edgeCount];
	for (int i = 0; i < _edgeCount; i++)
	{
		_incidenceMatrix[i] = new int[numberOfVertecies];
	}

	Construct(numberOfVertecies, values);

}

IncidenceMatrix::~IncidenceMatrix() 
{
	for (int i = 0; i < _edgeCount; i++)
	{
		delete[] _incidenceMatrix[i];
	}

	delete[] _incidenceMatrix;
}

void IncidenceMatrix::AddEdge(int a, int b, int weight) 
{
	if (currentEdege < _edgeCount)
	{
		_incidenceMatrix[currentEdege][a] = weight;
		_incidenceMatrix[currentEdege][b] = -weight;
		currentEdege++;
	}
}

int IncidenceMatrix::NumberOfVertecies()
{
	return _numberOfVertecies;
}

int IncidenceMatrix::GetEdgeWeight(int a, int b) 
{
	for (int i = 0; i < _edgeCount; i++)
	{
		if (_incidenceMatrix[i][a] > 0 && _incidenceMatrix[i][a] == -_incidenceMatrix[i][b])
		{
			if(_incidenceMatrix[i][a] < 0)
				return -_incidenceMatrix[i][a];
			
			return _incidenceMatrix[i][a];
		}
	}
}

int* IncidenceMatrix::GetNeighbours(int a) 
{
	int* neighbours = new int[_numberOfVertecies + 1];
	int j = 0;

	for (int i = 0; i < _edgeCount; i++)
	{
		for (int b = 0; b < _numberOfVertecies; b++)
		{
			if (_incidenceMatrix[i][a] > 0 && _incidenceMatrix[i][a] == -_incidenceMatrix[i][b])
			{
				neighbours[j++] = b;
			}
		}
	}

	neighbours[j] = -1;

	return neighbours;
}

void IncidenceMatrix::PrintGraph() 
{
	for (int i = 0; i < _edgeCount; i++)
	{
		for (int j = 0; j < _numberOfVertecies; j++)
		{	
			std::cout << _incidenceMatrix[i][j] << " ";	
		}

		std::cout << std::endl;
	}
}
