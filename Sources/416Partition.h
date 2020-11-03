#pragma once
/*
给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

注意:

每个数组中的元素不会超过 100
数组的大小不会超过 200
示例 1:

输入: [1, 5, 11, 5]

输出: true

解释: 数组可以分割成 [1, 5, 5] 和 [11].
 

示例 2:

输入: [1, 2, 3, 5]

输出: false

解释: 数组不能分割成两个元素和相等的子集.

*/


/*

LeetCode-【动态规划】-分割等和子集&划分为k个相等的子集
https://blog.csdn.net/zw159357/article/details/82805282

dd大牛的背包九讲-背包问题汇总
https://blog.csdn.net/stack_queue/article/details/53544109

*/


#include "TestFrame.h"
/*
1,获取所有元素的子集，但是只有两个子集
2，
*/


 vector<vector<int>> memo;
    
bool canCore(vector<int>& nums,int index,int sum)
{
    if(sum == 0) return true;
    if(sum<0 || index <0) return false;

    if(memo[index][sum] != -1) 
		return memo[index][sum];
    memo[index][sum]= canCore(nums,index-1,sum) || canCore(nums,index-1,sum-nums[index]);
    return memo[index][sum];
}

bool Partition(vector<int>& nums) {
		int n = nums.size();
		int sum = 0;
        
		for(int i =0;i<n;i++)
			sum = sum+nums[i];
		memo = vector<vector<int>> (n,vector<int>(sum/2+1,-1));

		int a = sum % 2;

		if(sum%2 != 0) return false;
	return canCore(nums,n-1,sum/2);
 }



int Sum(vector<int>& nums)
{
	int sum = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		sum += nums[i];
	}
	return sum;
}

/*

bool subsetSum(int nums[], int s) 
{
    bool[] dp = new bool[s + 1]; 

    dp[0] = true;
    for (int n : nums){
        for (int i = s; i >= n; i--){
            dp[i] =dp[i]||dp[i - n]; 
        }
        if(dp[s])
            return true; 
    }
    return dp[s];
} 

public bool canPartition(int nums[]) 
 {
    int sum=0;
    for(int n:nums)
        sum+=n;
    if(sum%2!=0)
        return false;
    return subsetSum(nums,sum>>>1);
}
*/
static void Test416LeetCode()
{	
	vector<int> nums{ 1, 3,1, 5 };
	Partition(nums);
	return;


//	Partition(a);

	int sum = Sum(nums);

	if (sum % 2)
	{
		cout << "false"<<endl;
	}

	vector<vector<int>> memo;
	int n = nums.size();
	memo = vector<vector<int>> (n,vector<int>(sum/2+1,-1));


	vector<int> dp(sum / 2 + 1);
	dp[0] = 1;
	for (int i = 0; i < nums.size(); ++i) {
		for (int j = sum / 2; j >= nums[i]; --j) {
			dp[j] |= dp[j - nums[i]];
		}
		if (dp[sum / 2]) 
			cout << "true"<<endl;
	}

	cout << "false"<<endl;
}




//RegisterStruct M416(&Test416LeetCode);