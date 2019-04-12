#include<iostream>
#include<vector>

using namespace::std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int lo = 0, hi = nums.size() - 1;
		while (lo <= hi)//=�ű���� �ų�[target] target 
		{
			int mid = (lo + hi) / 2;
			//�ж���λ����Ŀ��ֵ�Ƿ���ͬһ��(�����ͬһ��)��
			if (!((nums[mid] >= nums[0]) ^ (target >= nums[0])))
			{
				if (nums[mid] == target) return mid;
				if (nums[mid] > target) hi = mid - 1;//-1 �ų�[1,3] 2
				else lo = mid + 1;
			}
			else
			{
				//Ŀ�����ұ�
				if (nums[mid] > target) lo = mid + 1;
				//Ŀ�������
				else hi = mid - 1;//-1 �ų�[1,2,0] 3
			}
		}
		return  -1;
	}
};

int main()
{
	vector<int> nums = {1,2,3};
	Solution sol;
	cout << sol.search(nums, 2) << endl;

	return 0;
}