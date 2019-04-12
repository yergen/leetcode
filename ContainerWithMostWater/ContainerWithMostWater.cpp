#include<vector>
#include<iostream>
#include<algorithm>

using namespace::std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int m = 0, n = height.size();
		for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n;++j)
		{
			m = max(min(height[i], height[j])*(j - i),m);
		}
		return m;
	}
};

int main()
{
	vector<int> h{1,8,6,2,5,4,8,3,7};
	Solution sol;
	cout << sol.maxArea(h) << endl;
	return 0;
}