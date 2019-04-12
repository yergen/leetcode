#include<iostream>
#include<vector>
#include<algorithm>

using namespace::std;

class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
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
		for (int i = index; i < candidates.size() && target >= candidates[i]; ++i)
		{
			if (i == index || candidates[i] != candidates[i - 1])//ensure not contain duplicate combinations.except:[1,1,1,] 2
			{
				combination.push_back(candidates[i]);
				backTracking(candidates, i+1, target - candidates[i], res, combination);
				combination.pop_back();//pop the wrong element.
			}
		}
	}
};

int main()
{
	vector<int> candidates = { 1,1,1,3,4 };
	int target = 2;

	Solution sol;
	vector<vector<int>> SumSet = sol.combinationSum(candidates, target);

	for (auto i : SumSet)
	{
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}
	cout << endl;

	return 0;
}

