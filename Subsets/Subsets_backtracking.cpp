#include<iostream>
#include<vector>
#include<algorithm>

using namespace::std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> temp;
		subsets(nums, 0, res, temp);
		return res;
	}
private:
	void subsets(vector<int>& nums, int start, vector<vector<int>>& res,vector<int> temp)
	{
		res.push_back(temp);
		for (int i = start; i < nums.size(); ++i)
		{
			temp.push_back(nums[start]);
			subsets(nums, i + 1, res, temp);
			temp.pop_back();
		}
	}
};

int main()
{
	vector<int> nums = { 1, 2, 3, 4 };
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