#include<iostream>
#include<vector>
#include<algorithm>

using namespace::std;

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		//change from"for(... && target >= candidates[i])" to "for(... && target >= 0)" in backTracking function.
		//sort(candidates.begin(), candidates.end()); 		//it is unnecessary 
		std::vector<std::vector<int> > res;//the final results
		std::vector<int> combination;//a  tempure result for backTracking.
		backTracking(candidates, 0, target, res, combination);

		return res;
	}
private:
	void backTracking(vector<int>& candidates, int index, int target, vector<vector<int>> &res, vector<int> &combination)
	{
		if (!target)
		{
			res.push_back(combination);
			return;
		}
		for (int i = index; i < candidates.size() && target >= 0; ++i)
		{
			combination.push_back(candidates[i]);
			backTracking(candidates, i, target - candidates[i], res, combination);
			combination.pop_back();//pop the wrong element.
		}
	}
};

int main()
{
	vector<int> candidates = { 2, 3, 6, 7 };
	int target = 7;

	Solution sol;
	vector<vector<int>> SumSet = sol.combinationSum(candidates,target);

	for (auto i : SumSet)
	{
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}
	cout << endl;

	return 0;
}

