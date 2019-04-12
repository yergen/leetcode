#include<iostream>
#include<vector>
#include<string>

using namespace::std;

class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		solve(board);
	}
public:
	bool solve(vector<vector<char>>& board)
	{
		for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] == '.')
			{
				for (char c = '1'; c <= '9'; c++) //trial. try 1 through 9
				{
					if (isValid(board, i, j, c))
					{
						board[i][j] = c; //put c for this cell

						if (solve(board))
							return true;
						else
							board[i][j] = '.';//otherwise go back;
					}
				}
				return false;
			}
		}
		return true;
	}

private:
	bool isValid(vector<vector<char>>& board, int row, int col, char c)
	{
		for (int i = 0; i < 9; i++)
		{
			if ((board[i][col]) != '.' && board[i][col] == c) return false; //�˶�ĳ�е�������
			if ((board[row][i]) != '.' && board[row][i] == c) return false;//�˶�ĳ�е�������
			if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] != '.' &&
				board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
			//�˶�ĳ��ĳ�����ڿ������Ԫ��  3*(row/3) ��ʼ�� 3*(col/3)��ʼ�� 
		}

		return true;
	}
};

int main()
{
	vector<vector<char>> sudoku =
		/*{
			{ '5', '3', '.', '.', '7', '.', '.', '.', '.' },
			{ '6', '.', '.', '1', '9', '5', '.', '.', '.' },
			{ '.', '9', '8', '.', '.', '.', '.', '6', '.' },
			{ '8', '.', '.', '.', '6', '.', '.', '.', '3' },
			{ '4', '.', '.', '8', '.', '3', '.', '.', '1' },
			{ '7', '.', '.', '.', '2', '.', '.', '.', '6' },
			{ '.', '6', '.', '.', '.', '.', '2', '8', '.' },
			{ '.', '.', '.', '4', '1', '9', '.', '.', '5' },
			{ '.', '.', '.', '.', '8', '.', '.', '7', '9' },
			};*/
	{
		{ '1', '.', '7', '6', '.', '.', '4', '.', '2' },
		{ '.', '.', '.', '9', '.', '5', '.', '.', '.' },
		{ '.', '.', '.', '4', '.', '.', '.', '1', '9' },
		{ '.', '8', '.', '.', '.', '.', '.', '.', '4' },
		{ '2', '.', '.', '.', '.', '.', '.', '.', '.' },
		{ '7', '.', '4', '.', '.', '.', '2', '.', '.' },
		{ '.', '5', '.', '.', '4', '.', '.', '.', '7' },
		{ '.', '.', '6', '8', '.', '.', '.', '.', '.' },
		{ '.', '.', '.', '.', '.', '.', '1', '9', '.' },
	};

	Solution sol;
	sol.solveSudoku(sudoku);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cout << sudoku[i][j] << " ";
		cout << endl;
	}
	cout << endl;

	return 0;
}