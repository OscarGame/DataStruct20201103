#pragma once

#include <stdio.h>
#include <string.h>
#include "TestFrame.h"


#include "DataStructType.h"
using namespace std;

/*

子类使用私有继承

对任意一个对象的入栈
push(void* node)
*/
class commonStack
{
protected:
    commonStack();
    ~commonStack();

    void push(void* node);
    void* Top();
    void pop();
    int size()const;
    bool Empty() const;
    void clear();

    
private:
    struct StackNode
    {
        void* data;
        StackNode* next;
        StackNode(void* Newdata, StackNode* nextNode)
            :data(Newdata),next(nextNode)
        {}
    };

    StackNode * top;
    // 防止默认拷贝和默认赋值
    commonStack(const commonStack& rhs);
    commonStack& operator=(const commonStack& rhs);
    int mySize;
};

commonStack::commonStack()
    :top(nullptr),mySize(0)
{

}

 
commonStack::~commonStack()
{
    clear();
}

 
void commonStack::push(void* node)
{
    top = new StackNode(node,top);
    mySize ++;
}

 
void* commonStack::Top()
{
    if (Empty())
    {
        printf("Error, stack is empty!");
    }
    return top->data;
}

 
void commonStack::pop()
{
    if (Empty())
    {
        printf("Error, stack is empty!");
    }
    StackNode* topOfStack = top;
    top = top->next;
    delete topOfStack;
    topOfStack = nullptr;
    mySize --;
    return;
}

 
bool  commonStack::Empty() const
{
    return top == nullptr;
}
 
void commonStack::clear()
{
    while (top)
    {
        StackNode* topOfStack = top;
        top = top->next;
        delete topOfStack;

    }
    mySize = 0;
}
 
int commonStack::size()const
{
    return mySize;
}


template <typename T>
class Stack:private commonStack
{
public:
    void push(T * ty){commonStack::push(static_cast<void*>(ty));}
    T* top(){return static_cast<T*>(commonStack::Top());}
    void pop(){return commonStack::pop();}
    int size(){return commonStack::size();}
    bool Empty()const{ return commonStack::Empty(); }
    void clear(){return commonStack::clear();}
 
};
template<class T>
class ArrayStack
{
private:
	int top;
public:
	ArrayStack() :top(-1)
	{
		printf("ArrayStack");
	}

	void Push(T** stack,T* node)
	{
		if (stack != nullptr)
		{
			stack[++top] = node;
		}
	}

	void Pop()
	{
		if (top == -1)
		{
			return;
		}
		--top;
	}

	T* GetTopElement(T** stack)
	{
		if (top == -1)
		{
			return nullptr;
		}
		T* t = stack[top];
		return t;
	}
};

template<typename T>
class LinkStack
{
private:

	struct Node
	{
		Node* next;
		T element;


		Node() :next(nullptr) {}
		Node(T t) :element(t), next(nullptr) {}
	};

	Node* head;
private:
	LinkStack(const LinkStack&);

	LinkStack& operator=(const LinkStack&) = delete;
public:
	LinkStack():head(nullptr)
	{
		 
	}

	void Push(T elem)
	{
		//Node<T>* node = new Node<T>();  内部结构体可以免去<T>的方式
		Node* node = new Node();
		node->element = elem;
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

	T Top()
	{
		return head->element;
	}

	//利用这个来delete
	void Pop()
	{
		Node* top = head;
		head = head->next;

		delete top;
		top = nullptr;
	}

	void clear()
	{
	}


};

/*

template<class T>
void LinkStack<T>::Push(T* elem)
{	
	Node<T*>* node = new Node<T*>();
	node->element = elem;
	Push2(node);
}
*/


struct MyNode
{
	int a;
	MyNode():a(0)
	{}
};


void StackTest()
{
	printf("Enter StackTest");



	/*
	
	LinkStack<MyNode> stack;
	
	MyNode a;
	a.a = 1;
	stack.Push(a);

	MyNode b = stack.Top();
	printf("b = %d", b.a);
	stack.Pop();
	*/

	/*
	Node<int> a;
	a.element = 11;

	stack.Push(a);

	Node<int> b;
	
	//stack.Pop();

	b.element = stack.Pop2();
	*/
	system("pause");

}


//RegisterStruct RegisterStackTest(&StackTest);