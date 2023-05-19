#pragma once
#include "Node.h"
#include "PriorityQueue.h"
#include <limits.h>

class PriorityQueueArray : public PriorityQueue
{
	private:
		Node* _queue;
		int	 _maxSize;
		int _size = 0;
	public:
		PriorityQueueArray(int maxSize);
		~PriorityQueueArray();


		void Insert(Node node) override;
		void DecreasKey(int id,int newValue) override;
		Node ExtractMin() override;
		bool IsEmpty() override;
		int ContatinsKey(int key) override;

};

