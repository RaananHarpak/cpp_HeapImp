#ifndef _Node_H
#define _Node_H
#include<string>
using namespace std;



class Node
{
protected:
	int priority;
	string data;
	Node** ppointer;
	int index;

public:
	Node(int _priority=-1,string _data="Error",Node* _ppointer=nullptr,int _index=-1) {
		priority = _priority;
		data = _data;
		ppointer = new Node*;
		*ppointer = _ppointer;
		index = _index;
	}
	Node(const Node& node) {
		priority = node.priority;
		data = node.data;
		ppointer = new Node*;
		//ppointer = node.ppointer;
		index = node.index;
	}

	int GetPriority() { return priority; }
	string GetData() { return data; }
	int GetIndex() { return index; }
	Node* GetPointer() { return *ppointer; }
	void SetIndex(int _index) { index = _index; }
	void SetPriority(int _priority) { priority = _priority; }
	void SetData(string _data) { data = _data; }
	void SetPointer(Node& _pointer) { *ppointer = &_pointer; }
	//void SetPointer(Node* _pointer) { *ppointer = &_pointer; }
};



#endif