#include<iostream>
#include<vector>
#include<algorithm>

using namespace::std;
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		if (intervals.empty()) return vector<Interval>{};
		vector<Interval> res;
		//lambda 表达式 [capture list](parameter list) -> return type {function body}
		sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {return a.start < b.start; });
		res.push_back(intervals[0]);
		for (int i = 1; i < intervals.size(); ++i)
		{
			//back() 迭代器最后一个元素
			if (res.back().end < intervals[i].start) res.push_back(intervals[i]);
			else
				res.back().end = max(res.back().end, intervals[i].end);
		}
		return res;
	}
};

int main()
{
	vector<Interval> intervals = { Interval(2, 6), Interval(1, 3), Interval(8, 10), Interval(15, 18) };
	Solution sol;
	vector<Interval> res;
	res = sol.merge(intervals);
	for (auto r : res)
	{
		cout << '{' << r.start << ',' << r.end << '}' << ',';
	}
	cout << endl;
	return 0;
}
