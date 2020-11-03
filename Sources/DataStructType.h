#pragma once



struct TreeNode
{
	int val;
	TreeNode* right;
	TreeNode* left;

	TreeNode(int i) :val(i), right(nullptr), left(nullptr)
	{}
};


struct ListNode
{
	ListNode* mNext;
	int mData;
	explicit ListNode(int i = 0) :mData(i), mNext(nullptr)
	{
	
	}
};

