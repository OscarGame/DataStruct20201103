#pragma once
#include "TestFrame.h"
/*
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

示例 1:
输入:
11110
11010
11000
00000
输出: 1

示例 2:
输入:
11000
11000
00100
00011
输出: 3
解释: 每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-islands
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

void ShowMatrix(vector<vector<char>> grid)
{
	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[0].size(); j++)
		{
			cout << grid[i][j] << ",";
		}
		cout <<endl;
	}
	cout <<endl;
}

void bfs(vector<vector<char>>& grid,int i,int j){
    if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
		return;
   
	if(grid[i][j] == '0')
		return;
    
	grid[i][j] = '0';
    bfs(grid,i+1,j);
    bfs(grid,i,j+1);
    bfs(grid,i-1,j);
    bfs(grid,i,j-1);
}
    
int numIslands(vector<vector<char>>& grid) 
{

	int size = grid[0].size();

	int ans = 0;
	for(int i = 0;i < grid.size(); i++){
		for(int j = 0;j < grid[0].size();j++){
			if(grid[i][j] == '0')
				continue;
			ans++;
			bfs(grid,i,j);

			ShowMatrix(grid);
		}
	}
	return ans;
}



/*
11110
11010
11000
00000
*/
/*
vector<char> grid1;
	grid1.push_back('1');
	grid1.push_back('1');
	grid1.push_back('1');
	grid1.push_back('1');
	grid1.push_back('0');
	grid.push_back(grid1);

	vector<char> grid2;
	grid2.push_back('1');
	grid2.push_back('1');
	grid2.push_back('0');
	grid2.push_back('1');
	grid2.push_back('0');
	grid.push_back(grid2);

	vector<char> grid3;
	grid3.push_back('1');
	grid3.push_back('1');
	grid3.push_back('0');
	grid3.push_back('0');
	grid3.push_back('0');
	grid.push_back(grid3);

	vector<char> grid4;
	grid4.push_back('0');
	grid4.push_back('0');
	grid4.push_back('0');
	grid4.push_back('0');
	grid4.push_back('0');
	grid.push_back(grid4);
*/

/*
11000
11000
00100
00011
*/
void Test200()
{
	vector<vector<char>> grid;
	
	vector<char> grid1;
	grid1.push_back('1');
	grid1.push_back('1');
	grid1.push_back('0');
	grid1.push_back('0');
	grid1.push_back('0');
	grid.push_back(grid1);

	vector<char> grid2;
	grid2.push_back('1');
	grid2.push_back('1');
	grid2.push_back('0');
	grid2.push_back('0');
	grid2.push_back('0');
	grid.push_back(grid2);

	vector<char> grid3;
	grid3.push_back('0');
	grid3.push_back('0');
	grid3.push_back('1');
	grid3.push_back('0');
	grid3.push_back('0');
	grid.push_back(grid3);

	vector<char> grid4;
	grid4.push_back('0');
	grid4.push_back('0');
	grid4.push_back('0');
	grid4.push_back('1');
	grid4.push_back('1');
	grid.push_back(grid4);

	ShowMatrix(grid);
	int num = numIslands(grid);
	cout << num;

}



//RegisterStruct T200(&Test200);