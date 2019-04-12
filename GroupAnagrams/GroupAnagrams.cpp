#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace::std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		vector<string> temp;
		for (int i = 0; i < strs.size(); ++i)
		{
			string s = strs[i];
			sort(s.begin(), s.end());
			int j = 0;
			for (; j < temp.size(); ++j)
			{
				if (temp[j] == s)
				{
					res[j].push_back(strs[i]);
					break;
				}
			}
			if (j == temp.size())
			{
				temp.push_back(s);
				res.push_back({ strs[i] });
			}
		}

		return res;
	}
};

int main()
{
	vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
	vector<vector<string>> res;
	Solution sol;
	res = sol.groupAnagrams(strs);
	for (auto list_strs : res)
	{
		for (auto str : list_strs)
			cout << str << " ";
		cout << endl;
	}
	cout << endl;

	return 0;
}