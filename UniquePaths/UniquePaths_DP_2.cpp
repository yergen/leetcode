#include<iostream>
#include<vector>
#include<string>

using namespace::std;

class Solution {
public:
	//��̬�滮
	int uniquePaths(int m, int n) {
		//��һ��·����ȫΪ1
		vector<int> table(n, 1);
		//���θ���ÿһ�е�·����
		for (int i = 1; i < m;++i)
		for (int j = 1; j < n; ++j)
			//table[j-1]��ߵ�·������table[j] �ϱߵ�·������
			table[j] += table[j - 1];
		//�������һ�����һ�е�·������
		return table[n - 1];
	}
};

int main()
{
	int m = 3, n = 2;
	Solution sol;
	cout << sol.uniquePaths(m, n) << endl;
	return 0;
}