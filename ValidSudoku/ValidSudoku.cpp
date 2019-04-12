#include<iostream>
#include<vector>

using namespace::std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		int row[3][9][9] = {0};
		for (int i = 0; i < 9;i++)
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] != '.')
			{
				int num = board[i][j] - '1';
				if (row[0][i][num] + row[1][j][num] + row[2][i / 3 * 3 + j / 3][num] >0)
					return false;
				else
					row[0][i][num] = row[1][j][num] = row[2][i / 3 * 3 + j / 3][num] = 1;
			}
		}
		return true;
	}
};

int main()
{
	vector<vector<char>> a = {
	};
	Solution sol;

	cout << sol.isValidSudoku(a) << endl;

	return 0;
}