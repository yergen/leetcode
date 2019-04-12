#include<iostream>
#include<vector>

using namespace::std;

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		res.push_back({nums[0]});
		permute(nums,res,1);
		return res;
	}
private:
	//用尾递归实现乱序的全排列,不满足要求。
	void permute(vector<int>& nums, vector<vector<int>> &res,int index)
	{
		vector<vector<int>> temp_res;

		if (index == nums.size())
			return;
		else
		{
			for (int i = 0; i < res.size(); ++i)
			{
				vector<int> param = res[i];
				for (int j = 0; j < index + 1; ++j)
				{
					vector<int> res_param;
					res_param = param;
					res_param.insert(res_param.begin()+j, nums[index]);
					temp_res.push_back(res_param);
				}
			}
			res.clear();
			res = temp_res;
			permute(nums, res, index + 1);
		}
	}
};

int main()
{
	vector<int> nums = { 1, 2, 3 };
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