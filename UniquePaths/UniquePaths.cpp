#include<iostream>
#include<vector>
#include<string>

using namespace::std;

class Solution {
public:
	//回溯法 时间超限
	int uniquePaths(int m, int n) {
		if (m == 1 || n == 1) return 1;
		//右下角的路径数是左边和上面的和。遇到第一行或第一列则为一条路径。
		return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
	}
};

int main()
{
	int m = 3, n = 2;
	Solution sol;
	cout << sol.uniquePaths(m, n) << endl;
	return 0;
}