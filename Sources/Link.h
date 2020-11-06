#pragma once
#include "TestFrame.h"
#include "DataStructType.h"

template<typename T>
class Link 
{

	class LinkNode
	{
	private:
		
	public:
		LinkNode* next;
		T mVal;
		LinkNode(T val):mVal(val), next(nullptr)
		{

		}
	};

private:
	LinkNode* head;
public:
	Link():head(nullptr)
	{

	}

	void Push(T in)
	{
		LinkNode* node = new LinkNode(in);

		if (head == nullptr)
		{
			head = node;
		}
		else
		{
			node->next = head;
			head = node;
		}
	}

	void DelNode(T in)
	{

	}
};

void TestLink()
{

	Link<int> link;
	link.Push(2);
	link.Push(22);
	cout << "" << endl;



}
RegisterStructTestFunction2(TestLink);