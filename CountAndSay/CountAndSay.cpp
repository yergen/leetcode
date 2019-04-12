#include<iostream>
#include<string>
#include<algorithm>

using namespace::std;

class Solution {
public:
	string countAndSay(int n) {
		if (n <= 1) return "1";

		string res_temp = countAndSay(n-1);

		string res;
		char count = '1';
		for (int i = 1; i < res_temp.size(); ++i)
		{
			if (res_temp[i] == res_temp[i-1])
				count++;
			else
			{
				res.push_back(count);
				res.push_back(res_temp[i - 1]);
				count = '1';
			}
		}
		res.push_back(count);
		res.push_back(res_temp[res_temp.size() - 1]);

		return res;
	}
};

int main()
{
	int num = 5;
	Solution sol;

	cout << sol.countAndSay(5) << endl;

	return 0;
}