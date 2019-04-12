#include<iostream>

using namespace::std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		unsigned long n = 0;
		int temp = x;
		while (temp>0)
		{
			n = n * 10 + temp % 10;
			temp /= 10;
		}

		return x == n;
	}
};

int main()
{
	int a = 10;
	Solution sol;
	cout << sol.isPalindrome(a) << endl;
	return 0;
}