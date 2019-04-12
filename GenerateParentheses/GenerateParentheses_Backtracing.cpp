#include<vector>
#include<string>
#include<iostream>

using namespace::std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {	//Backtracking
		vector<string> res;
		backtrack(res, "", 0, 0, n);
		return res;
	}

	void backtrack(vector<string> &result, string current,int open,int close,int max){
		if (current.size() == 2 * max)
		{
			result.push_back(current);
			return ;
		}
		if (open < max)//Start an opening bracket if we still have one (of n) left to place
			backtrack(result, current+'(', open + 1, close, max);
		if (close < open)//Start a closing bracket if it would not exceed the number of opening brackets
			backtrack(result, current + ')', open, close + 1, max);
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