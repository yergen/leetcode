#include<iostream>
#include<vector>
#include<algorithm>

using namespace::std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		vector<int> nodes;
		ListNode *point =new ListNode(0),*head = point;
		for (auto l : lists)
		{
			while (l)
			{
				nodes.push_back(l->val);
				l = l->next;
			}
		}//将所有链表值放到一个数组内
		sort(nodes.begin(), nodes.end());//排序
		for (auto x : nodes)
		{
			point->next = new ListNode(x);
			point = point->next;
		}//组合成一个链表

		return head->next;
	}
};

int main()
{
	int a[] = { 1, 4, 5 }, b[] = { 1, 3, 4 }, c[] = { 2, 6 };

	ListNode *l1 = new ListNode(0),*l1_head = l1;
	ListNode *l2 = new ListNode(0),*l2_head = l2;
	ListNode *l3 = new ListNode(0),*l3_head = l3;
	for (int i = 0; i < 3; i++)
	{
		l1->next = new ListNode(a[i]);
		l2->next = new ListNode(b[i]);
		if (i < 2)
			l3->next = new ListNode(c[i]);
		l1 = l1->next;
		l2 = l2->next;
		l3 = l3->next;
	}
	vector<ListNode*> list = { l1_head->next, l2_head->next, l3_head->next };
	Solution sol;
	ListNode *r = sol.mergeKLists(list);
	while (r)
	{
		cout << r->val << " ";
		r = r->next;
	}
	cout << endl;

	return 0;
}