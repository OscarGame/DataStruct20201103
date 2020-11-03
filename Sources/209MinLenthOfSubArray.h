#pragma once
#include <vector>
#include <set>
using namespace std;

#include "TestFrame.h"

/*
题目链接
题目解析;
给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组。如果不存在符合条件的连续子数组，返回 0。

示例:

输入: s = 7, nums = [2,3,1,2,4,3]
输出: 2
解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。

tip: 滑窗法求解.
————————————————
版权声明：本文为CSDN博主「Hcaroline」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/gyhjlauy/article/details/103439363
*/



/*
类似
https://blog.csdn.net/zjwreal/article/details/100769101

https://leetcode-cn.com/problems/shortest-subarray-with-sum-at-least-k/
返回 A 的最短的非空连续子数组的长度，该子数组的和至少为 K 。
如果没有和至少为 K 的非空子数组，返回 -1 。

所有子数组中和>= k

输入：A = [2,-1,2], K = 3
输出：3
*/



#include<iostream>
#include <vector>
#include <set>
#include<algorithm>
using namespace std;

#include "../Common.h"


int minSubArrayLen(int s, vector<int>& nums);

void Test209()
{
	int s = 7;
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(4);
	nums.push_back(3);
	minSubArrayLen(s,nums);

}

int minSubArrayLen2(int s, vector<int>& nums) {
        int n = nums.size();
        int left = 0,right = 0,sum = 0,res = n+1,len = 0;
        while(right < n)
        {
            while(sum < s && right < n)
            {
                len++;
                sum = sum + nums[right++];
            }
            while(sum>=s)//这里while不可以用if替换,差值大于第一个元素的情况,细细体会一下
            {
                res = min(res,len);
                sum = sum-nums[left++];
                len--;
            }
        }
        return res == n+1?0:res;
    }

// s = 7, nums = [2,3,1,2,4,3]
int minSubArrayLen(int s, vector<int>& nums)
{
	//sort(nums.begin(), nums.end());
	int n = nums.size();
	int left = 0, right = 0, sum = 0, res = n + 1, len = 0;

	//求所有子数组 这样得到的子数组是连续的，注意有些要求还是非连续的
	for (int i = 0; i < n; i++)
	{
		right = i;
		vector<int> sumArr;
		sum = 0;
		len = 0;

		while (sum< s && right < n)
		{
			int element = nums[right++];
			sum += element;
			len++;
			sumArr.push_back(element);
		}

		

		if (sum >= s)
		{
			res = len < res ? len : res;

			for each (int var in sumArr)
			{
				std::cout << var;
			}
			std::cout << "len=" << len << endl;
		}
		
	}
	/*
	
	for (int i = 0 ; i < nums.size()-1;i++)
	{
		tsum = 0;
		tleng = 0;

		//获得连续的子数组
		for (int j = i; j < nums.size() - 1; j++)
		{
			tsum += nums[j];
			tleng += 1;
		}

		if (tsum >= s )
		{
			minLength = tleng;
		}
		
	}
	*/
	return res;
}

//RegisterStruct T209(&Test209);



