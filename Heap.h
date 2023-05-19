#pragma once
#include "Node.h"
#include "PriorityQueue.h"
#include <iostream>

class Heap : public PriorityQueue
{
	private:
		Node* _heap;
		int _capacity;
		int _heap_size;

		void Heapify(int);
		int parent(int i) { return i >> 1; }
		int left(int i) { return i << 1; }
		int right(int i) { return (i << 1) + 1; }

	public:
		Heap(int capacity);
		~Heap();

		Node ExtractMin() override;
		void Insert(Node node) override;
		void DecreasKey(int id, int newValue) override;
		int  ContatinsKey(int key) override;
		bool IsEmpty() override;

};

