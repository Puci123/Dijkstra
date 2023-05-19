#pragma once
#include "PriorityQueue.h"


class LinqedListQueue : public PriorityQueue
{
	public:
		LinqedListQueue();
		~LinqedListQueue() override;

		void Insert(Node node) override;
		Node ExtractMin() override;
		bool IsEmpty() override;
		int ContatinsKey(int key) override;
		void DecreasKey(int id, int newValue) override;

	private:


		struct ListNode
		{
			Node data;
			ListNode* nextNode;
			ListNode* prevNode;
		};


		ListNode* _head;
};

