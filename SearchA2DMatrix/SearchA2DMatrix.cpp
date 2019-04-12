#include<iostream>
#include<vector>

using namespace::std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size();
		if (m == 0 || matrix[0].size() == 0) return false;
		int n = matrix[0].size();

		int lo = 0, hi = m*n;
		while (lo < hi)
		{
			int mid = lo + (hi - lo) / 2;
			int row = mid / n;
			int col = mid%n;
			if (matrix[row][col] == target) return true;
			else if (matrix[row][col] > target)
				hi = mid;
			else
				lo = mid + 1;
		}

		return false;
	}
};

int main()
{
	Solution sol;
	vector<vector<int>> matrix = { { 1, 3, 5 } };
	int target = 0;
	cout << sol.searchMatrix(matrix, target) << endl;
	return 0;
}