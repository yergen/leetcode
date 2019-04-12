#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace::std;
// ±º‰∏¥‘”∂»£∫O(|S| + |T|)
class Solution {
public:
	string minWindow(string s, string t) {
		int m = s.size(), n = t.size();
		if (m < n) return "";
		//pari<int, char>
		vector<pair<int, char>> filtered_S;
		unordered_map<char, int> s_map;
		unordered_map<char, int> t_map;
		
		for (int i = 0; i < n; ++i)
			t_map[t[i]]++;

		int required = t_map.size();
		for (int i = 0; i < m; ++i)
		{
			if (t_map.find(s[i]) != t_map.end())
				filtered_S.push_back({ i, s[i] });
		}

		int left = 0, right = 0;
		int formed = 0;
		vector<int> res{ -1, 0, 0 };

		while (right < filtered_S.size())
		{
			char c =filtered_S[right].second;
			s_map[c]++;
			if (s_map[c] == t_map[c])
				formed++;
			
			while (left <= right && formed == required)
			{
				char w = filtered_S[left].second;
				int start = filtered_S[left].first;
				int end = filtered_S[right].first;

				if (res[0] == -1 || end - start + 1 < res[0])
				{
					res[0] = end - start + 1;
					res[1] = start;
					res[2] = end;
				}

				s_map[w]--;
				if (s_map[w] < t_map[w])
					formed--;

				left++;
			}
			right++;
		}
		return res[0] == -1 ? "" : s.substr(res[1], res[0]);
	}
};

int main()
{
	string s = "ADOBECODEBANC";
	string t = "ABC";

	Solution sol;
	cout << sol.minWindow(s, t) << endl;
	return 0;
}