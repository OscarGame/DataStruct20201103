

#include<iostream>
#include <stdio.h>
using namespace std;

//ÃÌº”≤‚ ‘øÚº‹
#include "TestFrame.h"

#include "17PhoneNumberComToCha.h"
#include "279Squares.h"
#include "199BinaryTreeRightView.h"
#include "102&107BinaryTreeLeveltraverse.h"


#include "Sort.h"
#include "NoRepeatCha.h"
#include "FString.h"
#include "Tree.h"
#include "Queue.h"
#include "Link.h"


char* GetString()
{
	char* cha = const_cast<char*>("sdfsdf");
	return cha;
}


struct ArrayStr
{
	struct Node
	{
		int val;
		Node():val(0)
		{
		}

		Node(int inVal):val(inVal)
		{}
	};

	Node* node;
	int mDeltaSize;
	int mCurSize;
	ArrayStr() :mCurSize(1),mDeltaSize(0)
	{
		node = new Node[mCurSize];
	}

	bool CopyCurElementToNewArray(int inDeltaSize)
	{
		Node* newNodePtr = nullptr;
		bool isSuccess = ResetSize(inDeltaSize, &newNodePtr);

		if (isSuccess)
		{
			for (int index = 0 ;index < mCurSize;index++)
			{
				newNodePtr[index] = node[index];

			}

			mCurSize = mCurSize + inDeltaSize;
			node = newNodePtr;
		}


		for (int index = 0; index < mCurSize; index++)
		{
			cout << &newNodePtr[index]<< endl;

		}


		return isSuccess;

	}

	bool ResetSize(int deltaSize,Node** outNode)
	{	
		if (deltaSize == 0)
		{
			return false;
		}

		Node* nodes = new Node[deltaSize + mCurSize];
		if (nodes)
		{
			mDeltaSize = deltaSize;
			*outNode = nodes;
			return true;
		}
		return false;
	}

};


#include <stack>
#include <queue>

int main(int argc, const char** argv)
{

	queue<int> m_Queue;

	ArrayStr as;
	as.CopyCurElementToNewArray(1);

	char* cha = GetString();

	RegisterFunction::GetInstance()->RunAllRegisterFunction();
	getchar();
	return 1;
}