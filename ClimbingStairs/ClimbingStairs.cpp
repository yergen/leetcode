#include<iostream>
#include<cmath>

using namespace::std;

class Solution {
public:
	int climbStairs(int n) {
		int a = 1, b = 1;
		while (n--)
		{
			int c = a + b;
			a = b;
			b = c;
		}
		return a;
	}
};

int main()
{
	int n = 5;
	Solution sol;
	cout << sol.climbStairs(n) << endl;
	return 0;
}