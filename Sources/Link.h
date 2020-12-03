#pragma once
#include "TestFrame.h"
#include "DataStructType.h"

template<typename T>
class LinkNode
{
private:

public:
	LinkNode* next;
	T mVal;
	LinkNode(T val) :mVal(val), next(nullptr)
	{

	}
};

template<typename T>
class Link 
{
private:
	LinkNode<T>* head;
public:
	Link():head(nullptr)
	{

	}

	void Push(T in)
	{
		LinkNode<T>* node = new LinkNode<T>(in);

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

	LinkNode<T>*  PopNode()
	{
		if (head == nullptr)
			return nullptr;
		
		LinkNode<T>* node = head;
		
		head = head->next;
		return node;
	}

	//逆置链表
	LinkNode<T>*  InerseNode()
	{
		if (head == nullptr)
			return nullptr;

		LinkNode<T>* pre = nullptr;
		LinkNode<T>* next = nullptr;
		while (head != nullptr)
		{
			//保留下一个节点
			next = head->next;
			//当前头结点指向前驱节点
			head->next = pre;
			//前驱节点和当前节点同时后移
			pre = head;
			head = next;
		}
		return pre;
	}

};




void TestLink()
{

	Link<int> link;
	link.Push(3);
	link.Push(2);
	link.Push(1);

	LinkNode<int>* node = nullptr;
	//node = link.InerseNode();

	while (node)
	{
		cout << node->mVal << endl;
		node = node->next;
	}		

	while (node = link.PopNode())
	{
		cout << node->mVal << endl;
	}
}

//RegisterStructTestFunction2(TestLink);