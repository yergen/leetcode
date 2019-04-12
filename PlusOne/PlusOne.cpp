#include<iostream>
#include<vector>

using namespace::std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int n = digits.size();
		if (n == 0) return vector<int>({1});
		int carry = 1;//ticks
		for (int i = n - 1; i >= 0;i--)
		{
			int num = digits[i] + carry;
			digits[i] = num % 10;
			carry = num / 10;
			if (carry == 0)
				return digits;
		}
		digits.insert(digits.begin(), 1);
		return digits;
	}
};

int main()
{
	vector<int> digits = {9,9,9,9};
	Solution sol;
	vector<int> dig = sol.plusOne(digits);

	for (auto num : dig)
	{
		cout << num << " ";
	}
	cout << endl;
	return 0;
}