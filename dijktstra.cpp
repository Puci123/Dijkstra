﻿#include<fstream>
#include<iostream>
#include<chrono>


#include "AdjacencyMatrix.h"
#include "IncidenceMatrix.h"
#include "AdjcencyList.h"
#include "EdgeList.h"
#include "PriorityQueueArray.h"
#include "Heap.h"
#include "FiboHeap.h"
#include "LinqedListQueue.h"
#include "Node.h"

#define MAX_EDGE_WEIGHT 100;


const char* FILEPATH = "TimeComplexity.csv";
const bool WRITETOFILE = false;

//return: first -> distncies to vertceis; scond -> previeus verecies
std::pair<int*,int*> dijkstra(int start, Graph* graph, PriorityQueue* queue)
{

	int*  dist = new int[graph->NumberOfVertecies()];
	int* prev = new int[graph->NumberOfVertecies()];
	bool* visited = new bool[graph->NumberOfVertecies()];
	
	

	for (int i = 0; i < graph->NumberOfVertecies(); i++)
	{
		dist[i] = INT_MAX;
		visited[i] = 0;
		prev[i] = -1;
	}

	dist[start] = 0;
	queue->Insert(Node(start, 0));
	
	while (!queue->IsEmpty())
	{
		Node curent = queue->ExtractMin();
		if (curent.id == -1 || dist[curent.id] < curent.weight) continue;

		visited[curent.id] = true;
		
		int  i = 0;
		int* neighbours = graph->GetNeighbours(curent.id);
		
		for (int i = 0; neighbours[i] != -1; i++)
		{
			if (graph->GetEdgeWeight(curent.id, neighbours[i]) == -1 || visited[neighbours[i]]) continue;

			int newDist = dist[curent.id] + graph->GetEdgeWeight(curent.id, neighbours[i]);
			if (newDist < dist[neighbours[i]])
			{
				dist[neighbours[i]] = newDist;
				prev[neighbours[i]] = curent.id;
				int temp = queue->ContatinsKey(neighbours[i]);

				if (temp == -1)
					queue->Insert(Node(neighbours[i], newDist));
				else
					queue->DecreasKey(temp, newDist);
			}
		}

		delete[] neighbours;
	}
	
	delete[] visited;
	return std::pair<int*,int*>(dist,prev);

}

int* shotestPath(int start,int finish, Graph* graph, PriorityQueue* queue)
{
	std::pair<int*, int*> values = dijkstra(start, graph, queue);
	int* path = new int[graph->NumberOfVertecies()];

	for (int i = 0; i < graph->NumberOfVertecies(); i++)
	{
		path[i] = -1;
	}

	if (values.first[finish] < INT_MAX)
	{
		int j = graph->NumberOfVertecies() - 1;
		for (int current = finish; current != -1; current = values.second[current])
		{
			path[j] = current;
			j--;
		}
	}

	delete[] values.first;
	delete[] values.second;

	return path;
}

void populetGraph(int size, float density, int seed, int &edgeHandle,int ***memHandel) 
{
	srand(seed);
	int** temp = *memHandel;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			float edgeFactor = ((float)(rand() % 101)) / 100;

			if (edgeFactor < density && j != i)
			{
				temp[i][j] = rand() % MAX_EDGE_WEIGHT;
				edgeHandle++;
			}
			else
			{
				temp[i][j] = -1;
			}
		}
	}
}


void Benchmark(PriorityQueue* queue, Graph* graph, double &timeOut, UINT16 &memOut)
{
	auto start =  std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch().count();
	
	int* path = shotestPath(0,graph->NumberOfVertecies() - 1,graph,queue);
	
	auto stop = std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch().count();


	delete[] path;
	
	timeOut = (stop - start) * 0.001;
}

void WriteToFile(std::string name, int size, double value) 
{
	if (WRITETOFILE)
	{
		std::ofstream file;
		file.open(FILEPATH, std::ios::app);
		file << name << ";" << size << ";" << value << "\n";
		file.close();
	}
}

void BenchMarkGraphType(Graph* graph, std::string name) 
{
	double time;
	UINT16 mem = 0;

	PriorityQueue* queue = new Heap(graph->NumberOfVertecies());

	std::cout << std::endl << name <<" + heap" << " curent size : " << graph->NumberOfVertecies();
	Benchmark(queue, graph, time, mem);
	std::cout << " exec time: " << time << "ms";
	WriteToFile(name + "_heap", graph->NumberOfVertecies(), time);

	delete queue;
	queue = new PriorityQueueArray(graph->NumberOfVertecies());
	std::cout << std::endl << name <<" + array" << " curent size : " << graph->NumberOfVertecies();
	Benchmark(queue, graph, time, mem);
	std::cout << " exec time: " << time << "ms";
	WriteToFile(name + "_array", graph->NumberOfVertecies(), time);


	delete queue;
	queue = new LinqedListQueue();
	std::cout << std::endl << name << " + list" << " curent size : " << graph->NumberOfVertecies();
	Benchmark(queue, graph, time, mem);
	std::cout << " exec time: " << time << "ms";
	WriteToFile(name + "_list", graph->NumberOfVertecies(), time);
	delete queue;
}

int main()
{
	int samplePerType = 30;
	int seed = 0;
	float density = 0.75;

	if (WRITETOFILE)
	{
		std::ofstream file;
		file.open(FILEPATH, std::ios::ate);
		file << "Name;size;time[ms];\n";
		file.close();
	}

	for (int i = 8; i < 513; i += 8)
	{

		int** data = new int* [i];
		for (int k = 0; k < i; k++)
		{
			data[k] = new int[i];
		}


		for (int j = 0; j < samplePerType; j++)
		{
			seed = i * samplePerType + j;
			srand(seed);
			density = ((float)(rand() % 101)) / 101;

			int edges = 0;

			


			populetGraph(i, density, seed, edges,&data);

			AdjacencyMatrix* graph1 = new AdjacencyMatrix(i,data);
			BenchMarkGraphType(graph1, "AdjacencyMatrix");
			delete graph1;

			AdjcencyList* graph2 = new AdjcencyList(i,data);
			BenchMarkGraphType((Graph*)graph2, "AdjacencyList");
			delete graph2;

			EdgeList* graph3 = new EdgeList(i,data);
			BenchMarkGraphType((Graph*)graph3, "EdgeList");
			delete graph3;

			IncidenceMatrix* graph4 = new IncidenceMatrix(i,edges,data);
			BenchMarkGraphType((Graph*)graph4, "IncidenceMatrix");
			delete graph4;

		}

		for (int k = 0; k < i; k++)
		{
			delete[] data[k];

		}
		delete[] data;
	}
}

 