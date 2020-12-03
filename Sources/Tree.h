#pragma once


#include <stdio.h>
#include <string.h>
#include "TestFrame.h"

#include "Stack.h"
#include "DataStructType.h"



TreeNode* CreateLeaf(int data)
{
	TreeNode * node = new TreeNode(data);
	node->left = nullptr;
	node->right = nullptr;
	return node;
}

TreeNode* CreateBTree()
{
	TreeNode* top = CreateLeaf(1);
	top->left = CreateLeaf(2);
	top->left->left = CreateLeaf(4);
	top->left->right = CreateLeaf(5);

	top->right = CreateLeaf(3);
	top->right->left = CreateLeaf(6);
	top->right->right = CreateLeaf(7);

	return top;
}

TreeNode* CreateBTree2()
{
	TreeNode* top = CreateLeaf(1);
	top->left = CreateLeaf(2);
	top->left->left = CreateLeaf(4);
	top->left->right = CreateLeaf(5);

	top->right = CreateLeaf(3);
	top->right->left = CreateLeaf(6);
	//top->right->right = CreateLeaf(7);

	return top;
}


void displayElem(TreeNode* elem) 
{
	if (elem)
	{
		printf("%d ", elem->val);
	}
	else 
	{
		printf("element is null ");
	}
	
}




void PreOrderTraverse(TreeNode* node)
{
	if (node)
	{
		displayElem(node);
		PreOrderTraverse(node->left);
		PreOrderTraverse(node->right);
	}
}

template<typename T>
struct templateStruct
{
	T* rawarray[10];

	T* raw;
	templateStruct(T* inRaw = nullptr) :raw(inRaw)
	{
		for (int i = 0 ; i<10 ; i++)
		{
			rawarray[10] = nullptr;
		}
	}

	void push()
	{
	}

};

struct PreOrderTraverse2Stack
{
	TreeNode* stack[7];

	PreOrderTraverse2Stack()
	{
		for (int i =0 ; i < 7;i++)
		{
			stack[i] = nullptr;
		}
	}

	int top = -1;
	void Push(TreeNode* node)
	{
		stack[++top] = node;
	}

	void Pop()
	{
		if (top == -1)
			return;

		top -= 1;
	}

	TreeNode* GetTopElement()
	{
		if (top == -1)
		{
			return NULL;
		}
		return stack[top];
	}

	bool IsEmpty()
	{
		return top == -1 ? true : false;
	}
};

// 根 左 右
void PreOrderTraverse2(TreeNode* node)
{

	templateStruct<TreeNode> tem(node);
	TreeNode* cur = tem.raw;

	
	PreOrderTraverse2Stack stack;
	stack.Push(node);

	while (!stack.IsEmpty())
	{
		TreeNode* cur = stack.GetTopElement();
		stack.Pop();

		while (cur)
		{
			displayElem(cur);
			if (cur->right)
			{
				stack.Push(cur->right);
			}
			cur = cur->left;
		}
	}

}

void PreOrderTraverse3(TreeNode* node)
{
	PreOrderTraverse2Stack stack;
	stack.Push(node);

	TreeNode *p = nullptr;

	while (!stack.IsEmpty())
	{
		p = stack.GetTopElement();

		if (p)
		{
			displayElem(p);
			stack.Pop();
		}

		if (p->right)
		{
			stack.Push(p->right);
		}

		if (p->left)
		{
			stack.Push(p->left);
		}
	}
}



//左 根  右  先遍历到最左边
void InOderTraverse(TreeNode* node)
{
	PreOrderTraverse2Stack stack;
	TreeNode* p = node;

	while (p != nullptr || !stack.IsEmpty())
	{
		//一直
		while (p != NULL)
		{
			stack.Push(p);
			p = p->left;
		}
		//到这里必然是走到子节点，同时 p=null
		p = stack.GetTopElement();
		displayElem(p);
		stack.Pop();

		p = p->right;
	}

}


#include <stack>

void PostOrderTraverse(TreeNode* tree)
{
	//TreeNode* treeArray[7];
	//Push(treeArray, tree);
	PreOrderTraverse2Stack stack;
	stack.Push(tree);

	TreeNode* p = tree;
	TreeNode* last = tree;

	while (!stack.IsEmpty())
	{
		p = stack.GetTopElement();
		//	叶子节点的判断							根节点的判断(当前节点的右节点 == 上次访问过的 将该根节点Pop)
		if ((p->left == nullptr && p->right == nullptr) || (p->right == last))
		{
			displayElem(p);
			stack.Pop();
			last = p;
		}
		else
		{
			if (p->right)
			{
				stack.Push(p->right);
			}

			if (p->left)
			{
				stack.Push(p->left);
			}
		}
	}
}



void TreeSumOfLeftLeaves(TreeNode* tree,int& sum)
{
	PreOrderTraverse2Stack stack;
	stack.Push(tree);

	TreeNode* cur = nullptr;

	while (!stack.IsEmpty())
	{
		cur = stack.GetTopElement();
		if (cur->left == nullptr && cur->right == nullptr)
		{
			sum += cur->val;
			stack.Pop();
		}
		else
		{
			stack.Pop();

			if (cur->right != nullptr)
			{
				stack.Push(cur->right);
			}

			if (cur->left != nullptr)
			{
				stack.Push(cur->left);
			}
		}
			
		
	}

}



void LevelOrderTraverse(TreeNode* tree)
{
	struct FQueue
	{
		TreeNode* mQueue[7];
		int front,rear;

		FQueue() :front(0),rear(0)
		{

		}

		void Enqueue(TreeNode* node)
		{
			if (node)
				mQueue[rear++] = node;
		}

		TreeNode* DeQueue()
		{
			return mQueue[front++];
		}

		bool IsEmpty()
		{
			bool empty = front == rear ? true : false;
			return empty;
		}
	}queue;

	queue.Enqueue(tree);

	TreeNode* cur = nullptr;

	while (!queue.IsEmpty())
	{
		cur = queue.DeQueue();
		displayElem(cur);
		if (cur->right)
		{
			queue.Enqueue(cur->right);
		}

		if (cur->left)
		{
			queue.Enqueue(cur->left);
		}
	}


}

void TraverseTest()
{
	TreeNode* tree = CreateBTree();

	//PreOrderTraverse2(tree);
	//PreOrderTraverse3(tree);

	InOderTraverse(tree);
	//PostOrderTraverse(tree);

	//=============================
	//TreeNode* tree = CreateBTree();
	//int sum = 0;
	//TreeSumOfLeftLeaves(tree,sum);
	//cout << sum << endl;

	//LevelOrderTraverse(tree);
}


//反转树
void invertTree(TreeNode* tree)
{
	if (tree == nullptr)
	{
		return;
	}

	TreeNode* temp = tree->left;
	tree->left = tree->right;
	tree->right = temp;

	invertTree(tree->left);
	invertTree(tree->right);
}


void invertTreeTest()
{
	TreeNode* tree = CreateBTree();
	invertTree(tree);

	PreOrderTraverse(tree);
}





void TreeStackTest()
{
	TreeNode** arr = new TreeNode*[2];

	TreeNode* top1 = CreateLeaf(1);
	TreeNode* top2 = CreateLeaf(2);
	arr[0] = top1;
	arr[1] = top2;

	ArrayStack<TreeNode> stack;
	stack.Push(arr, top1);
	stack.Push(arr, top2);

	displayElem(stack.GetTopElement(arr));
	displayElem(stack.GetTopElement(arr));
	displayElem(stack.GetTopElement(arr));

}

void TreeTest()
{
	//invertTreeTest();
	TraverseTest();
}


//RegisterStruct RegisterTreeTest(&TreeTest);