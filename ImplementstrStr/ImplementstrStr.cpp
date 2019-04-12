#include<string>
#include<iostream>

using namespace::std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty()) return 0;
		int i = 0, L = haystack.size() - needle.size();
		while (i <= L)
		{
			if (haystack[i] == needle[0])
			{
				int j, k = i + 1;
				for (j = 1; j < needle.size(); j++)
				{
					if (haystack[k++] != needle[j])
						break;
				}
				if (j == needle.size())
					return i;
				else
					i++;
			}
			else
				i++;
		}

		return -1;
	}
};

int main()
{
	string a = "a",b = "a";
	Solution sol;
	cout << sol.strStr(a, b) << endl;
	return 0;
}