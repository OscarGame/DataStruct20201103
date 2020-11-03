#pragma once
#include "TestFrame.h"

#include <vector>
#include <queue>

using namespace std;


int numsSquares(int n);

struct PN
{
	int num;
	int step;
};

 int numsSquares2(int n) {

		queue<PN> PNqueue;  

        queue< pair<int,int>> q;    //剩余数，步数
        q.push( make_pair(n,0) );
        vector<bool> visited (n ,false);    //[0..n-1]是否被访问过得标志位 
        while(!q.empty()){
            int num = q.front().first;
            int step = q.front().second;
            q.pop();            
            int i = 1;

			//完全平方数  n^2 = （n-x）^2 + （n-y）^2 + ...
			//13 = 4 + 9   == >  13 - 3^2 = 2^   所以这里将3从最小的1开始
            while(num - i * i >= 0){
                int tmp = num - i * i;
				if (tmp == 0)
				{
					PN pn;
					pn.step = step + 1;
					pn.num = i;
					PNqueue.push(pn);
					//return step + 1;
					break;
				}
				
                if(tmp > 0){
                    if(visited[tmp] == false){
                        q.push(make_pair(tmp,step + 1));
                        visited[tmp] = true;
                    }
                }
                i++;
            }
        }

		getchar();
        return 0;
    }





/*
给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, …）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

输入: n = 12
输出: 3 
解释: 12 = 4 + 4 + 4.


输入: n = 13
输出: 2
解释: 13 = 4 + 9.
*/
int numsSquares(int n)
{

	queue< pair<int,int>> q;    //剩余数，步数
      q.push( make_pair(n,0) );
	  
	  queue< int> qq;
	//n = i1^2 + i2^2 + ... +in^2;
	int i = 1;
	
	while ((n - i * i) >= 0)
	{
		qq.push(i);
		i += 1;
	}

	getchar();
	return 1;
}

void Test()
{

	cout << "Register279"<<endl;

	int result = numsSquares(14);
	cout << "result=" <<result<<endl;
	getchar();
}

//RegisterStruct Register279(&Test);
