#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace::std;

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int> >res;
		backtrack(res, 0, nums);
		return res;
	}
private:
	void backtrack(vector<vector<int>>& res,int start,vector<int> nums)
	{
		if (start == nums.size() - 1)
		{
			res.push_back(nums);
		}
		else
		{
			for (int k = start; k < nums.size(); k++)
			{
				if (start != k && nums[start] == nums[k]) continue;
				swap(nums[start], nums[k]);
				backtrack(res, start + 1, nums);
			}
		}
	}
};

int main()
{
	vector<int> nums = { 1, 2, 1, 2 };
	Solution sol;
	vector <vector<int>> res;
	res = sol.permute(nums);
	for (auto nums : res)
	{
		for (auto num : nums)
			cout << num << " ";
		cout << endl;
	}

	return 0;
}