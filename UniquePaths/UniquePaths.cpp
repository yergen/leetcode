#include<iostream>
#include<vector>
#include<string>

using namespace::std;

class Solution {
public:
	//���ݷ� ʱ�䳬��
	int uniquePaths(int m, int n) {
		if (m == 1 || n == 1) return 1;
		//���½ǵ�·��������ߺ�����ĺ͡�������һ�л��һ����Ϊһ��·����
		return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
	}
};

int main()
{
	int m = 3, n = 2;
	Solution sol;
	cout << sol.uniquePaths(m, n) << endl;
	return 0;
}