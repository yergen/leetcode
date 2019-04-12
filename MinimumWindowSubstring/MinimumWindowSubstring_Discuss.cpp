#include<iostream>
#include<vector>
#include<string>

using namespace::std;
//时间复杂度：O(|S| + |T|)
class Solution {
public:
	string minWindow(string s, string t) {
		vector<int> map(128, 0);
		//把里面的字符看做一个整体
		for (auto c : t) map[c]++;
		int n = t.size();
		int left = 0, right = 0, head = 0, d = INT_MAX;
		while (right < s.size())
		{
			//s[right] in t
			if (map[s[right++]]-- > 0) n--;
			while (n == 0)
			{
				if (right - left< d) d = right - (head = left);
				if (map[s[left++]]++ == 0) n++;
			}
		}
		return d == INT_MAX ? "" : s.substr(head, d);
	}
};

int main()
{
	string s = "AB";
	string t = "A";

	Solution sol;
	cout << sol.minWindow(s, t) << endl;
	return 0;
}