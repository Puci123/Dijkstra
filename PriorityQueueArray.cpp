#include "PriorityQueueArray.h"


PriorityQueueArray::PriorityQueueArray(int maxSize)
{
	_queue = new Node[maxSize];
	_maxSize = maxSize;
	_size = 0;

	for (int i = 0; i < _maxSize; i++)
	{
		_queue[i] = Node(-1, INT_MAX);
	}

}

PriorityQueueArray::~PriorityQueueArray()
{
	delete[] _queue;
}

void PriorityQueueArray::Insert(Node a)
{
	_size++;
	_queue[a.id] = a;
}

void PriorityQueueArray::DecreasKey(int i,int newValue)
{
	_queue[i].weight = newValue;
}


Node PriorityQueueArray::ExtractMin()
{
	Node min = _queue[0];
	for (int i = 0; i < _maxSize; i++)
	{
		if (_queue[i].weight < min.weight && _queue[i].id != -1)
			min = _queue[i];
	}

	_size--;
	if(min.id != -1)
		_queue[min.id] = Node(-1,INT_MAX);
	
	return min;
}

int PriorityQueueArray::ContatinsKey(int key)
{
	return _queue[key].id;
}

bool PriorityQueueArray::IsEmpty()
{
	return _size == 0;
}

