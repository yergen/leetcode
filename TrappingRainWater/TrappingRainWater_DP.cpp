#include<iostream>
#include<vector>
#include<algorithm>

using namespace::std;

class Solution {
public:
	int trap(vector<int>& height) {
		int n = height.size(), ans = 0;
		if (n <= 2) return 0;

		vector<int> left_max(n), right_max(n);

		left_max[0] = height[0];
		for (int i = 1; i < n; ++i)
			left_max[i] = max(left_max[i-1], height[i]);

		right_max[n-1] = height[n - 1];
		for (int i = n-2; i >= 0; --i)
			right_max[i] = max(right_max[i+1], height[i]);

		for (int i = 1; i < n-1; i++)
			ans += min(left_max[i], right_max[i]) - height[i];

		return ans;
	}
};

int main()
{
	vector<int> height = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	Solution sol;

	cout << sol.trap(height) << endl;

	return 0;
}