#include<iostream>
#include<vector>
#include<string>

using namespace::std;

class Solution {
public:
	//动态规划
	int uniquePaths(int m, int n) {
		//第一行路径数全为1
		vector<int> table(n, 1);
		//依次更新每一行的路径数
		for (int i = 1; i < m;++i)
		for (int j = 1; j < n; ++j)
			//table[j-1]左边的路径数，table[j] 上边的路径数。
			table[j] += table[j - 1];
		//返回最后一行最后一列的路径数。
		return table[n - 1];
	}
};

int main()
{
	int m = 3, n = 2;
	Solution sol;
	cout << sol.uniquePaths(m, n) << endl;
	return 0;
}