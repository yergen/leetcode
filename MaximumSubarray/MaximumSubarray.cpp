#include<vector>
#include<iostream>

using namespace::std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		vector<int> res;
		res = findMaxSubArray(nums, 0, nums.size() - 1);
		return res[2];
	}
private:
	vector<int> findMaxSubArray(vector<int>& nums, int low, int high)
	{
		if (low == high)
			return { low, high, nums[low] };
		else
		{
			int	mid = (low + high) / 2;
			vector<int> left = findMaxSubArray(nums, low, mid);
			vector<int> right = findMaxSubArray(nums, mid + 1, high);
			vector<int> cross = findMaxCrossSubArray(nums, low, mid, high);

			if (left[2] >= right[2] && left[2] >= cross[2])
				return left;
			else if (right[2] >= left[2] && right[2] >= cross[2])
				return right;
			else
				return cross;
		}
	}
	vector<int> findMaxCrossSubArray(vector<int>& nums, int low, int mid, int high)
	{
		int left_sum = INT_MIN, left_index = mid;
		int sum = 0;
		for (int i = mid; i >= low; --i)
		{
			sum += nums[i];
			if (sum > left_sum)
			{
				left_sum = sum;
				left_index = i;
			}
		}

		int right_sum = INT_MIN, right_index = mid + 1;
		sum = 0;
		for (int i = mid + 1; i <= high; ++i)
		{
			sum += nums[i];
			if (sum > right_sum)
			{
				right_sum = sum;
				right_index = i;
			}
		}

		return { left_index, right_index, left_sum + right_sum };
	}

};

int main()
{
	vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	Solution sol;
	cout << sol.maxSubArray(nums) << endl;
	return 0;
}