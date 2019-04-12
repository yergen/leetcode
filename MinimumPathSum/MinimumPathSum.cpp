#include<iostream>
#include<vector>
#include<algorithm>

using namespace::std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();

		vector<int> table(n + 1,INT_MAX);
		table[1] = 0;
		for (int i = 0; i < m;++i)
		for (int j = 1; j <= n; ++j)
			table[j] = grid[i][j - 1] + min(table[j], table[j - 1]);
		return table[n];
	}
};

int main()
{
	vector<vector<int>> Grid = { { 1, 3, 1 }, { 1, 5, 1 }, { 4, 2, 1 } };
	Solution sol;
	cout << sol.minPathSum(Grid) << endl;

	return 0;
}