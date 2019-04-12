#include<cstring>
#include<unordered_set>
#include<algorithm>
#include<iostream>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int n = s.size();
		int length = 0;
		for (int i = 0; i < n; ++i)
		for (int j = i + 1; j <= n;++j)
		{
			if (AllUnique(s, i, j)) length = max(length, j - i);
		}
		return length;
	}
public:
	bool AllUnique(string s,int start,int end)
	{
		unordered_set<char> set;
		for (int i = start; i < end; ++i)
		{
			char c = s[i];
			if (set.find(c) != set.end())
				return false;
			set.insert(c);
		}

		return true;
	}
};

int main()
{
	string s = "1231231234";
	Solution solution;
	int l = solution.lengthOfLongestSubstring(s);
	cout << l<< endl;
	return 0;
}