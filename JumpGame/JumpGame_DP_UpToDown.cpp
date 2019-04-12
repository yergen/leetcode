#include<vector>
#include<iostream>
#include<algorithm>

using namespace::std;

//
class Solution {
public:
	bool canJump(vector<int>& nums) {
		if (nums.size() <= 1) return true;
		vector<int> memo(nums.size() - 1, UNKNOWN);
		memo.push_back(GOOD);
		return canJumpFromPosition(0, nums,memo); 
	}
private:
	bool canJumpFromPosition(int position, vector<int>& nums,vector<int>& memo)
	{
		if (memo[position] != UNKNOWN) 
			return memo[position] == GOOD ? true : false;

		int furthestJump = min(position + nums[position], int(nums.size() - 1));
		for (int nextPosition = position + 1; nextPosition <= furthestJump; nextPosition++)
		{
			if (canJumpFromPosition(nextPosition, nums, memo))
			{
				memo[position] = GOOD;
				return true;
			}
		}
		memo[position] = BAD;
		return false;
	}
private:
	enum index{
		GOOD,BAD,UNKNOWN
	};
};

int main()
{
	vector<int> nums = { 2, 3, 1, 1, 4 };
	Solution sol;
	cout << sol.canJump(nums) << endl;
	return 0;
}