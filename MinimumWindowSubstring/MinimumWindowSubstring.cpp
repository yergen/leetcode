#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace::std;
//时间复杂度：O(|S| + |T|)
class Solution {
public:
	string minWindow(string s, string t) {
		int m = s.size(), n = t.size();
		if (m < n) return "";
		unordered_map<char, int> t_map;
		unordered_map<char, int> s_map;
		for (int i = 0; i < t.size(); ++i)
			t_map[t[i]]++;
		//t_map中字母的个数
		int required = t_map.size();
		//left:窗口的左边界 right:窗口的右边界 
		//formed:窗口包含t_map的字母数(字母的个数大于等于t_map中的字母个数算一个)
		int left = 0, right = 0, formed = 0;
		//依次结果的长度、左索引、右索引。
		vector<int> res{ -1, 0, 0 };

		while (right < m)
		{
			char c = s[right];
			s_map[c]++;
			//如果当前添加字符的频率等于期望的频率formed加一
			if (t_map.find(c) != t_map.end() && s_map[c] == t_map[c])
				formed++;

			while (left <= right && formed == required)
			{
				char w = s[left];
				//直到现在保存的最小的窗口信息
				if (res[0] == -1 || right - left + 1 < res[0])
				{
					res[0] = right - left + 1;
					res[1] = left;
					res[2] = right;
				}

				s_map[w]--;

				if (t_map.find(w) != t_map.end() &&s_map[w] < t_map[w])
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
	string t = "ABCD";

	Solution sol;
	cout << sol.minWindow(s, t) << endl;
	return 0;
}