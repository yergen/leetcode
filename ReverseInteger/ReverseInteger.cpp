#include<iostream>

using namespace::std;

class Solution {
public:
	int reverse(int x) {
		int res = 0;
		while (x!=0)
		{
			int pop = x % 10;
			x = x / 10;
			//(res == INT_MAX/10 && pop > 7) ���������ʵ�ǲ����ڵ�
			if (res > INT_MAX / 10 || (res == INT_MAX/10 && pop > 7)) return 0;
			if (res < INT_MIN / 10 || (res == INT_MAX/10 && pop < -8)) return 0;
			//(last_res -pop)/10 = last_res/10 -pop/10 = last_res/10 != res Ҳ�����ж��Ƿ����
			res = res * 10 + pop;
		}
		return res;
	}
};

int main()
{
	int num=0;
	Solution sol;
	sol.reverse(num);

	return 0;
}