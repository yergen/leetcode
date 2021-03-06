#include<iostream>
#include<vector>
#include<string>

using namespace::std;

class Solution {
private:
	vector<vector<string> > res;
	int upperlim;
public:
	vector<vector<string> > solveNQueens(int n) {
		upperlim = (1 << n) - 1;//低n位全部置1
		vector<string> cur(n, string(n, '.'));
		helper(0, 0, 0, cur, 0);
		return res;
	}

	void helper(const int row, const int ld, const int rd, vector<string>&cur, const int index)
	{
		int pos, p;
		if (row != upperlim)
		{
			pos = upperlim & (~(row | ld | rd));//pos中二进制为1的位，表示可以在当前行的对应列放皇后
			//和upperlim与运算，主要是ld在上一层是通过左移位得到的，它的高位可能有无效的1存在，这样会清除ld高位无效的1
			while (pos)
			{
				p = pos & (~pos + 1);//获取pos最右边的1,例如pos = 010110，则p = 000010
				pos = pos - p;//pos最右边的1清0
				setQueen(cur, index, p, 'Q');//在当前行，p中1对应的列放置皇后
				helper(row | p, (ld | p) << 1, (rd | p) >> 1, cur, index + 1);//设置下一行
				setQueen(cur, index, p, '.');
			}
		}
		else//找到一个解
			res.push_back(cur);
	}

	//第row行，第loc1(p)列的位置放置一个queen或者清空queen，loc1(p)表示p中二进制1的位置
	void setQueen(vector<string>&cur, const int row, int p, char val)
	{
		int col = 0;
		while (!(p & 1))
		{
			p >>= 1;
			col++;
		}
		cur[row][col] = val;
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
		if (sum == 1)
			break;
	}
	cout << "sum : " << sum << endl;

	return 0;
}