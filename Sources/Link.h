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

	//��������
	LinkNode<T>*  InerseNode()
	{
		if (head == nullptr)
			return nullptr;

		LinkNode<T>* pre = nullptr;
		LinkNode<T>* next = nullptr;
		while (head != nullptr)
		{
			//������һ���ڵ�
			next = head->next;
			//��ǰͷ���ָ��ǰ���ڵ�
			head->next = pre;
			//ǰ���ڵ�͵�ǰ�ڵ�ͬʱ����
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