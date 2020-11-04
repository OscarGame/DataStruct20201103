#pragma once
#include <stdio.h>
#include <string.h>
#include "TestFrame.h"


struct QueueNode
{
	int val;
	QueueNode* next;
};

//https://www.cnblogs.com/lanhaicode/p/10432004.html
struct LinkQueue 
{
	QueueNode* front;
	QueueNode* rear;
	
	LinkQueue()
	{
		front = rear = new QueueNode;
		front->next = nullptr;
	}

	bool IsEmpty()
	{
		return front == rear ? true : false;
	}

	void EnQueue(QueueNode* node)
	{
		rear->next = node;
		rear = node;
	}

	QueueNode* DeQueue()
	{
		if (IsEmpty())
			return nullptr;

		QueueNode* node = front;

		front = front->next;

		/*
		
		//出队列的节点为最后一个节点
		if (front->next == rear)
		{
			node = front;

			//rear = front;
			//front->next = nullptr;
		}
		//
		else
		{
			front
		}
		*/
		return node;
	}



};




void QueneTest()
{

}


RegisterStructTestFunction2(QueneTest)