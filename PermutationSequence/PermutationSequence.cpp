#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace::std;

class Solution {
public:
	string getPermutation(int n, int k) {
		string str,res;
		int a,b=k-1;
		vector<int> fac;

		fac.push_back(1);
		for (int i = 0; i < n; i++)
		{
			str.push_back(i + '1');
			fac.push_back((i+1)*fac[i]);
		}

		for (int i = n-1; i >=0; i--)
		{
			a = b / fac[i];
			b %= fac[i];
			res.push_back(str[a]);
			str.erase(str.begin() + a);
		}

		return res;
	}
};

int main()
{
	Solution sol;
	int n = 4, k;
	for (k = 1; k <= 24;k++)
		cout << sol.getPermutation(n,k) << endl;

	return 0;
}