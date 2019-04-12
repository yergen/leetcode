#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace::std;

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		map<int, int> map;
		for (auto m : nums)
			++map[m];
		vector<vector<int>> res;
		vector<int> param;
		backtrack(res, param,map,nums);
		return res;
	}
private:
	void backtrack(vector<vector<int>>& res, vector<int> &param, map<int, int>& map, vector<int>& nums)
	{	//depth of trees: nums.size()
		if (param.size() == nums.size())
		{
			res.push_back(param);
		}
		else
		{
			//map.size(): max counts of child nodes: 
			for (auto &num: map)
			{
				if (map[num.first] == 0) continue;
				param.push_back(num.first);
				num.second--;
				backtrack(res, param,map, nums);
				num.second++;
				param.pop_back();
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