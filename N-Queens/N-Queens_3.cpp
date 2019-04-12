#include<iostream>
#include<vector>
#include<string>

using namespace::std;

class Solution {
private:
	vector<vector<string> > res;
	int upperlim;
public:
	vector<vector<string> > solveNQueens(int n) {
		upperlim = (1 << n) - 1;//��nλȫ����1
		vector<string> cur(n, string(n, '.'));
		helper(0, 0, 0, cur, 0);
		return res;
	}

	void helper(const int row, const int ld, const int rd, vector<string>&cur, const int index)
	{
		int pos, p;
		if (row != upperlim)
		{
			pos = upperlim & (~(row | ld | rd));//pos�ж�����Ϊ1��λ����ʾ�����ڵ�ǰ�еĶ�Ӧ�зŻʺ�
			//��upperlim�����㣬��Ҫ��ld����һ����ͨ������λ�õ��ģ����ĸ�λ��������Ч��1���ڣ����������ld��λ��Ч��1
			while (pos)
			{
				p = pos & (~pos + 1);//��ȡpos���ұߵ�1,����pos = 010110����p = 000010
				pos = pos - p;//pos���ұߵ�1��0
				setQueen(cur, index, p, 'Q');//�ڵ�ǰ�У�p��1��Ӧ���з��ûʺ�
				helper(row | p, (ld | p) << 1, (rd | p) >> 1, cur, index + 1);//������һ��
				setQueen(cur, index, p, '.');
			}
		}
		else//�ҵ�һ����
			res.push_back(cur);
	}

	//��row�У���loc1(p)�е�λ�÷���һ��queen�������queen��loc1(p)��ʾp�ж�����1��λ��
	void setQueen(vector<string>&cur, const int row, int p, char val)
	{
		int col = 0;
		while (!(p & 1))
		{
			p >>= 1;
			col++;
		}
		cur[row][col] = val;
	}
};

int main()
{
	Solution sol;
	int sum = 0;
	vector<vector<string>> res;
	res = sol.solveNQueens(8);
	for (auto Vstring : res)
	{
		for (auto str : Vstring)
		{
			cout << str << endl;
		}
		cout << endl;
		sum++;
		if (sum == 1)
			break;
	}
	cout << "sum : " << sum << endl;

	return 0;
}