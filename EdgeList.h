#pragma once
#include "Graph.h"
#include <iostream>


struct EdgeLinqedListNode
{
	int a;
	int b;
	int weight;
	EdgeLinqedListNode* nextNode;

};

class EdgeList : Graph
{
	public:
		EdgeList(int numberOfVertecies);
		~EdgeList();
		void PrintGraph();
		void AddEdge(int a, int b, int weight) override;
		int  NumberOfVertecies() override;
		int	 GetEdgeWeight(int a, int b) override;
		int* GetNeighbours(int index) override;
		


	private:
		void Push(int a, int b, int weight);
		int* ToArray();
		bool IsEmpty();
		
		EdgeLinqedListNode* SerchForNode(int a, int b);
		
		EdgeLinqedListNode* header;
		int count = 0;
		int numberOfVerteices;

};

