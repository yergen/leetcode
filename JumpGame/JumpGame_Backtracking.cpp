#include<vector>
#include<iostream>
#include<algorithm>

using namespace::std;

//leetcode:Runtime error
class Solution {
public:
	bool canJump(vector<int>& nums) {
		if (nums.size() <= 1) return true;
		canJumpFromPosition(0, nums);
	}
private:
	bool canJumpFromPosition(int position, vector<int>& nums)
	{
		if (position == nums.size() - 1) return true;

		int furthestJump = min(unsigned int(position + nums[position]), nums.size()-1);
		//old
		//for (int nextPosition = position + 1; nextPosition <= furthestJump; ++nextPosition)
		//new
		for (int nextPosition = furthestJump; nextPosition > position; --nextPosition)
		{
			if (canJumpFromPosition(nextPosition, nums)) return true;
		}

		return false;
	}
};

int main()
{
	vector<int> nums = {2,3,1,1,4 };
	Solution sol;
	cout << sol.canJump(nums) << endl;
	return 0;
}