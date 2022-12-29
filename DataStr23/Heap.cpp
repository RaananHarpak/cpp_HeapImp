#include "Heap.h"

void MaxHeap::DeleteMax(Node& deleted)
{
	
	//Node max = pairArr[0];
	deleted = pairArr[0];
	deleted.SetPointer(pairArr[0]);
	//max.SetPointer(pairArr[0]);
	//max.pointer = new Node;
	HeapSize--;
	pairArr[0] = pairArr[HeapSize];
	FixHeap(0);
}

void MinHeap::DeleteMin(Node& minNode)
{
	if (HeapSize < 1) {
		// handle error
	}
	//Node* ptr;
	//ptr = pairArr[0].GetPointer();
	minNode = pairArr[0];
	minNode.SetPointer(pairArr[0]);
	//min.pointer = new Node;
	HeapSize--;
	pairArr[0] = pairArr[HeapSize];
	FixHeap(0);
	//return(min);
}

void MaxHeap::FixHeap(int node)
{
	int max;
	int left = Left(node);
	int right = Right(node);
	if ((left < HeapSize) && (pairArr[left].GetPriority() > pairArr[node].GetPriority()))
		max = right;
	else
		max = node;
	if ((right < HeapSize) && (pairArr[right].GetPriority() > pairArr[max].GetPriority()))
		max = right;

	if (max != node)
	{
		//Swap(&pairArr[node], &pairArr[max]);
		Swap(pairArr[node],pairArr[max]);
		FixHeap(max);
	}
}

void MinHeap::FixHeap(int node)
{
	int min;
	int left = Left(node);
	int right = Right(node);
	if ((left < HeapSize) && (pairArr[left].GetPriority() < pairArr[node].GetPriority()))
		min = right;
	else
		min = node;
	if ((right < HeapSize) && (pairArr[right].GetPriority() < pairArr[min].GetPriority()))
		min = right;

	if (min != node)
	{
		//Swap(&pairArr[node], &pairArr[min]);
		Swap(pairArr[node], pairArr[min]);
		FixHeap(min);
	}
}

void MaxHeap::Insert(Node item)
{
	//Node newNode = { item.GetPriority(),item.GetData(),item.GetPointer(),item.GetIndex() };
	Node* ptr = item.GetPointer();
	if (HeapSize == maxSize) {
		// handle error
	}
	int i = HeapSize++;
	while ((i > 0) && (pairArr[Parent(i)].GetPriority() < item.GetPriority()))
	{
		pairArr[i] = pairArr[Parent(i)];
		pairArr[i].SetPointer(pairArr[Parent(i)]);
		i = Parent(i);
	}
	pairArr[i] = item;
	pairArr[i].SetPointer(item);
	pairArr[i].SetIndex(i);

}

void MinHeap::Insert(Node item)
{
	if (HeapSize == maxSize) {
		// handle error
	}
	int i = HeapSize++;
	while ((i > 0) && (pairArr[Parent(i)].GetPriority() > item.GetPriority()))
	{
		pairArr[i] = pairArr[Parent(i)];
		i = Parent(i);
	}
	pairArr[i] = item;
	pairArr[i].SetIndex(i);

}

void Swap(Node& p1, Node& p2)
{
	Node tmp = { p1.GetPriority(),p1.GetData(),p1.GetPointer(),p1.GetIndex() };
	p1.SetPriority(p2.GetPriority());
	p1.SetData(p2.GetData());
	p1.SetPointer(p2);
	p1.SetIndex(p2.GetIndex());
	p2.SetPriority(tmp.GetPriority());
	p2.SetData(tmp.GetData());
	p2.SetPointer(tmp);
	p2.SetIndex(tmp.GetIndex());
}

void Heap::Swap(Node& p1, Node& p2)
{Node tmp = { p1.GetPriority(),p1.GetData(),p1.GetPointer(),p1.GetIndex() };
	p1.SetPriority(p2.GetPriority());
	p1.SetData(p2.GetData());
	p1.SetPointer(p2);
	p1.SetIndex(p2.GetIndex());
	p2.SetPriority(tmp.GetPriority());
	p2.SetData(tmp.GetData());
	p2.SetPointer(tmp);
	p2.SetIndex(p1.GetIndex());
}

void MaxHeap::Remove(Node& item)
{
	if (HeapSize > 0)
	{
		
		Node temp = { pairArr[HeapSize - 1] };
		temp.SetPointer(pairArr[HeapSize - 1]);

		//temp.pointer = new Node;
		//temp.data = pairArr[HeapSize - 1].data;
		//temp.GetPriority() = pairArr[HeapSize - 1].GetPriority();
		
	//Swap(item, &temp);
	Swap(item,temp);
	FixHeap(temp.GetIndex());/////////////////////////////////////
	HeapSize--;
	}
	else {
		HeapSize--;
	}
}

void MinHeap::Remove(Node& item)
{
	if (HeapSize > 0)
	{
		Node temp = { pairArr[HeapSize - 1] };
		//temp.pointer = new Node;
		//temp.GetPriority() = pairArr[HeapSize - 1].GetPriority();
		//temp.data = pairArr[HeapSize - 1].data;
		temp.SetPointer(pairArr[HeapSize - 1]);
			Swap(item,temp);
			//Swap(item, &temp);
			FixHeap(temp.GetIndex());/////////////////////////
		HeapSize--;
	}
	else {
		HeapSize--; 
	}
}