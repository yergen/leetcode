#include<iostream>
#include<string>
#include<unordered_set>
#include<unordered_map>

using namespace::std;

class Solution {
public:
	bool isNumber(string s) {
		unordered_set<char> validSet = { '.', '+', '-', 'e' };
		unordered_map<char, int> CharMap;
		int i = 0, j = s.size() - 1,numFlag = 0;
		while (i<j && (isspace(s[i]) || isspace(s[j])))
		{
			if (isspace(s[i])) i++;
			if (isspace(s[j])) j--;
		}
		s = s.substr(i, j - i + 1);
		cout << s << endl;
		i = 0;
		while (i < s.size() && (isdigit(s[i]) || validSet.find(s[i]) != validSet.end()))
		{
			if (isdigit(s[i])) numFlag = 1;
			else
			{
				if (s[i] == '-') s[i] = '+';
				if (s[i] == '+' && numFlag) return false;
				//一个符号出现两次
				if (++CharMap[s[i]] > 1)
					return false;
				//e后有小数
				if (s[i] == '.')
				{
					if (s.size() == 1 || CharMap['e'] == 1)
						return false;
				}
				//e后有小数的情况。
				if (s[i] == 'e')
				{
					//e前没数字
					if (!numFlag) return false;
				}
				//符号为最后一个字符
				if (i == s.size() - 1)
				{
					return s[i] == '.';
				} 
				if (validSet.find(s[i + 1]) != validSet.end())
				{
					if (i == s.size() - 2)
						return false;
					else if ((s[i] == 'e' &&(s[i + 1] == '+' || s[i + 1] == '-')) || (s[i] == '.' && s[i+1] == 'e'))
					{
						i++;
						continue;
					}
					return false;
				}
			}

			i++;
		}
		return i == s.size();
	}
};

int main()
{
	string s = "   . ";
	Solution sol;
	cout << sol.isNumber(s) << endl;

	return 0;
}
