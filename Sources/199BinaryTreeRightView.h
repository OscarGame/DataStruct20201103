#pragma once
#include "TestFrame.h"

#include <vector>
#include <queue>

using namespace std;

#include "DataStructType.h"



TreeNode* GetRoot()
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
����: [1,2,3,null,5,null,4]
���: [1, 3, 4]
����:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

  ��ʵ�ǲ�α���,��ô�ڱ�����ʱ����ұߵ���ߴ�һ�����ߣ����������ĵ�һ������������Ҫ��ӵ�Ԫ�أ�
  ����һ������ÿ��Ĳ㼶����Ҳ����˵ÿ���ڵ���������Ĳ��� ==  �ýڵ����ڵĲ����Ļ�����ô����ڵ��������Ҫ�ҵ�
*/
vector<TreeNode*> GetRightView(TreeNode* root)
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
		
		
		if (level == rightView.size())
		{
			rightView.push_back(cur);
		}
	


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


void Test199()
{
	TreeNode* root = GetRoot();


	vector<TreeNode*> ve = GetRightView(root);

	cout << "Test199"<<endl;

	getchar();
}

//RegisterStruct Register199(&Test199);