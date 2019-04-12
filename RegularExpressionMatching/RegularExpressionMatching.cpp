#include<iostream>
using namespace::std;
class Solution {
public:
	bool isMatch(string s, string p) {
		if (p.empty()) return s.empty();
		//第一个字符匹配
		bool first_match = (!s.empty() && (s[0] == p[0] || p[0] == '.'));
		if (p.size() >= 2 && p[1] == '*')
			//*之后的匹配                      //*匹配
			return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
		else
			//无*单字符逐个匹配
			return first_match && isMatch(s.substr(1), p.substr(1));
	}
};

int main()
{
	string s = "aaa", p = "aaaa";
	Solution sol;
	cout << sol.isMatch(s,p) << endl;
	return 0;
}