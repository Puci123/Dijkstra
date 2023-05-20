#include "Graph.h"


void Graph::Construct(int vCount, int** data) 
{
	for (int i = 0; i < vCount; i++)
	{
		for (int j = 0; j < vCount; j++)
		{
			if (data[i][j] != -1) AddEdge(i, j, data[i][j]);
		}
	}
}