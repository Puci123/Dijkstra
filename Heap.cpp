#include "Heap.h"



void swap(Node* x, Node* y)
{
	Node temp = *x;
	*x = *y;
	*y = temp;
}

Heap::Heap(int cap)
{
	_heap_size = 0;
	_capacity = cap + 1;
	_heap = new Node[_capacity];
}

Heap::~Heap()
{
	delete[] _heap;
}

void Heap::Insert(Node k)
{
	int i = ++_heap_size;
	_heap[i] = k;

	while (i > 1 && _heap[parent(i)].weight > _heap[i].weight)
	{
		swap(&_heap[i], &_heap[parent(i)]);
		i = parent(i);
	}
}


Node Heap::ExtractMin()
{

	if (_heap_size == 1)
	{
		_heap_size--;
		return _heap[1];
	}

	Node root = _heap[1];
	_heap[1] = _heap[_heap_size--];
	Heapify(1);

	return root;
}

void Heap::Heapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l <= _heap_size && _heap[l].weight < _heap[i].weight)
		smallest = l;
	if (r <= _heap_size && _heap[r].weight < _heap[smallest].weight)
		smallest = r;
	if (smallest != i)
	{
		swap(&_heap[i], &_heap[smallest]);
		Heapify(smallest);
	}
}

bool Heap::IsEmpty()
{
	return _heap_size == 0;
}

int Heap::ContatinsKey(int key) 
{
	for (int i = 1; i < _heap_size + 1; i++)
	{
		if (_heap[i].id == key) return i;
	}

	return -1;
}

void Heap::DecreasKey(int i,int newValue) 
{
	_heap[i].weight = newValue;
	while (i > 1 && _heap[parent(i)].weight > _heap[i].weight)
	{
		swap(&_heap[i], &_heap[parent(i)]);
		i = parent(i);

	}
}


