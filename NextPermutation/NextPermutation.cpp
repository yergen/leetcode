#include<vector>
#include<iostream>
#include<algorithm>
using namespace::std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int i = nums.size() - 2;
		while (i >= 0 && nums[i + 1] <= nums[i]) i--;
		if (i >= 0)
		{
			int j = nums.size() - 1;
			//j>=0 -> j>=i
			while (j >= i && nums[j] <= nums[i]) j--;
			swap(nums, i, j);
		}
		//(i+1)括号不能少，否则会出现越界错误。
		sort(nums.begin() + (i + 1), nums.end());
	}
private:
	void swap(vector<int>& nums, int i, int j){
		int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
	}
};

int main()
{
	vector<int> a = { 2,1,1 };
	Solution sol;
	sol.nextPermutation(a);
	for (auto i : a)
	{
		cout << i << ",";
	}
	cout << endl;
	return 0;
}