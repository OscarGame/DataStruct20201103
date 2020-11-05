#pragma once
#include <stdio.h>
#include <string.h>
#include "TestFrame.h"


struct QueueNode
{
	QueueNode():val(-1),next(nullptr)
	{

	}

	int val;
	QueueNode* next;
};

//https://www.cnblogs.com/lanhaicode/p/10432004.html
class LinkQueue 
{
private:
	QueueNode* front;
	QueueNode* rear;
public:
	
	
	LinkQueue()
	{
		front = rear = nullptr;
	}

	bool IsEmpty()
	{
		return front == nullptr;
	}

	void EnQueue(QueueNode* node)
	{
		if (IsEmpty())
		{
			rear = front = node;
		}
		else
		{
			rear->next = node;
			rear = node;
		}
	}

	QueueNode* DeQueue()
	{
		if (IsEmpty())
			return nullptr;

		QueueNode* node = front;
		front = front->next;
		return node;
	}
};




void QueneTest()
{
	LinkQueue queue;
	QueueNode* node = new QueueNode();
	node->val = 1;
	queue.EnQueue(node);

	QueueNode* node2 = new QueueNode();
	node2->val = 2;
	//queue.EnQueue(node2);

	QueueNode* cur = nullptr;
	while (!queue.IsEmpty())
	{
		cur = queue.DeQueue();
		cout << cur->val << endl;
	}
	

}


RegisterStructTestFunction2(QueneTest)