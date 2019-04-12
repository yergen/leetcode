#include<iostream>
#include<vector>
//#include<algorithm>

using namespace::std;
//one-pass ‘≠÷∑≤Â»Î≈≈–Ú
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int i = 0, j = 0;
		for (int k = 0; k < nums.size(); ++k)
		{
			int num = nums[k];
			nums.erase(nums.begin() + k);
			if (num == 0)
			{
				nums.insert(nums.begin() + i, num);
				i++;
				j++;
			}
			else if (num == 1)
			{
				nums.insert(nums.begin() + i, num);
				j++;
			}
			else if (num == 2)
			{
				nums.insert(nums.begin() + j, num);
			}
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