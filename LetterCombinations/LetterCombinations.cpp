#include<iostream>
#include<vector>
#include<string>

using namespace::std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		if (digits.empty()) return {};
		vector<string> result;
		const vector<string> DataSet = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		result.push_back("");//迭代的第一步初始化数据为空
		for (int i = 0; i < digits.size(); ++i)
		{
			if (digits[i]<'2' || digits[i]>'9') continue;
			vector<string> temp_res;
			string temp = DataSet[digits[i] - '2'];
			for (int j = 0; j < result.size();j++)
			for (int k = 0; k < temp.size(); k++)
				temp_res.push_back(result[j] + temp[k]);
			result = temp_res;
		}
		return result;
	}
};

int main()
{
	string digits = "11";
	Solution sol;
	vector<string> res = sol.letterCombinations(digits);
	for (auto r = res.cbegin(); r != res.cend();++r)
		cout << *r << endl;

	return 0;
}