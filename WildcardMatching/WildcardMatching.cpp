#include<iostream>p_pos
#include<string>

using namespace::std;

class Solution {
public:
	bool isMatch(string s, string p) {
		int sPos = 0, pPos = 0, pStar = -1, sStar = 0;
		int pLenght = p.length();
		while (sPos < s.length())
		{

			if (pPos < pLenght && (s[sPos] == p[pPos] || p[pPos] == '?')) {
				sPos++; pPos++; 
			}
			else if (pPos < pLenght && p[pPos] == '*'){
				pStar = pPos++; sStar = sPos;
			}
			else if (pStar != -1) { 
				pPos = pStar+1; sPos = ++sStar;
			}
			else 
				return  false;
		}

		while (p[pPos] == '*' && pPos < pLenght){ pPos++;}

		return pPos == pLenght;
	}
};

int main()
{
	string s = "acdcb", p = "a*c?b";

	Solution sol;
	cout << sol.isMatch(s,p) << endl;
	return 0;
}