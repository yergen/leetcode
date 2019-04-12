#include<iostream>
#include<vector>
#include<string>

using namespace::std;

class Solution {
public:
	//数学公式：Combiantion(m+n-2,m-1) = Combiantion(m+n-2,n-1)
	//= (m+n-2)!/((m-1)!*(n-1)!) = ((m+n-2)*(m+n-3)*...(n))/((m-1)*(m-2)*...*1)
	//= m+n-2/m-1 * (m+n-3)/m-2 *...n。
	int uniquePaths(int m, int n) {
		double res = 1;
		for (int i = 1; i < m; ++i)
			res = res*(n + i-1) / i;
		return (int)res;
	}
};

int main()
{
	int m = 3, n = 2;
	Solution sol;
	cout << sol.uniquePaths(m, n) << endl;
	return 0;
}