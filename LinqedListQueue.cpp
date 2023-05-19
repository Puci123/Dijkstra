#include "LinqedListQueue.h"

LinqedListQueue::LinqedListQueue() 
{
	_head = new ListNode{Node() ,nullptr,nullptr};
}

LinqedListQueue::~LinqedListQueue() 
{
	ListNode* curent = _head->nextNode;


	while (curent != nullptr)
	{
		
		ListNode* temp = curent;
		curent = curent->nextNode;
		delete temp;
	}

	delete _head;
}

void LinqedListQueue::Insert(Node node)
{
	ListNode* curent = _head;

	while (true)
	{
		if(curent->nextNode == nullptr)
		{
			ListNode* listnode = new ListNode{ node,nullptr,nullptr };
			listnode->nextNode = curent->nextNode;
			listnode->prevNode = curent;
			curent->nextNode = listnode;
			break;

		}
		else if (node.weight < ((curent->nextNode))->data.weight)
		{
			ListNode* listnode = new ListNode{ node,nullptr,nullptr };
			
			listnode->nextNode = curent->nextNode;
			(curent->nextNode)->prevNode = listnode;
			listnode->prevNode = curent;
			curent->nextNode = listnode;
			

			break;
		}

		curent = curent->nextNode;

	}

}



bool LinqedListQueue::IsEmpty() 
{
	return (_head->nextNode == nullptr);
}

int LinqedListQueue::ContatinsKey(int k) 
{
	ListNode* curent = _head->nextNode;

	while (curent != nullptr)
	{
		if ((curent->data).id == k) return k;
		curent = curent->nextNode;
	}

	return -1;
}

void LinqedListQueue::DecreasKey(int id, int newVal) 
{
	ListNode* curent = _head->nextNode;
	
	while (curent != nullptr)
	{
		if (curent->data.id == id) break;

		curent = curent->nextNode;
	}

	curent->data.weight = newVal;

	
	while (curent->prevNode != _head && curent->data.weight < curent->prevNode->data.weight)
	{
		Node temp = curent->data;
		curent->data = (curent->prevNode)->data;
		(curent->prevNode)->data = temp;

		curent = curent->prevNode;

	}

	

}

Node LinqedListQueue::ExtractMin() 
{
	Node first = _head->nextNode->data;
	ListNode* temp = _head->nextNode;

	_head->nextNode = (_head->nextNode)->nextNode;
	
	if(_head->nextNode != nullptr)
		_head->nextNode->prevNode = _head;
	
	delete temp;
	return first;
}


