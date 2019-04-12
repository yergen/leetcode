#include<string>
#include<iostream>

using namespace::std;

class Solution {
public:
	string addBinary(string a, string b) {
		if (a.empty() || b.empty())
			return a.empty() ? b : a;
		int m = a.size(), n = b.size(), carry = 0;
		string c;
		for (int i = m - 1, j = n - 1; i >= 0 || j >= 0; --i, --j)
		{
			int a_num = i >= 0 ? (a[i]-'0') : 0;
			int b_num = j >= 0 ? (b[j]-'0') : 0;
			int num = a_num + b_num + carry;
			carry = num / 2;

			c.insert(c.begin(), num % 2 + '0');
		}
		if (carry) c.insert(c.begin(), '1');

		return c;
	}
};

int main()
{
	string a = "1010", b = "1011";
	Solution sol;

	cout << sol.addBinary(a, b) << endl;

	return 0;
}