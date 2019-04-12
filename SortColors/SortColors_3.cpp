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
			//i!=j Ҳ�ɱ�ʡ��
			if (nums[i] == 0)
				//i-- ��ʡ�� jһ��С�ڵ���i
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