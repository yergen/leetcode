#include<iostream>
#include<string>
#include<vector>

using namespace::std;

class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> res;
		int length = 0, count = 0,n = words.size();
		string s;
		for (int i = 0; i < n-1; ++i)
		{
			length += words[i].size();
			count++;
			if (length + words[i+1].size()+count > maxWidth)
			{
				int space_num = maxWidth - length;
				if (count > 1)
				{
					int space_ave = space_num / (count - 1);
					int space_rem = space_num % (count - 1);
					for (int j = count-1; j > 0; --j)
					{
						s += words[i - j];
						//int rem = space_rem-- > 0 ? 1 : 0;
						s += string(space_ave + (space_rem-- > 0), ' ');
					}
				}
				s += words[i];
				//一个单词
				if (count == 1)
					s += string(space_num, ' ');
				res.push_back(s);
				//重新初始化处理下一组单词。
				s.clear();
				length = 0;
				count = 0;
			}
		}
		//最后一行的单词加空格正好够一行
		if (length + words[n-1].size() + count == maxWidth)
		{
			while (count)
				s += words[n - 1 - count--] + ' ';
			s += words[n - 1];
		}
		else
		{
			while (count + 1)
				s += words[n - 1 - count--] + ' ';
			s += string(maxWidth - s.size(), ' ');
		}

		res.push_back(s);
		return res;

	}

};

int main()
{
	//vector<string> words = { "This", "is", "an", "example", "of", "text", "justification." };
	vector<string> words = { "What", "must", "be", "acknowledgment", "shall", "be" };
	//vector<string> words = { "Science", "is", "what", "we", "understand", "well", "enough", "to", "explain",\
		"to", "a", "computer.", "Art", "is", "everything", "else", "we" ,"do"};
	int maxWidth = 20;
	Solution sol;
	vector<string> res = sol.fullJustify(words,maxWidth);
	for (auto r : res)
		cout << r << ',' << endl;
	return 0;
}