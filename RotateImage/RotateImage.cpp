#include<iostream>
#include<vector>
#include<algorithm>

using namespace::std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		for (int i = 0; i < n / 2;++i)
		for (int j = i; j < n-1-i; ++j)
		{
			//首行和最后一列交换
			swap(matrix[i][j], matrix[j][n - i - 1]);
			//最后一行和第一列交换
			swap(matrix[n - i - 1][n - j - 1], matrix[n - j - 1][i]);
			//对角交换
			swap(matrix[i][j], matrix[n - i - 1][n - j - 1]);	
		}
	}
};

int main()
{
	vector<vector<int>> matrix = { { 5, 1, 9, 11}, { 2, 4, 8, 10 }, { 13, 3, 6, 7 }, { 15, 14, 12, 16 } };
	//vector<vector<int>> matrix = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	Solution sol;
	sol.rotate(matrix);

	for (auto mat : matrix)
	{
		for (auto m : mat)
			cout << m << " ";
		cout << endl;
	}
	cout << endl;
	return 0;
}