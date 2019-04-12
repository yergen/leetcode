#include<iostream>
#include<vector>

using namespace::std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int i = 0,n=nums.size();
		while (i < n)
		{
			if (nums[i] == val)
			{
				nums[i] = nums[n - 1];
				// reduce array size by one
				n--;
			}
			else
				i++;
		}

		return n;
	}
};

int main()
{
	vector<int> a = {1,2,1,2,2};
	int b;
	Solution sol;
	b = sol.removeElement(a, 2);
	for (int i = 0; i < b; i++)
	{
		cout << a[i] << "";
	}
	cout << endl;

	return 0;
}