#include<string>
#include<unordered_set>
#include<algorithm>
#include<iostream>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int n = s.size();
		unordered_set<char> set;
		int length = 0,temp = 0;
		for (int i = 0; i < n; ++i)
		for (int j = temp; j < n; ++j)
		{
			if (set.find(s[j]) == set.end())
			{
				set.insert(s[j]);
				length = max(length, j+1 - i);
			}
			else
			{
				temp = j;
				set.erase(s[i]);
				break;
			}
		}
		return length;
	}
};

int main()
{
	string s = "1312454123423";
	Solution solution;

	cout << solution.lengthOfLongestSubstring(s) << endl;

	return 0;
}