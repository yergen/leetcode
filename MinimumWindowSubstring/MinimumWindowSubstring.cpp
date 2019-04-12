#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace::std;
//ʱ�临�Ӷȣ�O(|S| + |T|)
class Solution {
public:
	string minWindow(string s, string t) {
		int m = s.size(), n = t.size();
		if (m < n) return "";
		unordered_map<char, int> t_map;
		unordered_map<char, int> s_map;
		for (int i = 0; i < t.size(); ++i)
			t_map[t[i]]++;
		//t_map����ĸ�ĸ���
		int required = t_map.size();
		//left:���ڵ���߽� right:���ڵ��ұ߽� 
		//formed:���ڰ���t_map����ĸ��(��ĸ�ĸ������ڵ���t_map�е���ĸ������һ��)
		int left = 0, right = 0, formed = 0;
		//���ν���ĳ��ȡ�����������������
		vector<int> res{ -1, 0, 0 };

		while (right < m)
		{
			char c = s[right];
			s_map[c]++;
			//�����ǰ����ַ���Ƶ�ʵ���������Ƶ��formed��һ
			if (t_map.find(c) != t_map.end() && s_map[c] == t_map[c])
				formed++;

			while (left <= right && formed == required)
			{
				char w = s[left];
				//ֱ�����ڱ������С�Ĵ�����Ϣ
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