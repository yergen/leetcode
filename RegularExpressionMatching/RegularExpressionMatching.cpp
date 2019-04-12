#include<iostream>
using namespace::std;
class Solution {
public:
	bool isMatch(string s, string p) {
		if (p.empty()) return s.empty();
		//��һ���ַ�ƥ��
		bool first_match = (!s.empty() && (s[0] == p[0] || p[0] == '.'));
		if (p.size() >= 2 && p[1] == '*')
			//*֮���ƥ��                      //*ƥ��
			return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
		else
			//��*���ַ����ƥ��
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