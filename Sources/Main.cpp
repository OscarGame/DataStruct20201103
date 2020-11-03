

#include<iostream>
#include <stdio.h>
using namespace std;

//添加测试框架
#include "TestFrame.h"

#include "279Squares.h"
#include "199BinaryTreeRightView.h"
#include "102&107BinaryTreeLeveltraverse.h"

#include "Sort.h"
#include "NoRepeatCha.h"


#include "FString.h"
#include "Tree.h"



/*
第一批
https://blog.csdn.net/my_clear_mind/category_7905968.html

第二批
https://blog.csdn.net/wolf96/category_2719841.html

第三批
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