#include<iostream>
#include<vector>
using namespace::std;


class Solution {
public:
	bool isMatch(string s, string p) {
		int m = s.size(),n=p.size();

		vector<vector<int>>memo(m + 1, vector<int>(n + 1, -1));
		return dp(0, 0, s, p,memo);
	}

	bool dp(int i, int j, string s, string p, vector<vector<int>>&memo)
	{
		if (memo[i][j] != -1)
			return memo[i][j] == 1;
		bool ans;
		if (p.size() == j) 
			ans = (i == s.size());
		else
		{
			bool first_match = (i < s.size() && (p[j] == s[i] || p[j] == '.'));

			if (j + 1 < p.size() && p[j + 1] == '*')
			{
				ans = (dp(i, j + 2, s, p,memo) || (first_match && dp(i + 1, j, s, p,memo)));
			}
			else
			{
				ans = first_match && dp(i + 1, j + 1, s, p,memo);
			}
		}
		memo[i][j] = ans ? 1 : 0;

		return ans;
	}
};

int main()
{
	string s = "ab", p = ".*c";
	Solution sol;
	cout << sol.isMatch(s, p) << endl;
	return 0;
}