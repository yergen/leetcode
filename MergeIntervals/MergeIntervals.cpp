#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>

using namespace::std;
//brute force 这种思路编译出错网上没有找到解决办法。
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
	/*bool operator < (Interval const &a)
	{
		if (start < a.start) return true;
		if (start == a.start) return end < a.end;
		return false;
	}*/
};

class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		buildGrap(intervals);
		buildCompents(intervals);

		vector<Interval> merge;
		for (int comp = 0; comp < nodesInComp.size(); comp++)
		{
			merge.push_back(mergeNodes(nodesInComp[comp]));
		}

		return merge;
	}
private:
	//判断两个线段是否有重叠
	bool overlap(Interval a, Interval b)
	{
		return a.start <= b.end && b.start <= a.end;
	}
	//如果u和v存在且重叠，则在u和v之间构建一个无向图。
	void buildGrap(vector<Interval> intervals)
	{
		for (auto inter : intervals)
			graph[inter];
		for (auto inter1:intervals)
		for (auto inter2 : intervals)
		{
			if (overlap(inter1, inter2))
			{
				graph[inter1].push_back(inter2);
				graph[inter2].push_back(inter1);
			}
		}
	}
	//合并图的所有区间段到一个区间段	
	Interval mergeNodes(vector<Interval> nodes)
	{
		int minStart = nodes[0].start;
		int maxEnd = nodes[0].end;
		for (auto node : nodes)
		{
			minStart = min(node.start, minStart);
			maxEnd = max(node.end, maxEnd);
		}

		return Interval(minStart, maxEnd);
	}
	//用深度优先搜索标记连接组件的所有结点。
	void markComponentDFS(Interval start, int compNumber)
	{
		stack<Interval> stk;
		stk.push(start);

		while (!stk.empty())
		{
			Interval node = stk.top();
			stk.pop();

			if (visited.find(start) == visited.end())
			{
				visited.insert(start);
				if (nodesInComp.find(compNumber) == nodesInComp.end())
				{
					nodesInComp[compNumber];
				}
				nodesInComp[compNumber].push_back(start);

				for (auto child : graph[start])
					stk.push(child);
			}
		}
	}

	void buildCompents(vector<Interval> intervals)
	{
		int compNumber = 0;

		for (auto interval : intervals)
		{
			if (visited.find(interval) != visited.end())
			{
				markComponentDFS(interval, compNumber);
				compNumber++;
			}
		}
	}

private:
	unordered_map<Interval, vector<Interval>> graph;
	unordered_map<size_t, vector<Interval>> nodesInComp;
	unordered_set<Interval> visited;
};

int main()
{
	vector<Interval> intervals = {Interval(1,3),Interval(2,6),Interval(8,10),Interval(15,18)};
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
