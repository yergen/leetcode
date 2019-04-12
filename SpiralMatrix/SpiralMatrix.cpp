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
		int i = 0, j = 0, count = 0, flag = 0;
		while (res.size() < m*n)
		{
			while (j < n - count && res.size() < m*n)
				res.push_back(matrix[i][j++]);
			i++;
			j--;
			while (i < m - count && res.size() < m*n)
				res.push_back(matrix[i++][j]);
			i--;
			j--;
			while (j >= count && res.size() < m*n)
				res.push_back(matrix[i][j--]);
			i--;
			j++;
			while (i>count && res.size() < m*n)
				res.push_back(matrix[i--][j]);
			i++;
			j++;

			count++;
		
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
	res = sol.spiralOrder(matrix2);
	for (auto i : res)
		cout << i << " ";
	cout << endl;

	return 0;
}