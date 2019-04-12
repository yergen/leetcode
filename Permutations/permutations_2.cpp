#include<iostream>
#include<vector>
#include<algorithm>

using namespace::std;

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> param;
		backtrack(res, param, nums);
		return res;
	}
private:
	void backtrack(vector<vector<int>>& res, vector<int> &param, vector<int>& nums)
	{
		if (param.size() == nums.size())
		{
			res.push_back(param);
		}
		else
		{
			for (int i = 0; i < nums.size(); ++i)
			{
				if(find(param.begin(), param.end(), nums[i]) != param.end()) continue;
				param.push_back(nums[i]);
				backtrack(res, param, nums);
				param.pop_back();
			}
		}
	}
};

int main()
{
	vector<int> nums = { 1, 2, 3, 4, 5 };
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