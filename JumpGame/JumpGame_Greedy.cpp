#include<iostream>
#include<vector>
#include<algorithm>

using namespace::std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int pos = nums.size() - 1;
		for (int i = pos; i >= 0; i--)
		{
			if (nums[i] + i >= pos)
				pos = i;
		}
		return pos == 0;
	}

	/*bool canJump(vector<int>& nums) {
		int i = 0, n = nums.size();
		for (int reach = 0; i<n && i<=reach; i++)
			reach = max(nums[i] + i, reach);

		return i == n;
	}*/
};

int main()
{
	vector<int> nums = {1};
	Solution sol;
	cout << sol.canJump(nums) << endl;

	return 0;
}