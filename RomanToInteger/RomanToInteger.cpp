#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace::std;

class Solution {
public:
	int romanToInt(string s) {
		int n = s.size(), result = 0; 

		unordered_map<char, int> map = { { 'I', 1 }, { 'V', 5 }, { 'X', 10 }, { 'L', 50 }, { 'C', 100 }, { 'D', 500 }, { 'M', 1000 } };
		unordered_map<string, int> a = { {"IV", 0}, { "IX",0 }, {"XL", 0}, {"XC",0 }, {"CD",0 }, { "CM",0 } };//哈希表的值是无效的不知道能否简化
		for (int i = 0; i < n-1;i++)
			a.find(s.substr(i, 2)) == a.end() ? result += map[s[i]] : result -= map[s[i]];
		return result+map[s[n-1]];
	}
};

int main()
{
	string str = "MCMXCIV";
	Solution sol;
	cout << sol.romanToInt(str) << endl;
	return 0;
}