#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace::std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int n = strs.size();
		if (n == 0)
			return "";
		int minString = int(strs[0].size());
		for (int i = 1; i < n; i++)
			minString = min(int(strs[i].size()), minString);
		string prefix = "";
		int j;
		for (int i = 0; i < minString; i++)
		{
			for (j = 1; j < n; j++)
			{
				if (strs[j][i] != strs[0][i])
					break;
			}
			if (j == n)
				prefix += strs[0][i];
			else
				return prefix;
		}
		return prefix;
	}
};

int main()
{
	vector<string> str = {""};
	Solution sol;
	cout << sol.longestCommonPrefix(str) << endl;
	return 0;
}