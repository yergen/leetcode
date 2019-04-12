#include<iostream>
#include<vector>

using namespace::std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int lo = 0, hi = nums.size() - 1;
		while (lo <= hi)//=号必须加 排除[target] target 
		{
			int mid = (lo + hi) / 2;
			//判断中位数和目标值是否在同一边(相等算同一边)。
			if (!((nums[mid] >= nums[0]) ^ (target >= nums[0])))
			{
				if (nums[mid] == target) return mid;
				if (nums[mid] > target) hi = mid - 1;//-1 排除[1,3] 2
				else lo = mid + 1;
			}
			else
			{
				//目标在右边
				if (nums[mid] > target) lo = mid + 1;
				//目标在左边
				else hi = mid - 1;//-1 排除[1,2,0] 3
			}
		}
		return  -1;
	}
};

int main()
{
	vector<int> nums = {1,2,3};
	Solution sol;
	cout << sol.search(nums, 2) << endl;

	return 0;
}