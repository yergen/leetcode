#include<vector>
#include<iostream>
#include<algorithm>

using namespace::std;
class Solution {
public:
	int maxArea(vector<int>& height) {
		int i = 0, j = height.size()-1,m = 0;
		while (j > i)
		{
			m = max(min(height[i], height[j])*(j - i), m);
			height[i] < height[j] ? i++ : j--;
		}
		return m;
	}
};

int main()
{
	vector<int> h{ 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	Solution sol;
	cout << sol.maxArea(h) << endl;
	return 0;
}