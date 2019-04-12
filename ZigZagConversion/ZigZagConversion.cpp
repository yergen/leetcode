#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace::std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows < 1) return "";
		else if(numRows == 1) return s;

		vector<string> rows(min(numRows, int(s.size())));

		int curRow = 0;
		bool dir = false;

		for (auto c : s)
		{
			rows[curRow] += c;
			if (curRow == 0 || curRow == numRows - 1) dir = !dir;
			dir ? curRow++ : curRow--;//curRow += dir ? 1 : -1;
		}
		
		string result;
		for (auto row : rows) result += row;

		return s;

	}
};

int main()
{
	string s = "PAYPALISHIRING";
	int numRows = 2;
	Solution sol;
	cout << sol.convert(s, numRows) << endl;
	return 0;
}