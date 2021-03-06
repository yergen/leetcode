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
		int n = lists.size(), count = 1;
		if (n == 0) return NULL;//example: [] 
		while (count < n)
		{
			for (int i = 0; i+count < n; i += count*2)
				lists[i] = merge2Lists(lists[i], lists[i + count]);
			count *= 2;
		}

		return lists[0];
	}

	ListNode* merge2Lists(ListNode* l1, ListNode* l2)
	{
		ListNode *head = new ListNode(0), *point = head;
		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;

		while (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				point->next = l1;
				l1 = l1->next;
			}
			else
			{
				point->next = l2;
				l2 = l2->next;
			}
			point = point->next;
		}
		point->next = l1 == NULL ? l2 : l1;
		
		return head->next;
	}
};

int main()
{
	int a[] = { 1, 4, 5 }, b[] = { 1, 3, 4 }, c[] = { 2, 6 };

	ListNode *l1 = new ListNode(0), *l1_head = l1;
	ListNode *l2 = new ListNode(0), *l2_head = l2;
	ListNode *l3 = new ListNode(0), *l3_head = l3;
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
	//vector<ListNode*> list = { l1_head->next, l2_head->next, l3_head->next };
	vector<ListNode*> list = {};
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