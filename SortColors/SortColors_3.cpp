#include<iostream>
#include<vector>
//#include<algorithm>

using namespace::std;
//two-pass 
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int n = nums.size();
		int j = 0, k = n - 1;
		for (int i = 0; i <= k; ++i)
		{
			//i!=j 也可被省略
			if (nums[i] == 0)
				//i-- 可省略 j一定小于等于i
				swap(nums[i], nums[j++]);
			else if (nums[i] == 2 && i != k)
				//ticks: i--
				swap(nums[i--], nums[k--]);
		}
	}
};

int main()
{
	vector<int> nums = { 0, 0, 0, 0, 0 };
	Solution sol;
	sol.sortColors(nums);
	for (auto n : nums)
		cout << n << " ";
	cout << endl;
	return 0;
}