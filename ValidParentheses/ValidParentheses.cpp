#include<iostream>
#include<string>
#include<stack>
using namespace::std;

class Solution {
public:
	bool isValid(string s) {
			stack<char> stk;
			for (auto c : s)
			{
				if (c == '(' || c == '{' || c == '[')
					stk.push(c);
				else
				{
					if (stk.empty() || (c == ')' && stk.top() != '(') || (c == '}' && stk.top() != '{') || (c == ']' && stk.top() != '[')) return false;
					stk.pop();
				}
			}
			return stk.empty();
	}
};

int main()
{
	string s = "()[]{}";
	Solution sol;
	cout << sol.isValid(s) << endl;

	return 0;
}