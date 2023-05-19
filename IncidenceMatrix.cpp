#include "IncidenceMatrix.h"




IncidenceMatrix::IncidenceMatrix(int numberOfVertecies) 
{
	_edgeCount = 0;
	_numberOfVertecies = numberOfVertecies;
}

IncidenceMatrix::~IncidenceMatrix() 
{
	for (int i = 0; i < _edgeCount; i++)
	{
		_incidenceMatrix[i] = new int[_numberOfVertecies];
		delete[] _incidenceMatrix[i];
	}

	delete[] _incidenceMatrix;
}

void IncidenceMatrix::AddEdge(int a, int b, int weight) 
{
	_edgeCount++;
	int** newTab = new int* [_edgeCount];

	for (int i = 0; i < _edgeCount - 1; i++)
	{
		newTab[i] = new int[NumberOfVertecies()];
		for ( int j = 0; j < NumberOfVertecies(); j++)
		{
			newTab[i][j] = _incidenceMatrix[i][j];
		}
	}

	newTab[_edgeCount - 1] = new int[NumberOfVertecies()];
	for (int j = 0; j < NumberOfVertecies(); j++)
	{
		newTab[_edgeCount - 1][j] = 0;
	}

	int** temp = _incidenceMatrix;
	_incidenceMatrix = newTab;
	_incidenceMatrix[_edgeCount - 1][a] = weight;
	_incidenceMatrix[_edgeCount - 1][b] = -weight;

	for (int i = 0; i < _edgeCount - 1; i++)
	{
		delete[] temp[i];
	}

	delete[] temp;

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
