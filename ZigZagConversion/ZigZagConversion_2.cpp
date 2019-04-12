//row 0				index: k*(2*numRows - 2)
//row i				index: k*(2*numRows - 2) + i and (k+1)(2*numRows - 2) -i
//row numRows - 1   index: k*(2*numRows - 2) + numRows-1 
#include<string>
#include<iostream>

using namespace::std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1)  return s;

		int n = s.size();
		int cyclelen = 2 * numRows - 2;
		string result;
		            
		for (int i = 0; i < numRows; ++i)
		for (int j = 0; j + i < n; j += cyclelen)
		{
			result += s[j + i];
			if (i != 0 && i != numRows - 1 &&j+cyclelen-i < n )
				result += s[j+cyclelen-i];
		}

		return result;
	}
};

int main()
{
	string s = "PAYPALISHIRING";
	int numRows = 3;
	Solution sol;
	cout << sol.convert(s, numRows) << endl;
	return 0;
}