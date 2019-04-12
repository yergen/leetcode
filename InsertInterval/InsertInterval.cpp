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
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
			//重载小于运算符 不太好理解
			auto compare = [](const Interval &intv1, const Interval &intv2){ return intv1.end < intv2.start; };
			//equal_range:
			auto range = equal_range(intervals.begin(), intervals.end(), newInterval, compare);
			auto itr1 = range.first, itr2 = range.second;
			if (itr1 == itr2) {
				intervals.insert(itr1, newInterval);
			}
			else {
				itr2--;
				itr2->start = min(newInterval.start, itr1->start);
				itr2->end = max(newInterval.end, itr2->end);
				intervals.erase(itr1, itr2);
			}
			return intervals;
		}
};

int main()
{
	vector<Interval> intervals = { Interval(1, 4), Interval(3, 5), Interval(6, 7), Interval(8, 10),Interval(12,16)};
	
	Solution sol;
	vector<Interval> res;
	res = sol.insert(intervals, Interval(4, 8));
	for (auto r : res)
	{
		cout << '{' << r.start << ',' << r.end << '}' << ',';
	}
	cout << endl;
	return 0;
}
