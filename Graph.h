#pragma once

class Graph
{

	public:
		virtual void PrintGraph() = 0;
		virtual void AddEdge(int a, int b, int weight) = 0;
		virtual int  NumberOfVertecies() = 0;
		virtual int	 GetEdgeWeight(int a, int b) = 0;
		virtual int* GetNeighbours(int index) = 0;
	protected:
		void Construct(int vCount, int** data);

};
