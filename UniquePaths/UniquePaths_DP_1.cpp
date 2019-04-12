#include<iostream>
#include<vector>
#include<string>

using namespace::std;

class Solution {
public:
	//动态规划
	int uniquePaths(int m, int n) {
		//第一行和第一列的路径数都为1
		vector<vector<int>> table(m, vector<int>(n, 1));
		for (int i = 1; i < m;++i)
		for (int j = 1; j < n; ++j)
			table[i][j] = table[i - 1][j] + table[i][j - 1];

		return table[m - 1][n - 1];
	}
};

int main()
{
	int m = 3, n = 2;
	Solution sol;
	cout << sol.uniquePaths(m, n) << endl;
	return 0;
}