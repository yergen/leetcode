#include<iostream>
#include<vector>

using namespace::std;

class Solution {
public:
	int climbStairs(int n) {
		vector<int> DP(n + 1, 0);
		if (n <= 1) return 1;

		DP[1] = 1;
		DP[2] = 2;

		for (int i = 3; i <= n; ++i)
		{
			DP[i] = DP[i - 1] + DP[i - 2];
		}
		return DP[n];
	}

};

int main()
{
	int n = 5;
	Solution sol;
	cout << sol.climbStairs(n) << endl;
	return 0;
}