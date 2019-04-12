#include<iostream>
#include<vector>

using namespace::std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int m = matrix.size();
		if (m == 0) return{};
		int n = matrix[0].size();
		vector<int> res;
		//行的左右边界
		int r1 = 0, r2 = m - 1;
		//列的左右边界
		int c1 = 0, c2 = n - 1;
		while (r1 <= r2 && c1 <= c2)
		{
			for (int c = c1; c <= c2; c++) res.push_back(matrix[r1][c]);
			for (int r = r1 + 1; r <= r2; r++) res.push_back(matrix[r][c2]);
			if (r1 < r2 && c1 < c2)
			{
				for (int c = c2 - 1; c > c1; c--) res.push_back(matrix[r2][c]);
				for (int r = r2; r > r1; r--) res.push_back(matrix[r][c1]);
			}
			r1++;
			r2--;
			c1++;
			c2--;
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
	res = sol.spiralOrder(matrix1);
	for (auto i : res)
		cout << i << " ";
	cout << endl;

	return 0;
}