

#include<iostream>
#include <stdio.h>
using namespace std;

//��Ӳ��Կ��
#include "TestFrame.h"

#include "279Squares.h"
#include "199BinaryTreeRightView.h"
#include "102&107BinaryTreeLeveltraverse.h"

#include "Sort.h"
#include "NoRepeatCha.h"


#include "FString.h"
#include "Tree.h"



/*
��һ��
https://blog.csdn.net/my_clear_mind/category_7905968.html

�ڶ���
https://blog.csdn.net/wolf96/category_2719841.html

������
https://blog.csdn.net/mohuak/category_7153596.html

*/

void GetMemory(char**p, int num)
{
	*p = (char*)malloc(sizeof(char) * num);
}


int main(int argc, const char** argv)
{
	RegisterFunction::GetInstance()->RunAllRegisterFunction();

	getchar();
	return 1;
}