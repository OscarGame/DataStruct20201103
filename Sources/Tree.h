#pragma once


#include <stdio.h>
#include <string.h>
#include "TestFrame.h"

#include "Stack.h"



#define TElemType int
typedef struct BTNode
{
	BTNode()
	{
		left = NULL;
		right = NULL;
		childIsVisualed = false;
	}

	TElemType data;
	struct BTNode* left;
	struct BTNode* right;
	bool childIsVisualed = false;
};



BTNode* CreateLeaf(TElemType data)
{
	BTNode * node = new BTNode;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

BTNode* CreateBTree()
{
	BTNode* top = CreateLeaf(1);
	top->left = CreateLeaf(2);
	top->left->left = CreateLeaf(4);
	top->left->right = CreateLeaf(5);

	top->right = CreateLeaf(3);
	top->right->left = CreateLeaf(6);
	top->right->right = CreateLeaf(7);

	return top;
}

void displayElem(BTNode* elem) 
{
	if (elem)
	{
		printf("%d ", elem->data);
	}
	else 
	{
		printf("element is null ");
	}
	
}




void PreOrderTraverse(BTNode* node)
{
	if (node)
	{
		displayElem(node);
		PreOrderTraverse(node->left);
		PreOrderTraverse(node->right);
	}
}

void PreOrderTraverse2(BTNode* node)
{
	if (node)
	{
		displayElem(node);
	}
}

void TreeTest()
{
	BTNode** arr = new BTNode*[2];

	BTNode* top1 = CreateLeaf(1);
	BTNode* top2 = CreateLeaf(2);
	arr[0] = top1;
	arr[1] = top2;


	ArrayStack<BTNode> stack;
	stack.Push(arr, top1);
	stack.Push(arr, top2);


	displayElem(stack.GetTopElement(arr));
	displayElem(stack.GetTopElement(arr));
	displayElem(stack.GetTopElement(arr));

}


//RegisterStruct RegisterTreeTest(&TreeTest);