#pragma once
#include <cmath>
#include <iostream>
#define PHI  1.61803398875

// Creating a FiboNode
struct FiboNode 
{
	int valueOfNode;
	int degree;
	FiboNode* parent;
	FiboNode* child;
	FiboNode* left;
	FiboNode* right;
	bool mark = false;
};

// Implementing the Fibonacci heap
class FibonacciHeap {
	private:
		int count;
		FiboNode* min;
		void AddNodeToRoots(FiboNode* node);
		void Consolidate();
		void HeapLink( FiboNode* y, FiboNode* z);
		int MaxDegere();


	public:
		FibonacciHeap();
		void Insert(FiboNode* node);
		void DisplayChildernsOfNode(FiboNode* node);
		void Display();
		FiboNode*  ExtractMin();

		
};

