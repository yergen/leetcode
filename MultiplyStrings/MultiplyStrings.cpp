#include<string>
#include<iostream>

using namespace::std;

class Solution {
public:
	string multiply(string num1, string num2) {
		string sum(num1.size() + num2.size(), '0');
		//begin from the lowest bit.
		for (int i = num1.size() - 1; 0 <= i; --i) {
			int carry = 0;
			for (int j = num2.size() - 1; 0 <= j; --j) {
				int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
				sum[i + j + 1] = tmp % 10 + '0';
				carry = tmp / 10;
			}
			//better comprehensive
			sum[i] = carry + '0';
		}

		size_t startpos = sum.find_first_not_of("0");
		//static const size_t npos = -1 
		if (string::npos != startpos) {
			return sum.substr(startpos);
		}

		return "0";
	}
};

int main()
{
	string num1 = "123", num2 = "456";
	Solution sol;
	cout << sol.multiply(num1, num2) << endl;
	return 0;
}