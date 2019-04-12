#include<string>
#include<unordered_map>
#include<algorithm>
#include<iostream>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int n = s.size(),length = 0;
		int index[128];

		for (int j = 0, i = 0; j < n; ++j)
		{
			i = max(index[s[j]], i);
			length = max(length, j - i + 1);
			index[s[j]] = j + 1;
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