#include<iostream>
#include<vector>
#include<string>

using namespace::std;
//ʱ�临�Ӷȣ�O(|S| + |T|)
class Solution {
public:
	string minWindow(string s, string t) {
		vector<int> map(128, 0);
		//��������ַ�����һ������
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