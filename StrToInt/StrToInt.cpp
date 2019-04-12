#include<string>
#include<iostream>

using namespace::std;

class Solution {
public:
	int myAtoi(string str) {
		long res = 0;
		char sign = 1;
		int n = str.size();
		for (int i = 0; i < n;)
		{
			if (isspace(str[i++])) continue;
			if (str[i - 1] == '+')
				sign = 1;
			else if (str[i - 1] == '-')
				sign = -1;
			else
				i--;
			while (str[i] >= '0' && str[i] <= '9')
			{
				res = res * 10 + (str[i++] - '0');
				if (res > INT_MAX && sign == 1) return INT_MAX;
				if (res - 1 > INT_MAX && sign == -1) return INT_MIN;
			}
			return res*sign;
		}
		return 0;
	}
};

int main()
{
	string str = "      -42";
	Solution sol;
	cout << sol.myAtoi(str) << endl;

	return 0;
}