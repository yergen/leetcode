#include<vector>
#include<string>
#include<iostream>

using namespace::std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {	//brute Force 
		vector<string> res;
		string a(2*n,' ');//ֱ�ӳ�ʼ���ַ���������Ϊ2*n�����ַ���
		generateAll(a, 0, res);
		return res;
	}

	void generateAll(string &current, int pos, vector<string> &result){
		int a = current.size();
		if (pos == current.size())
		{
			if (valid(current))
				result.push_back(current);
		}
		else
		{
			current[pos] = '(';
			generateAll(current, pos + 1, result);
			current[pos] = ')';
			generateAll(current, pos + 1, result);
		}
	}

	bool valid(string current){
		int num = 0;
		for (char c : current)
		{
			if (c == '(') num++;
			else
				num--;
			if (num < 0) return false;
		}
		return (num == 0);
	}
};

int main()
{
	Solution sol;
	int n = 3;
	vector<string> r = sol.generateParenthesis(n);
	for (string s : r){
		cout << s << endl;
	}

	return 0;
}