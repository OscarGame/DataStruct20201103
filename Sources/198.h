#pragma once
/*
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

示例 1:

输入: [1,2,3,1]
输出: 4
解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。
示例 2:

输入: [2,7,9,3,1]
输出: 12
解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
     偷窃到的最高金额 = 2 + 9 + 1 = 12 。

https://blog.csdn.net/gyhjlauy/article/details/103387368

更好的一个解释
https://blog.csdn.net/qq_44525150/article/details/101571813

*/


#include "TestFrame.h"



vector<int> memo1;

int robCore(vector<int>& nums,int n)
{
    if(n<0) 
		return 0;//这里的条件很重要,因为是减法操作难免越界

	if(n == 0) 
		memo1[0]=nums[0];


    if(memo1[n] == -1) 
		//memo1[i]所存放的值是从nums[0]到nums[i]可以取到最大的值
		memo1[n] =  max(nums[n]+robCore(nums,n-2),robCore(nums,n-1));
    return memo1[n];
	

}

int rob(vector<int>& nums) {
        int n = nums.size();
        memo1 = vector<int>(n,-1);
        return robCore(nums,n-1);
    }


void Test198()
{
	vector<int> app;
	app.push_back(1);
	app.push_back(2);
	app.push_back(3);
	app.push_back(1);

	int e = rob(app);
	cout << e << endl;
}

//RegisterStruct T198(&Test198);