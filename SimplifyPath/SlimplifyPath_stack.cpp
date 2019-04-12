#include<iostream>
#include<string>
#include<stack>
//c++�����������������
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
			//ticks ���ν�ջ��Ԫ����ǰ��
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