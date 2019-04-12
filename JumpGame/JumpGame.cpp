#include<iostream>
#include<vector>

using namespace::std; 

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		if (n <= 1) return true;
		int left = 0, right = 0;
		int max_step = nums[0];
		while (right < n - 1)
		{
			for (int i = left; i <= right; ++i)
			{
				if (i + nums[i] > max_step)
					max_step = i + nums[i];
			}
			if (max_step == right && max_step < n - 1) return false;
			else
			{
				left = right + 1;
				right = max_step;
			}
		}
		return true;
	}
};

int main()
{
	vector<int> nums = {2,0,0};
	Solution sol;
	cout << sol.canJump(nums) << endl;

	return 0;
}