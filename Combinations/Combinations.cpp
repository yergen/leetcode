#include<iostream>
#include<vector>

using namespace::std;

class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		if (k > n) return{};
		vector<vector<int>> res;
		vector<int> temp;
		combine(n, k, res, temp);
		return res;
	}

private:
	void combine(int n, int k, vector<vector<int>> &res,vector<int> temp)
	{
		if (k == 0)
		{
			res.push_back(temp);
		}
		else
		{
			for (int i = n; i >= 1; --i)
			{
				temp.push_back(i);
				combine(i - 1, k - 1, res, temp);
				temp.pop_back();
			}
		}
	}
};

int main()
{
	int n = 4, k = 2;
	Solution sol;
	vector<vector<int>> res = sol.combine(n, k);

	for (auto re : res)
	{
		for (auto r : re)
			cout << r << " ";
		cout << endl;
	}

	return 0;
}