#include<iostream>
#include<vector>

using namespace::std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int lo = 0, n = nums.size(),hi = n-1;
		if (n == 0) return 0;
		while (lo < hi)
		{
			int mid = (lo + hi) / 2;
			if (nums[mid] == target) return mid;
			else if (nums[mid] > target) hi = mid;
			else
				lo = mid + 1;
		}

		return (nums[lo] < target) ? lo+1 : lo;
	}
};

int main()
{
	vector<int> nums = {};
	int target = 2;
	Solution sol;
	cout << sol.searchInsert(nums, target) << endl;

	return 0;
}