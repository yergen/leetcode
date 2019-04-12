#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>

using namespace::std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> count;
		int i = 0;
		for (auto s : strs)
		{
			sort(s.begin(), s.end());
			count[s].push_back(strs[i++]);
		}
		vector<vector<string>> res;
		for (auto n : count){
			sort(n.second.begin(), n.second.end());
			res.push_back(n.second);
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