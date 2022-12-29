#include "Map.h"


Node Map::Max()
{
	
	return h2.Max();

}
Node Map::Min()
{
	return h4.Min();
}
Node Map::DeleteMax()
{
		Node deleted;
		h2.DeleteMax(deleted);
		h3.Remove(deleted);
		if (abs(h1.HeapSize - h2.HeapSize) > 1)
		{
			Node node;
			h1.DeleteMax(node);
			Node nodeCopy{ node };
			node.SetPointer(nodeCopy);
			nodeCopy.SetPointer(node);
			h2.Insert(node);
			h3.Insert(nodeCopy);
		}
	return deleted;
}
Node Map::DeleteMin()
{
	Node deleted;
	 h4.DeleteMin(deleted);
	h1.Remove(deleted);

	if (abs(h3.HeapSize - h4.HeapSize) > 1)
	{
		Node node;
		 h3.DeleteMin(node);
		Node nodeCopy{ node};
		node.SetPointer(nodeCopy);
		nodeCopy.SetPointer(node);
		h4.Insert(node);
		h1.Insert(nodeCopy);
	}
	return deleted;
}
Map Map::CreateEmpty()
{
	return Map();
}
void Map::Insert(Node item)
{
	Node newNode = { item };
	Node nodeCopy = { newNode};
	newNode.SetPointer(nodeCopy);
	nodeCopy.SetPointer(newNode);
	//item.SetPointer(nodeCopy);

	//newNode.pointer = new Node;
	//nodeCopy.pointer = new Node;

	//newNode.data = item.data;
	//newNode.priority = item.priority;
	
	//nodeCopy.data = item.data;
	//nodeCopy.priority = item.priority; 
	//newNode.pointer = &nodeCopy;
	//nodeCopy.pointer = &newNode;

	/*if (Median().GetPointer() == nullptr)
	{*/
		//h4.Insert(newNode);
		//h1.Insert(nodeCopy);
		//if ( abs(h1.HeapSize - h2.HeapSize) > 1)
		//{
		//	Node node;
		//	//node.pointer = new Node;
		//	h1.DeleteMax(node);
		//	h4.Remove(node);
		//	Node nodeCopy{ node};
		//	node.SetPointer(nodeCopy);
		//	nodeCopy.SetPointer(node);
		//	h2.Insert(node);
		//	h3.Insert(nodeCopy);

		//}
	//}
		 if (newNode.GetPriority() < Median().GetPriority())
		{
			h4.Insert(newNode);
			h1.Insert(nodeCopy);
			if (abs(h1.HeapSize - h2.HeapSize) > 1)
			{
				Node node;
				//node.pointer = new Node;
				h1.DeleteMax(node);
				h4.Remove(node);
				Node nodeCopy{ node};
				node.SetPointer(nodeCopy);
				nodeCopy.SetPointer(node);
				h2.Insert(node);
				h3.Insert(nodeCopy);
			}
		}
		else
		{
			h2.Insert(newNode);
			h3.Insert(nodeCopy);
			if (abs(h2.HeapSize - h1.HeapSize) > 1)
			{
				Node node;
				h3.DeleteMin(node);
				h2.Remove(node);
				Node nodeCopy{ node};
				node.SetPointer(nodeCopy);
				nodeCopy.SetPointer(node);
				h1.Insert(node);
				h4.Insert(nodeCopy);
			}
		}
	}
Node Map::Median()
{
		if (h1.HeapSize > 0)
			return h1.Max();
		else if (h3.HeapSize > 0)
			return h3.Min();
		else
		{
			Node n;
			return n;
		}
			
		
		/*if (h3.HeapSize > 0 && h2.HeapSize > 0 && h3.HeapSize > h2.HeapSize)
		{
			return h2.Max();
		}
		else if (h3.HeapSize > 0 && h2.HeapSize > 0 && h3.HeapSize < h2.HeapSize)
		{
			return h3.Min();
		}*/
		/*else {
			Node n;
			n.pointer = nullptr;
			return n;
		}*/
	}
