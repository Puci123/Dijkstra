#pragma once

struct VerteciesLinqedListNode
{
	int value;
	int weight;
	VerteciesLinqedListNode* nextNode;

};

class VerteciesLinqedList
{
	
	public:
		VerteciesLinqedList();
		~VerteciesLinqedList();
		void Push(int value,int weight);
		int* ToArray();
		bool IsEmpty();
		VerteciesLinqedListNode* SerchForNode(int value);

	

	private:
		int count = 0;
		VerteciesLinqedListNode* header;

};

