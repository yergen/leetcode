#include<iostream>
#include<vector>

using namespace::std;

class Solution {
public:
	int climbStairs(int n) {
		vector<int> memo(n + 1, 0);

		return climbStairs(0, n, memo);
	}
private:
	int climbStairs(int i, int n,vector<int>& memo)
	{
		if (i > n)
			return 0;
		if (i == n)
			return 1;
		if (memo[i] > 0)
			return memo[i];
		memo[i] = climbStairs(i + 1, n, memo) + climbStairs(i + 2, n, memo);

		return memo[i];
	}
};

int main()
{
	int n = 5;
	Solution sol;
	cout << sol.climbStairs(n) << endl;
	return 0;
}