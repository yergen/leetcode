#include<iostream>
#include<vector>

using namespace::std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int n = nums.size();
		if (n == 0) return 0;
		int i = 0;
		for (int j = 1; j < n;j++)
		{
			if (nums[i] != nums[j])
			{
				i++;
				nums[i] = nums[j];
			}
		}

		return i+1;
	}
};

int main()
{
	vector<int> a = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
	int b;
	Solution sol;
	b = sol.removeDuplicates(a);
	for (int i = 0; i < b; i++)
	{
		cout << a[i] << "";
	}
	cout << endl;

	return 0;
}