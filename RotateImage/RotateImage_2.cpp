#include<iostream>
#include<vector>
#include<algorithm>

using namespace::std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		reverse(matrix.begin(), matrix.end());
		for (int i = 0; i < matrix.size();++i)
		for (int j = i + 1; j < matrix[i].size(); ++j)
			swap(matrix[i][j], matrix[j][i]);
	}
};

int main()
{
	//vector<vector<int>> matrix = { { 5, 1, 9, 11 }, { 2, 4, 8, 10 }, { 13, 3, 6, 7 }, { 15, 14, 12, 16 } };
	vector<vector<int>> matrix = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
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