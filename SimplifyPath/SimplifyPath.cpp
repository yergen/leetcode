#include<iostream>
#include<string>
#include<vector>
//c++串流的输入输出操作
#include<sstream>

using namespace::std;

class Solution {
public:
	string simplifyPath(string path) {
		string res, tmp;
		vector<string> stk;
		stringstream ss(path);
		while (getline(ss, tmp, '/'))
		{
			if (tmp == "" || tmp == ".") continue;
			if (tmp == "..")
			{
				if (!stk.empty()) stk.pop_back();
			}
			else
				stk.push_back(tmp);
		}
		for (auto s : stk) res += '/' + s;

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