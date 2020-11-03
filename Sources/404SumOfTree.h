#pragma once

#include <vector>
#include <set>
using namespace std;

#include "TestFrame.h"


/* 
������ ��������Ҷ�ӽ��͡�
tip�� ����Ҷ�ӽ�㣬��û���������������� �������㣬����λ���ж�
https://blog.csdn.net/gyhjlauy/article/details/100653111     
	3
	/ \
	9  20
	/  \
	15   7

������������У���������Ҷ�ӣ��ֱ��� 9 �� 15�����Է��� 24
*/

/*

��ȡһ������������Ӵ�
��������Ԫ�ز��ظ�
����
Input: nums = [1,2,3]
Output: [ [3], [1], [2],[1,2,3], [1,3],[2,3],[1,2],[]]
2������˼·
2.1�ݹ�Ľⷨ���൱��һ�������������������ԭ����ÿһ������ֻ������״̬��Ҫô���ڣ�Ҫô�����ڣ���ô�ڹ����Ӽ�ʱ����ѡ��Ͳ�ѡ��������������Կ��Թ���һ�ö���������������ʾѡ��ò㴦��Ľڵ㣬��������ʾ��ѡ�����յ�Ҷ�ڵ���������Ӽ��ϣ���
��������������������������������
��Ȩ����������ΪCSDN���������ܵ���ţ@1997����ԭ�����£���ѭ CC 4.0 BY-SA ��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
ԭ�����ӣ�https://blog.csdn.net/qq_42079455/article/details/89086152


������Ⱥ͹�����ȱ���
https://blog.csdn.net/chlele0105/article/details/38759593
https://blog.csdn.net/alxe_made/article/details/94892284
*/

#define Type int
#include <stdio.h>
#include <string.h>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct MyStack
{
	int top = -1;
	void Push(TreeNode** tree, TreeNode*node)
	{
		tree[++top] = node;
	}

	void Pop()
	{
		if (top == -1)
		{
			return;
		}
		top -= 1;
	}

	bool IsEmpty()
	{
		return top == -1 ? true : false;
	}

	TreeNode* GetTopElement(TreeNode** tree)
	{
		return tree[top];
	}
};

void Test404SumOfTree()
{
	//�� Tree.h TreeSumOfLeftLeaves
}

//RegisterStruct SumOfTree404(&Test404SumOfTree);
