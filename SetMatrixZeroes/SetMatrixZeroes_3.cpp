#include<iostream>
#include<vector>

using namespace::std;
/*
*time complexity:O(M*N) * (M+N)
*space complexity:O(1)
*/
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.size();
		if (m == 0) return;
		int n = matrix[0].size();
		int iscol = 0;
		for (int i = 0; i < m; ++i)
		{
			if (matrix[i][0] == 0) iscol = 1;
			//start j=1
			for (int j = 1; j < n; ++j)
			{
				if (matrix[i][j] == 0)
				{
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}

		for (int i = m - 1; i >= 0; --i)
		{
			for (int j = n - 1; j > 0; --j)
			{
				if (matrix[i][0] == 0 || matrix[0][j] == 0)
					matrix[i][j] = 0;
			}
			if (iscol) matrix[i][0] = 0;
		}

	}
};

int main()
{
	vector<vector<int>> matrix = { { 0, 1, 2, 0 }, { 3, 4, 5, 2 }, { 1, 3, 1, 5 } };
	Solution sol;
	sol.setZeroes(matrix);
	for (auto mat : matrix)
	{
		for (auto m : mat)
			cout << m << " ";
		cout << endl;
	}
	return 0;
}