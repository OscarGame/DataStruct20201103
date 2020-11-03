#pragma once
#include <vector>
#include <set>
using namespace std;

#include "TestFrame.h"

/*
��Ŀ����
��Ŀ����;
����һ������ n ���������������һ�������� s ���ҳ���������������� �� s �ĳ�����С�����������顣��������ڷ������������������飬���� 0��

ʾ��:

����: s = 7, nums = [2,3,1,2,4,3]
���: 2
����: ������ [4,3] �Ǹ������µĳ�����С�����������顣

tip: ���������.
��������������������������������
��Ȩ����������ΪCSDN������Hcaroline����ԭ�����£���ѭ CC 4.0 BY-SA ��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
ԭ�����ӣ�https://blog.csdn.net/gyhjlauy/article/details/103439363
*/



/*
����
https://blog.csdn.net/zjwreal/article/details/100769101

https://leetcode-cn.com/problems/shortest-subarray-with-sum-at-least-k/
���� A ����̵ķǿ�����������ĳ��ȣ���������ĺ�����Ϊ K ��
���û�к�����Ϊ K �ķǿ������飬���� -1 ��

�����������к�>= k

���룺A = [2,-1,2], K = 3
�����3
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
            while(sum>=s)//����while��������if�滻,��ֵ���ڵ�һ��Ԫ�ص����,ϸϸ���һ��
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

	//������������ �����õ����������������ģ�ע����ЩҪ���Ƿ�������
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

		//���������������
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



