#include<iostream>
#include<vector>
#include<string>

using namespace::std;

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> res;
		vector<string> temp(n,string(n,'.'));
		solveNQueens(res,temp,0);

		return res;
	}

	void solveNQueens(vector<vector<string>>& res,vector<string> temp,int row)
	{
		if (row == temp.size())
			res.push_back(temp);
		else
		{
			for (int col = 0; col < temp.size(); ++col)
			{
				if (isValid(temp, row, col))
				{
					temp[row][col] = 'Q';
					solveNQueens(res, temp, row + 1);
					//回溯
					temp[row][col] = '.';
				}
			}
		}
	}

	bool isValid(vector<string>& temp,int row,int col)
	{
		//列
		for (int i = 0; i < row; ++i)
		{
			if (temp[i][col] == 'Q') 
				return false;
		}
		//左上角
		for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
		{
			if (temp[i][j] == 'Q') 
				return false;
		}
		//右上角
		for (int i = row - 1, j = col + 1; i >= 0 && j < temp.size(); i--, j++)
		{
			if (temp[i][j] == 'Q')
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
	res = sol.solveNQueens(4);
	for (auto Vstring : res)
	{
		for (auto str : Vstring)
		{
			cout << str << endl;
		}
		cout << endl;
		sum++;
	}
	cout << "sum : "<< sum << endl;

	return 0;
}