#include<string>
#include<stdio.h>
#include<algorithm>
#include<iostream>

using namespace std;
class Solution {
public:
	string longestPalindrome(string s) {
		int start = 0, end = 0;
		string string1, string2, string3;
		int length = s.size();
		if (length <= 1) return s;
		for (int i = 0; i < length; ++i)
		{
			string1 = expandAroundCenter(s, i, i);
			string2 = expandAroundCenter(s, i, i + 1);
			if (string1.length() >= string3.length())
				string3 = string1;
			if (string2.length() >= string3.length())
				string3 = string2;
		}
		return string3;
	}
private: 
	string expandAroundCenter(string s, int left, int right)
{
		int L = left, R = right;
		int length = s.size();
		while(L >= 0 && R < length && s[L] == s[R])
		{
			L--;
			R++;
		}
		//不返回具体字符串长度，判断中间符是两字符之间还是单个字符不好处理。
		//substr(a,b) a:字符串的开始位置 b:指定的长度
		return s.substr(L+1,R-L-1);
}
};

int main()
{
	string s = "cbbd";
	Solution solution;
	cout << solution.longestPalindrome(s) << endl;
	return 0;
}