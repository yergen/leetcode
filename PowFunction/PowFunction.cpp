#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace::std;

class Solution {
public:
	double myPow(double x, int n) {
		double res = 1.0;
		for (int a = abs(n); a; a = a >> 1,x *= x)
			if (a & 1) res *= x;
		return n < 0 ? 1 / res : res;
	}
};

int main()
{
	Solution sol;

	cout << sol.myPow(2.0, 10) << endl;

	return 0;
}