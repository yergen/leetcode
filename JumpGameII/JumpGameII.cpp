#include<iostream>
#include<vector>
#include<algorithm>

using namespace::std;

class Solution {
public:
	int jump(vector<int>& nums) {
		int start = 0, end = 0, step = 0;
		while (end < nums.size()-1)
		{
			step++;
			int maxIndex = end + 1;
			for (int i = start; i <= end; ++i)
				maxIndex = max(maxIndex, nums[i] + i);
			start = end + 1;
			end = maxIndex;
		}

		return step;
	}
};

int main()
{
	vector<int> nums = {5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0};

	Solution sol;
	cout << sol.jump(nums) << endl;

	return 0;
}