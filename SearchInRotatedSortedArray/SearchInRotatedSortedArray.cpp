#include<iostream>
#include<vector>

using namespace::std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int n = nums.size();
		int lo = 0, hi = n - 1,mid;
		//找到起始最小数的下标
		while (lo < hi)
		{
			mid = (lo + hi) / 2;
			if (nums[mid] > nums[hi])
				lo = mid + 1;
			else
				hi = mid;
		}
		int rot = lo;
		lo = 0, hi = n - 1;
		while (lo <= hi )
		{
			mid = (lo + hi) / 2;
			int realmid = (mid + rot) >= n ? mid + rot - n : mid + rot;
			if (nums[realmid] == target) return realmid;
			else if (nums[realmid] < target) lo = mid + 1;
			else hi = mid-1;//排除[1] 0
		}
		return -1;
	}
};

int main()
{
	vector<int> nums = {1};
	Solution sol;
	cout << sol.search(nums, 0) << endl;
	for (auto i : nums)
		cout << i << " ";
	cout << endl;

	return 0;
}