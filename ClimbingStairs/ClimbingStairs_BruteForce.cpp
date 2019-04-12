#include<iostream>

using namespace::std;

class Solution {
public:
	int climbStairs(int n) {
		return climbStairs(0, n);
	}
private:
	int climbStairs(int i, int n)
	{
		if (i > n)
			return 0;
		if (i == n)
			return 1;
		return climbStairs(i + 1, n) + climbStairs(i + 2, n);
	}
};

int main()
{
	int n = 5;
	Solution sol;
	cout << sol.climbStairs(n) << endl;
	return 0;
}