#include<iostream>
#include<string>
#include<stack>
//c++串流的输入输出操作
#include<sstream>

using namespace::std;

class Solution {
public:
	string simplifyPath(string path) {
		string res, tmp;
		stack<string> stk;
		stringstream ss(path);
		while (getline(ss, tmp, '/'))
		{
			if (tmp == "" || tmp == ".") continue;
			if (tmp == "..")
			{
				if (!stk.empty()) stk.pop();
			}
			else
				stk.push(tmp);
		}
		while (!stk.empty())
		{
			//ticks 依次将栈顶元素往前放
			res = '/' + stk.top() + res;
			stk.pop();
		}

		return res.empty() ? "/" : res;
	}
};

int main()
{
	string path = "/home/";
	Solution sol;
	cout << sol.simplifyPath(path) << endl;

	return 0;
}