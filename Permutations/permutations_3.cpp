#include<iostream>
#include<vector>
#include<algorithm>

using namespace::std;
//time complexity: n!
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> result;
		permuteRecursive(nums, 0, result);
		return result;
	}
private:
	void permuteRecursive(vector<int> &nums, int begin, vector<vector<int> > &result)	
	{
		//到n-1即可输出，因为最后一步不做任何改变。
		if (begin == nums.size() -1) 
		{
			result.push_back(nums);
			return;
		}
		for (int i = begin; i < nums.size(); i++) 
		{
			swap(nums[begin], nums[i]);
			permuteRecursive(nums, begin + 1, result);
			// 相当于回溯
			swap(nums[begin], nums[i]);
		}
	}
};

int main()
{
	vector<int> nums = { 1, 2, 3};
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