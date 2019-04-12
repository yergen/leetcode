#include<iostream>

using namespace::std;

class Solution {
public:
	int mySqrt(int x) {
		if (x == 0) return 0;
		int left = 1, right = INT_MAX;
		while (true) {
			//mid = (left+right)/2 下面这种防止整数溢出
			int mid = left + (right - left) / 2;
			if (mid > x / mid) {
				right = mid - 1;
			}
			else {
				if (mid + 1 > x / (mid + 1))
					return mid;
				left = mid + 1;
			}
		}
	}
};

int main()
{
	Solution sol;
	int x = 1;
	cout << sol.mySqrt(2147395599) << endl;

	return 0;
}