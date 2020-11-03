#pragma once
#include "TestFrame.h"
#include <vector>
#include <queue>

using namespace std;

#include "DataStructType.h"



TreeNode* GetRoot102107()
{
	TreeNode* root = new TreeNode(0);

	TreeNode* r1 = new TreeNode(1);
	TreeNode* r2 = new TreeNode(2);
	
	root->left = r1;
	root->right = r2;
	


	TreeNode* r3 = new TreeNode(3);
	TreeNode* r4 = new TreeNode(4);

	r1->left = r3;
	r1->right = r4;


	TreeNode* r5 = new TreeNode(5);
	TreeNode* r6 = new TreeNode(6);
	r2->left = r5;
	r2->right = r6;

	return root;
}

/*
输入: [1,2,3,null,5,null,4]
输出: [1, 3, 4]
解释:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

  其实是层次遍历
*/
vector<TreeNode*> GetLevelTraverse(TreeNode* root)
{
	vector<TreeNode*> rightView;

	if (root == nullptr)
	{
		return rightView;
	}

	
	queue<pair<TreeNode*,int>> tempQuque;
	tempQuque.push(make_pair(root,0));

	while (!tempQuque.empty())
	{

		TreeNode* cur = tempQuque.front().first;
		int level = tempQuque.front().second;

		tempQuque.pop();
		
		rightView.push_back(cur);
		
		if (cur->right != nullptr)
		{
			tempQuque.push(make_pair(cur->right,level +1));
		}

		if (cur->left != nullptr)
		{
			tempQuque.push(make_pair(cur->left,level +1));
		}
		
	}
	return rightView;

}


void Test102107()
{
	TreeNode* root = GetRoot102107();


	vector<TreeNode*> ve = GetLevelTraverse(root);

	cout << "Test102107"<<endl;

	getchar();
}

//RegisterStruct RegisterTest102107(&Test102107);