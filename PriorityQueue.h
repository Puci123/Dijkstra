#pragma once
#include "Node.h"

class PriorityQueue
{
	public:
		virtual ~PriorityQueue() {};
		virtual void Insert(Node node) = 0;
		virtual void DecreasKey(int id, int newValue) = 0;
		virtual Node ExtractMin() = 0;
		virtual bool IsEmpty() = 0;
		virtual int ContatinsKey(int key) = 0;

		
};
