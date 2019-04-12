#include<vector>
#include<iostream>
#include<algorithm>

using namespace::std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int max_sum = nums[0];
		int res = max_sum;
		//卡丹算法
		for (int i = 1; i < nums.size(); ++i)
		{
			//[j,i]最大的和。
			max_sum = max(max_sum+nums[i],nums[i]);
			//[0,i]最大的和是max([0,i-1],[j,i])。
			res = max(max_sum, res);
		}
		return res;
	}
};

int main()
{
	vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	Solution sol;
	cout << sol.maxSubArray(nums) << endl;
	return 0;
}