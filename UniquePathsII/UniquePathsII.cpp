#include<iostream>
#include<vector>

using namespace::std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		vector<int> table(n + 1, 0);
		//初始化起始位置为1
		table[1] = 1;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				obstacleGrid[i][j - 1] ? table[j] = 0 : table[j] += table[j - 1];
			}
		}

		return table[n];
	}
};

int main()
{
	vector<vector<int>> Grid = { { 0, 0, 0 }, { 0, 1, 0 }, { 0, 0, 0 } };
	Solution sol;
	cout << sol.uniquePathsWithObstacles(Grid) << endl;

	return 0;
}