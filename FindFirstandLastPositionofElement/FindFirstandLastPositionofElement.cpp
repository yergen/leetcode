#include<vector>
#include<iostream>

using namespace::std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> res;
		int leftIndex = marginIndex(nums, target, true);
		//�ų�Ŀ��ֵ����������
		if (leftIndex == nums.size() || nums[leftIndex] != target) return{ -1, -1 };
		res.push_back(leftIndex);
		int rightIndex = marginIndex(nums, target, false);
		res.push_back(rightIndex - 1);
		return res;
	}

private:
	int marginIndex(vector<int>& nums, int target, bool isLeft)
	{
		int lo = 0, hi = nums.size();
		while (lo < hi)
		{
			int mid = (lo + hi) / 2;
			//�ҵ��ұ���΢����target����������ߵ���Ŀ��ֵ��С�����
			if (nums[mid] > target || (isLeft && nums[mid] == target))
			{
				hi = mid;
			}
			else
				lo = mid + 1;
		}

		return lo;
	}
};

int main()
{
	vector<int> nums = {1};
	int target = 8;
	Solution sol;
	vector<int> res;
	res = sol.searchRange(nums, target);
	for (auto i : res)
		cout << i << " ";
	cout << endl;
	return 0;
}