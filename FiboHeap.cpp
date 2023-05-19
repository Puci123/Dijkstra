#include "FiboHeap.h"


FibonacciHeap::FibonacciHeap() 
{
	count = 0;
	min = nullptr;
}

void FibonacciHeap::AddNodeToRoots(FiboNode* node)
{
	
	node->left = node;
	node->right = node;
	
	node->parent = nullptr;

	if (min == nullptr) 
	{
		min = node;
	}
	else
	{
		(min->left)->right = node;
		node->right = min;
		node->left = min->left;
		min->left = node;

		if (node->valueOfNode < min->valueOfNode)
			min = node;
	}

}

void FibonacciHeap::Insert(FiboNode* node) 
{
	AddNodeToRoots(node);
	count++;
}

int FibonacciHeap::MaxDegere() 
{
	return (log(count)/log(PHI));
}

void FibonacciHeap::HeapLink(FiboNode* y, FiboNode* x)
{
	(y->left)->right = y->right;
	(y->right)->left = y->left;

	y->left = y;
	y->right = y;
	y->parent = x;

	if (x->child == nullptr) 
	{
		x->child = y;
	}
	else
	{
		((x->child)->left)->right = y;
		y->left = (x->child)->left;
		y->right = x->child;
		(x->child)->left = y;

	}

	x->degree++;
}

void FibonacciHeap::Consolidate() 
{
	int maxDeg = MaxDegere();
	FiboNode** A = new FiboNode*[maxDeg + 1];

	for (int i = 0; i < maxDeg + 1; i++)
		A[i] = nullptr;

	FiboNode* curentNode = min;
	FiboNode* startNode = curentNode;
	
	FiboNode* x = startNode;
	FiboNode* y = nullptr;


	if (startNode != nullptr) 
	{
		do
		{

			int d = x->degree;

			while (A[d] != nullptr)
			{
				y = A[d];

				std::cout << A[d]->valueOfNode << std::endl;

				if (x != y && y != nullptr)
				{
					if (x->valueOfNode > y->valueOfNode)
					{
						FiboNode* temp = x;
						x = y;
						y = temp;
					}

					HeapLink(y, x);
					A[d] = nullptr;
				}
				d++;
			}

			A[d] = x;
			curentNode = curentNode->right;

		} while (curentNode != startNode);
	}
	return;

}

void FibonacciHeap::DisplayChildernsOfNode(FiboNode* node) 
{
	std::cout << "\n\tChilds of " << node->valueOfNode << std::endl;

	FiboNode* childNode = node->child;
	FiboNode* curent = childNode;

	if (childNode != nullptr)
	{
		//DisplayChildernsOfNode(childNode);

		do
		{
			std::cout << curent->valueOfNode << "; ";
			curent = curent->right;

		} while (curent != childNode);

		std::cout;
	}
	else
	{
		std::cout << "\tNONE";
	}
}

void FibonacciHeap::Display() 
{
	FiboNode* node = min;

	if (node == nullptr) 
	{
		std::cout << "\nHeap is empty" << std::endl;
	}
	else
	{
		std::cout << "Heap" << std::endl;
		do
		{
			std::cout << "Root node: " << node->valueOfNode;
			DisplayChildernsOfNode(node);
			std::cout << std::endl;

			node = node->right;
		} while (node != min && node->right != nullptr);
	}
}
FiboNode* FibonacciHeap::ExtractMin()
{
	FiboNode* z = min;
	
	if (z != nullptr) 
	{
		FiboNode* zchild = z->child;
		FiboNode* curetn = zchild;
		
		if (zchild != nullptr) 
		{
			do
			{
				(min->left)->right = curetn;
				curetn->right = min;
				curetn->left = min->left;
				min->left = curetn;

				curetn->parent = nullptr;


				curetn = curetn->right;
			} while (curetn != zchild);
		}

		(z->left)->right = z->right;
		(z->right)->left = z->left;

		if (z->right == z)
		{
			min = nullptr;
		}
		else
		{
			min = z->right;
			Consolidate();
		}
	}

	count--;
	return z;
}