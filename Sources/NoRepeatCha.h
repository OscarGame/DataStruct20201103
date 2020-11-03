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
	//abcabcbb �����е�bb��ʱ��Ὣǰ��Ķ�ɾ�������Ա�С�ˣ������������������û�б�������������Ҫ��������鱣��
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
			//vector<char>::iterator it = find(charVec.begin(), charVec.end(), testCha[j]);///���ص��ǵ�ַ
			//int index = &*it - &charVec[0];///����������еõ������е�λ��

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

		//�ղض���������������Ԫ�ؾʹ��ղض����Ƴ�
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