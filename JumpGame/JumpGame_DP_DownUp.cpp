#include<vector>
#include<iostream>
#include<algorithm>

using namespace::std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		if (n <= 1) return true;
		vector<int> memo(n - 1, UNKNOWN);
		memo.push_back(GOOD);
		for (int i = n - 2; i >= 0; --i)
		{
			int furthest = min(i + nums[i], int(nums.size() - 1));
			for (int j = i + 1; j <= furthest; ++j)
			{
				if (memo[j] == GOOD)
				{
					memo[i] = GOOD;
					break;
				}
			}
		}
		return memo[0] == GOOD;
	}
private:
	enum index{
		GOOD, BAD, UNKNOWN
	};
};

int main()
{
	vector<int> nums = { 2, 3, 1, 1, 4 };
	Solution sol;
	cout << sol.canJump(nums) << endl;
	return 0;
}