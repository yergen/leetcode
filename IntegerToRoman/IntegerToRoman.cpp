#include<iostream>
#include<vector>
#include<string> //û����仰 cout << string �����

using namespace::std;

class Solution {
public:
	string intToRoman(int num) {
		vector<vector<string>> table ={
			{ "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" },
			{ "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" },
			{ "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" },
			{ "", "M", "MM", "MMM" } };

		return table[3][num / 1000] + table[2][num / 100 % 10] + table[1][num / 10 % 10] + table[0][num % 10];
	}
};

int main()
{
	int n = 1994;
	Solution sol;

	cout << sol.intToRoman(n) << endl;

	return 0;
}