#include<iostream>
#include<vector>

using namespace::std;
/*
 *time complexity:O(M*N) 
 *space complexity:O(M+N)
 */
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.size();
		if (m == 0) return;
		int n = matrix[0].size();

		vector<int> row(m, 0), col(n, 0);
		for (int i = 0; i < m;++i)
		for (int j = 0; j < n; ++j)
		{
			if (matrix[i][j] == 0)
			{
				row[i] = 1;
				col[j] = 1;
			}
		}
		
		for (int i = 0; i < m;++i)
		for (int j = 0; j < n;++j)
		{
			if (row[i] || col[j])
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