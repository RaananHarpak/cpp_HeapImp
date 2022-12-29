#ifndef _MAP_H
#define _MAP_H
#include<stdlib.h>
#include<string>
#include "Heap.h"
using namespace std;

struct Pair {
	int priority;
	string data;
};

class Map
{
private:
	MaxHeap h1, h2;
	MinHeap h3, h4;

public:
	static Map CreateEmpty();
	void Insert(Node item);
	Node Max();
	Node Min();
	Node DeleteMax();
	Node DeleteMin();
	Node Median();
};

#endif