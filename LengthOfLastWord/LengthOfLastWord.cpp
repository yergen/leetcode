#include<iostream>
#include<string>

using namespace::std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		int length = 0, i = s.size() - 1;

		for (; i >= 0 && s[i] == ' '; i--);
		for (; i >= 0 && s[i] != ' '; i--)
			length++;

		return length;
	}
};

int main()
{
	string s = "a bdadf ";
	Solution sol;

	cout << sol.lengthOfLastWord(s) << endl;
	return 0;
}