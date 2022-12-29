#ifndef _Heap_H
#define _Heap_H
#include<string>
#include"Node.h"
using namespace std;

enum { MAX_SIZE = 100 };



class Heap
{
protected:
	Node pairArr[MAX_SIZE];
	Heap() : maxSize(MAX_SIZE), HeapSize(0) {};
	static int Parent(int node) { return (node - 1) / 2; };
	static int Left(int node) { return (2 * node + 1); };
	static int Right(int node) { return (2 * node + 2); };
	virtual void FixHeap(int node) = 0;
	//void Swap(Node* n1, Node* n2);

public:
	int maxSize, HeapSize;
	//virtual void HeapSort(Node A[], int n) = 0;
	void Swap(Node& p1, Node& p2);
};

class MaxHeap : Heap
{
private:
	Node pairArr[MAX_SIZE];
	void FixHeap(int node);

public:
	int maxSize, HeapSize;
	Node Max() { return pairArr[0]; }
	void DeleteMax(Node& deleted);
	void Insert(Node item);
	void Remove(Node& item);
};

class MinHeap : Heap
{
private:
	Node pairArr[MAX_SIZE];
	void FixHeap(int node);

public:
	int maxSize, HeapSize;
	Node Min() { return pairArr[0]; }
	void DeleteMin(Node& minNode);
	void Insert(Node item);
	void Remove(Node& item);
};

void Swap(Node& p1, Node& p2);

#endif