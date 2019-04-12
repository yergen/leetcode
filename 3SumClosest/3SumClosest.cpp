#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace::std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int n = nums.size(),result=nums[0]+nums[1]+nums[2];
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n - 2; i++)
		{
			if (i>0 && nums[i] == nums[i - 1]) continue;
			int start = i + 1, end = n - 1;
			while (start < end)
			{
				int sum = nums[i] + nums[start] + nums[end];
				if (abs(sum - target) < abs(result - target))
					result = sum;
				sum>target ? end--: start++;
			}
		}
		return result;
	}
};

int main()
{
	vector<int> a = { -1, 2, 1, -4 };
	int target = 1;
	Solution sol;
	cout << sol.threeSumClosest(a,target) << endl;
	return 0;
}