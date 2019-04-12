#include<iostream>
#include<vector>
#include<string>

using namespace::std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		if (n == 0) 
			res.push_back("");
		else
		{
			for (int c = 0; c < n; c++)
			for (auto left : generateParenthesis(c))
			for (auto right : generateParenthesis(n - c - 1))
				res.push_back("(" + left + ")" + right);
		}

		return res;
	}
};

int main()
{
	Solution sol;
	int n = 3;
	vector<string> r = sol.generateParenthesis(n);
	for (string s : r){
		cout << s << endl;
	}

	return 0;
}