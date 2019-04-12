#include<iostream>
#include<vector>

using namespace::std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int m = matrix.size();
		if (m == 0) return{};
		int n = matrix[0].size();
		//必须初始化否则报错。
		vector<vector<bool>> seen(m,vector<bool>(n,false));
		vector<int> res;
		int dr[] = { 0, 1, 0, -1 };
		int dc[] = { 1, 0, -1, 0 };
		int r = 0, c = 0, di = 0;//螺旋行进到r排，c列，di为方向。
		for (int i = 0; i < m*n; ++i)
		{
			res.push_back(matrix[r][c]);
			seen[r][c] = true;
			int cr = r + dr[di];
			int cc = c + dc[di];
			if (cr >= 0 && cr < m && cc >= 0 && cc < n && !seen[cr][cc])
			{
				r = cr;
				c = cc;
			}
			else
			{
				di = (di + 1) % 4;
				r += dr[di];
				c += dc[di];
			}
		}
		return res;
	}
};

int main()
{
	vector<vector<int>> matrix = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	vector<vector<int>> matrix1 = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
	vector<vector<int>> matrix2 = { { 1 }, { 2 }, { 3 } };
	Solution sol;
	vector<int> res;
	res = sol.spiralOrder(matrix);
	for (auto i : res)
		cout << i << " ";
	cout << endl;

	return 0;
}