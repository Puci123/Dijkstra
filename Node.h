#pragma once
#include <bits.h>
#include <iostream>

struct Node
{
	int id;
	int weight;

	struct Node(int id, int weight) 
	{
		this->id = id;
		this->weight = weight;
	}

	struct Node()
	{
		this->id = -1;
		this->weight = INT_MAX;
	}

	~Node() 
	{
	}
};
