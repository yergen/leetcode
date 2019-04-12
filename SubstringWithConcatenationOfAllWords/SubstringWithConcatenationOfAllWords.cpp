#include<iostream>
#include<vector>
#include<unordered_map>

using namespace::std;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		int k = s.size(), n = words.size(), index = 0, m = 0;
		if (n > 0)
		{
			m = words[0].size();
		}
		if (k < m*n || m==0) return{};
		//判断单词表中的单词长度是否相等。
		for (int i = 1; i < n; i++)
		{
			if (words[i].size() != m)
				return{};
		}
		//将匹配的单词表放到哈希表中，键为单词，值为单词出现的次数。
		unordered_map<string, int> words_map;
		for (auto word : words)
			words_map[word]++;

		vector<int> res = {};
		//必须一个一个对比，否则有遗漏。
		for (;index <= k - m*n; index++)
		{
			unordered_map<string, int> temp;
			int j = 0;
			for (;j < n;j++)
			{
				string word = s.substr(index + j*m, m);
				if (words_map.find(word) != words_map.end())
				{
					temp[word]++;
					if (temp[word] > words_map[word])
						break;
				}
				else
					break;
			}
			if (j == n)
				res.push_back(index);
		}

		return res;
	}
};

int main()
{
	string s = "aaaaaa";
	vector<string> words = {"aa","aa"};
	Solution sol;
	vector<int> result = sol.findSubstring(s, words);
	for (auto i : result)
		cout << i << " ";
	cout << endl;
	return 0;
}