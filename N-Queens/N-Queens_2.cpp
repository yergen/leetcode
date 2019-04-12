#include<iostream>
#include<vector>
#include<string>

using namespace::std;

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> res;
		//temp[i] 代表第i行第temp[i]列放置皇后。
		vector<int> temp(n, -1);
		solveNQueens(res, temp, 0);

		return res;
	}

	void solveNQueens(vector<vector<string>>& res, vector<int> temp, int row)
	{
		int n = temp.size();
		if (row == n)
		{
			vector<string> temp_res(n,string(n,'.'));
			for (int i = 0; i < n; ++i)
				temp_res[i][temp[i]] = 'Q';
			res.push_back(temp_res);
		}
		else
		{
			for (int col = 0; col < n; ++col)
			{
				if (isValid(temp, row, col)) 
				{
					temp[row] = col;
					solveNQueens(res, temp, row + 1);
					//回溯
					temp[row] = -1;
				}
			}
		}
	}

	bool isValid(vector<int>& temp, int row,int col)
	{
		for (int i = 0; i < row; ++i)
		{
			if (temp[i] == col || abs(row - i) == abs(col - temp[i])) 
				return false;
		}

		return true;
	}
};

int main()
{
	Solution sol;
	int sum = 0;
	vector<vector<string>> res;
	res = sol.solveNQueens(8);
	for (auto Vstring : res)
	{
		for (auto str : Vstring)
		{
			cout << str << endl;
		}
		cout << endl;
		sum++;
	}
	cout << "sum : " << sum << endl;

	return 0;
}