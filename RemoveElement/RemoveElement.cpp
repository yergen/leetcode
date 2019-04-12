#include<iostream>
#include<vector>

using namespace::std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int i = 0;
		for (int j = 0; j < nums.size(); j++)
		{
			if (nums[j] != val)
			{
				nums[i] = nums[j];
				i++;
			}
		}
		return i;
	}
};

int main()
{
	vector<int> a = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
	int b;
	Solution sol;
	b = sol.removeElement(a,2);
	for (int i = 0; i < b; i++)
	{
		cout << a[i] << "";
	}
	cout << endl;

	return 0;
}