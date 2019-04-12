#include<string>
#include<unordered_map>
#include<algorithm>
#include<iostream>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int n = s.size();
		unordered_map<char,int> map;
		int length = 0, i = 0;
		for (int j = 0; j < n; ++j)
		{
			if (map.find(s[j]) != map.end())
			{
				i = max(map[s[j]], i);
				map[s[j]] = j + 1;
			}
			else
			{
				map.insert({ s[j], j + 1 });
			}
			
			length = max(length, j - i + 1);
		}
		return length;
	}
};

int main()
{
	string s = "abcabcbb";
	Solution solution;

	cout << solution.lengthOfLongestSubstring(s) << endl;

	return 0;
}