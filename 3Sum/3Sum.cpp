#include<vector>
#include<iostream>
#include<unordered_set>
#include<algorithm>

using namespace::std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		int n = nums.size();
		if (n < 3) return {};

		vector<vector<int>> ret;
		sort(nums.begin(), nums.end());

		for (int i = 0; i < n;i++)
		{
			if ( i > 0 &&nums[i] == nums[i - 1])
				continue;
			int start = i + 1, end = n - 1;
			while (start < end)
			{
				if (nums[i] + nums[start] + nums[end] == 0)
				{
					ret.push_back({ nums[i], nums[start], nums[end] });
					start++;
					end--;
					while ((start < end) && (nums[start] == nums[start-1])) start++;
					while ((start < end) && (nums[end] == nums[end+1])) end--;
				}
				else if (nums[i] + nums[start] + nums[end] < 0)
				{ 
					start++;
				}
				else
				{
					end--;
				}
			}
		}
		return ret;
	}
};

int main()
{
	vector<int> t = { -1, 0, 1, 2, -1, -4 };
	Solution sol;
	vector<vector<int>> m;
	m = sol.threeSum(t);
	for (int i = 0; i < m.size(); ++i)
	{
		int n = m[i].size();
		for (int j = 0; j < n; ++j)
			cout << m[i][j] << " ";
		cout << endl;
	}

	return 0;
}