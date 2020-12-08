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

	LinkNode<T>*  GetHeadNode()
	{
		if (head == nullptr)
			return nullptr;
		return head;
	}

	void  PopNode()
	{
		if (head == nullptr)
			return;
		LinkNode<T>* node = head;
		head = head->next;
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

	//return head node
	LinkNode<T>* DeleteElement(T dele)
	{
		if (head == nullptr)
			return nullptr;

		LinkNode<T>* dummy = new LinkNode<T>(0);

		dummy->next = head;

		LinkNode<T>* cur = dummy;
		
		while (cur->next != nullptr)
		{
			if (cur->next->mVal == dele)
			{
				LinkNode<T>* delenode = cur->next;
				cur->next = delenode->next;

				delete delenode;
				delenode = nullptr;
			}
			else
			{
				cur = cur->next;
			}
		}

		LinkNode<T>* retNode = dummy->next;
		delete dummy;
		return retNode;
	}


	//1,2,2,4  一个排序的链表，删除重复的元素后得到1，4
	LinkNode<T>* DeleteRepeatElement()
	{
		LinkNode<T>* dummyHead = new LinkNode<T>(-1);
		dummyHead->next = head;

		LinkNode<T>* cur = dummyHead;
		//head is not null
		while (cur->next != nullptr) 
		{
			if (cur->next->next != nullptr && (cur->next->next->mVal == cur->next->mVal))
			{
				int val = cur->next->mVal;

				while (cur->next != nullptr)
				{
					if (cur->next->mVal == val)
					{
						LinkNode<T>* delenode = cur->next;

						cur->next = delenode->next;

						delete delenode;
						delenode = nullptr;
					}
					else
					{
						break;
					}
				}
			}
			cur = cur->next;
		}

		LinkNode<T>* node = dummyHead->next;

		delete dummyHead;
		dummyHead = nullptr;

		return node;
	}


	void printLink()
	{
		LinkNode<T>* cur = head;
		while (cur)
		{
			cout << cur->mVal << endl;
			cur = cur->next;
		}	
	}

};


template<typename T>
class DoubleLinkNode
{
private:

public:
	DoubleLinkNode* next;
	DoubleLinkNode* pre;
	T mVal;
	DoubleLinkNode(T val) :mVal(val), next(nullptr),pre(nullptr)
	{

	}
};

template<typename T>
class DoubleLink
{
	//头插法
private:
	DoubleLinkNode<T>* head;
public:
	DoubleLink():head(nullptr)
	{
	}

	void insert(T ele)
	{
		if (head == nullptr)
		{
			DoubleLinkNode<T>* node = new DoubleLinkNode<T>(ele);
			head = node;
		}
		else 
		{
			DoubleLinkNode<T>* node = new DoubleLinkNode<T>(ele);

			node->next = head;
			head->pre = node;

			head = node;
		}
	}

	void Delete(T ele)
	{
		DoubleLinkNode<T>* curnode = head;
		while (curnode != nullptr)
		{
			if (curnode->mVal == ele)
			{
				DoubleLinkNode<T>* delenode = curnode;
				if (curnode->next == nullptr)
				{
					delenode->pre->next = nullptr;
				}
				else 
				{
					curnode->pre->next = curnode->next;
					curnode->next->pre = curnode->pre;
				}
				
				curnode = curnode->pre;

				delete delenode;
				delenode = nullptr;
			}
			curnode = curnode->next;
		}
	}


	DoubleLinkNode<T>* Find(T& ele)
	{
		if (head == nullptr)
			return nullptr;
		
		DoubleLinkNode<T>* node = head;
		while (node != nullptr)
		{
			if (node->mVal == ele)
			{
				return node;
			}
			node = node->next;
		}
		return nullptr;
	}

	void printLink()
	{
		DoubleLinkNode<T>* node = head;
		while (node)
		{
			cout << node->mVal << endl;
			node = node->next;
		}
	}
};

void TestLink()
{

//#define LinkTest
#ifdef LinkTest
	Link<int> link;
	link.Push(3);
	link.Push(2);
	link.Push(2);
	link.Push(1);
	
	//node = link.InerseNode();

	//node = link.DeleteElement(2);
	link.printLink();
	cout << "===========" << endl;
	link.DeleteRepeatElement();

	link.printLink();
#endif//LinkTest

#define DoubleLinkTest
#ifdef DoubleLinkTest
	DoubleLink<int> dlink;
	dlink.insert(1);
	dlink.insert(2);
	dlink.insert(3);
	dlink.printLink();

	dlink.Delete(2);
	dlink.printLink();
#endif//DoubleLinkTest
	
}

RegisterStructTestFunction2(TestLink);