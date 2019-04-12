#include<iostream>
#include<vector>
#include<algorithm>

using namespace::std;

class Solution {
public:
	int trap(vector<int>& height) {
		int n = height.size(), ans = 0;
		for (int i = 0; i < n; ++i)
		{
			int left_max = 0, right_max = 0;
			for (int j = i; j >= 0; --j)
				left_max = max(left_max, height[j]);
			for (int k = i; k < n;k++)
				right_max = max(right_max, height[k]);
			//how much water every bar is able to trap.
			ans += min(left_max, right_max) - height[i];
		}

		return ans;
	}
};

int main()
{
	vector<int> height = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	Solution sol;

	cout << sol.trap(height) << endl;

	return 0;
}