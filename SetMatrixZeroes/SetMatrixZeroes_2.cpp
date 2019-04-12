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
		int MODIFIED = -1000000;
		int m = matrix.size();
		if (m == 0) return;
		int n = matrix[0].size();

		for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
		{
			if (matrix[i][j] == 0)
			{
				for (int k = 0; k < n; ++k)
				{
					if (matrix[i][k] != 0)
						matrix[i][k] = MODIFIED;
				}	
				for (int k = 0; k < m; ++k)
				{
					if (matrix[k][j] != 0)
						matrix[k][j] = MODIFIED;
				}
			}
		}

		for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
		{
			if (matrix[i][j] == MODIFIED)
				matrix[i][j] = 0;
		}
	}
};

int main()
{
	vector<vector<int>> matrix = { { 1, 1, 1, }, { 1, 0, 1 }, { 1, 1, 1 } };
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