#pragma once

#include "TestFrame.h"
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
using namespace std;
using std::vector;
using std::set;

bool isContain(vector<char>& invec ,char incha)
{
	for each (char cha in invec)
	{
		if (cha == incha)
		{
			return true;
		}
	}
	return false;
}



void TestNoRepeatCha2()
{
	//vectorSort();
	//return;
	//abcabcbb 在运行到bb的时候会将前面的都删除，所以变小了，这里解决了曾经的最大，没有保留下来，还需要另外的数组保存
	char* testCha = const_cast<char*>("pwwkew");//abcabcbb pwwkew pwwkea
	int length = strlen(testCha);

	vector<char> charVec;
	vector<char> DesCharVec;


	int j = 0, ns = 0;
	while (j < length)
	{
		char cha = testCha[j];
		while (isContain(charVec, testCha[j]))
		{
			//vector<char>::iterator it = find(charVec.begin(), charVec.end(), testCha[j]);///返回的是地址
			//int index = &*it - &charVec[0];///放入迭代器中得到容器中的位置

			charVec.erase(charVec.begin());

		}


		charVec.push_back(testCha[j]);
		if (ns < charVec.size())
		{
			ns = charVec.size();

			DesCharVec.clear();
			DesCharVec = charVec;

		}
		j++;
	}

	printf("element count = %d\n", ns);

	typedef vector<char>::iterator Iterator;
	Iterator ite = DesCharVec.begin();
	for (; ite != DesCharVec.end(); ite++)
	{
		printf("element = %c\n", *ite);
	}



}


void TestNoRepeatCha3()
{
	char* testCha= const_cast<char*>("pwwkew");//abcabcbb pwwkew pwwkea
	int length = strlen(testCha);

	vector<char> charVec;
	vector<char> DesCharVec;

	int j = 0 , ns=0;
	while (j < length)
	{
		printf("element = %c\n", testCha[j]);
		
		char CurCha = testCha[j];

		//收藏队列里面包含了这个元素就从收藏队列移出
		while (isContain(charVec, CurCha))
		{
			charVec.erase(charVec.begin());
		}

		charVec.push_back(CurCha);

		j++;

		if (ns < charVec.size())
		{
			ns = charVec.size();
		}
	}


}

//RegisterStruct RegisterNoRepeatChaRS(&TestNoRepeatCha3);