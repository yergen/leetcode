#include<iostream>
#include<vector>
#include<algorithm>

using namespace::std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		int n = nums.size();
		for (int i = 0; i < pow(2, n); i++)
		{
			vector<int> temp;
			for (int j = 0; j < n; j++)
			{
				if (i & 1 << j)
					temp.push_back(nums[j]);
			}
			res.push_back(temp);
		}

		return res;
	}
};

int main()
{
	vector<int> nums = { 1, 2, 3 };
	Solution sol;
	vector<vector<int>> res = sol.subsets(nums);
	for (auto re : res)
	{
		for (auto r : re)
			cout << r << " ";
		cout << endl;
	}
	return 0;
}