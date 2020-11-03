#pragma once

#include <vector>
#include <set>
using namespace std;

#include "TestFrame.h"


/* 
解析： 求树的左叶子结点和。
tip： ①是叶子结点，即没有左子树和右子树 ②是左结点，加入位置判断
https://blog.csdn.net/gyhjlauy/article/details/100653111     
	3
	/ \
	9  20
	/  \
	15   7

在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
*/

/*

获取一个数组的所有子串
数组里面元素不重复
比如
Input: nums = [1,2,3]
Output: [ [3], [1], [2],[1,2,3], [1,3],[2,3],[1,2],[]]
2、解题思路
2.1递归的解法，相当于一种深度优先搜索，由于原集合每一个数字只有两种状态，要么存在，要么不存在，那么在构造子集时就有选择和不选择两种情况，所以可以构造一棵二叉树，左子树表示选择该层处理的节点，右子树表示不选择，最终的叶节点就是所有子集合，树
————————————————
版权声明：本文为CSDN博主「奔跑的蜗牛@1997」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/qq_42079455/article/details/89086152


树的深度和广度优先遍历
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
	//在 Tree.h TreeSumOfLeftLeaves
}

//RegisterStruct SumOfTree404(&Test404SumOfTree);
