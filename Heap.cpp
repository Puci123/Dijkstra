#include "Heap.h"



void Heap::Swap(Node* x, Node* y)
{
	Node temp = *x;
	
	helpTable[x->id] = y;
	helpTable[y->id] = x;
	
	*x = *y;
	*y = temp;
}

Heap::Heap(int cap)
{
	_heap_size = 0;
	_capacity = cap + 1;
	helpTable = new Node * [_capacity] {nullptr};
	_heap = new Node[_capacity];
}

Heap::~Heap()
{
	delete[] _heap;
	delete[] helpTable;
}

void Heap::Insert(Node k)
{
	int i = ++_heap_size;
	_heap[i] = k;

	helpTable[k.id] = &_heap[i];

	while (i > 1 && _heap[parent(i)].weight > _heap[i].weight)
	{
		Swap(&_heap[i], &_heap[parent(i)]);
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
		Swap(&_heap[i], &_heap[smallest]);
		Heapify(smallest);
	}
}

bool Heap::IsEmpty()
{
	return _heap_size == 0;
}

int Heap::ContatinsKey(int key) 
{
	if (helpTable[key] != nullptr) return key;

	return -1;
}

void Heap::DecreasKey(int i,int newValue) 
{
	helpTable[i]->weight = newValue;
	while (i > 1 && _heap[parent(i)].weight > _heap[i].weight)
	{
		Swap(&_heap[i], &_heap[parent(i)]);
		i = parent(i);

	}
}


