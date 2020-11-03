#pragma once
#include <vector>
#include <set>
using namespace std;


#include "TestFrame.h"


/*
使用set来自动去掉重复元素
这样都情况下b是不会添加入set集合的
vector<int> a{1,2};
vector<int> b{ 1,2 };
vector<int> c{ 1,2,3};
set<vector<int>> se;
se.insert(a);
se.insert(b);
se.insert(c);
*/

/*
https://blog.csdn.net/gyhjlauy/article/details/103019133
这里还是4个类似的例子
两数求和
三数求和
最接近的三数之和
三数之和小于一个值


题目解析:
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意： 答案中不可以包含重复的四元组。

示例： 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：

[
[-1,  0, 0, 1],
[-2, -1, 1, 2],
[-2,  0, 0, 2]
]

*/

/*
这个算法其实是获得了一个数组的全排列
左边是i ,j，右边是left 和right ，这两个是会往右边移动的 
这样就获取了所有的四个非连续的元素了
*/
void fourSum(vector<int>& nums, int target)
{
	sort(nums.begin(), nums.end());
	set<vector<int>> res;//set去重
	int len = nums.size();
	for (int i = 0; i < len - 3; i++)
	{
		for (int j = i + 1; j < len - 2; j++)//注意这里的范围,不对会导致出错
		{
			int left = j + 1;
			int right = len - 1;

			//这里之所以能这样用是因为排序了
			while (left < right)
			{
				int sum = nums[i] + nums[j] + nums[left] + nums[right];
				if (sum == target)
				{
					vector<int> out{ nums[i],nums[j],nums[left],nums[right] };//将元素放入vector中
					res.insert(out);
					++left;
					--right;
				}
				else if (sum > target) 
					--right;
				else
					++left;

			}
		}
	}
}

static void Test18LeetCode()
{
	vector<int> a{ 1, 0, -1, 0, -2, 2 };
	int target = 0;
	fourSum(a,target);
}

//RegisterStruct Num18(&Test18LeetCode);


