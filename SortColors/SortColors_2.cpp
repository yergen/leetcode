#include<iostream>
#include<vector>
//#include<algorithm>

using namespace::std;
//two-pass 
class Solution {
public:
	void sortColors(vector<int>& nums) {
		vector<int> color(3, 0);
		for (auto num : nums)
			color[num]++;
		int i = 0;
		while (color[0]-- != 0) nums[i++] = 0;
		while (color[1]-- != 0) nums[i++] = 1;
		while (color[2]-- != 0) nums[i++] = 2;

	}
};

int main()
{
	vector<int> nums = { 0, 2, 1, 2, 0 };
	Solution sol;
	sol.sortColors(nums);
	for (auto n : nums)
		cout << n << " ";
	cout << endl;
	return 0;
}