#pragma once
#include <vector>
#include <set>
using namespace std;


#include "TestFrame.h"


/*
ʹ��set���Զ�ȥ���ظ�Ԫ��
�����������b�ǲ��������set���ϵ�
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
���ﻹ��4�����Ƶ�����
�������
�������
��ӽ�������֮��
����֮��С��һ��ֵ


��Ŀ����:
����һ������ n ������������ nums ��һ��Ŀ��ֵ target���ж� nums ���Ƿ�����ĸ�Ԫ�� a��b��c �� d ��ʹ�� a + b + c + d ��ֵ�� target ��ȣ��ҳ��������������Ҳ��ظ�����Ԫ�顣

ע�⣺ ���в����԰����ظ�����Ԫ�顣

ʾ���� �������� nums = [1, 0, -1, 0, -2, 2]���� target = 0��

����Ҫ�����Ԫ�鼯��Ϊ��

[
[-1,  0, 0, 1],
[-2, -1, 1, 2],
[-2,  0, 0, 2]
]

*/

/*
����㷨��ʵ�ǻ����һ�������ȫ����
�����i ,j���ұ���left ��right ���������ǻ����ұ��ƶ��� 
�����ͻ�ȡ�����е��ĸ���������Ԫ����
*/
void fourSum(vector<int>& nums, int target)
{
	sort(nums.begin(), nums.end());
	set<vector<int>> res;//setȥ��
	int len = nums.size();
	for (int i = 0; i < len - 3; i++)
	{
		for (int j = i + 1; j < len - 2; j++)//ע������ķ�Χ,���Իᵼ�³���
		{
			int left = j + 1;
			int right = len - 1;

			//����֮����������������Ϊ������
			while (left < right)
			{
				int sum = nums[i] + nums[j] + nums[left] + nums[right];
				if (sum == target)
				{
					vector<int> out{ nums[i],nums[j],nums[left],nums[right] };//��Ԫ�ط���vector��
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


