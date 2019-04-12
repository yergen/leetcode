#include<iostream>
#include<vector>
#include<string>

using namespace::std;

class Solution {
public:
	int totalNQueens(int n) {
		int res = 0;
		//temp[i] 代表第i行第temp[i]列放置皇后。
		vector<int> temp(n, -1);
		totalNQueens(res, temp, 0);

		return res;
	}

	void totalNQueens(int& res, vector<int> temp, int row)
	{
		int n = temp.size();
		if (row == n)
		{
			res++;
		}
		else
		{
			for (int col = 0; col < n; ++col)
			{
				if (isValid(temp, row, col))
				{
					temp[row] = col;
					totalNQueens(res, temp, row + 1);
					//回溯
					temp[row] = -1;
				}
			}
		}
	}

	bool isValid(vector<int>& temp, int row, int col)
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
	sum = sol.totalNQueens(8);
	cout << "sum : " << sum << endl;

	return 0;
}