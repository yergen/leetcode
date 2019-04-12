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
		ListNode node = ListNode(0),*head = &node;
		ListNode *temp_node = new ListNode(0);
		vector<ListNode*> list_head = lists;
		int node_sum=0,n= lists.size();
		for (int i = 0; i < lists.size(); i++)
		{
			while (lists[i])
			{
				node_sum++;
				lists[i] = lists[i]->next;
			}
		}//计算总共的结点数
		for (int j = 0;j < node_sum;j++)
		{
			int min = INT_MAX;
			for (int i = 0; i < n; i++)
			{
				if (list_head[i] && list_head[i]->val < min)
				{
					min = list_head[i]->val;
					temp_node->next = list_head[i];
				}
			}//找出最小的结点
			for (int i = 0; i < n; i++)
			{
				if (list_head[i] && list_head[i] == temp_node->next)
					list_head[i] = list_head[i]->next;
			}//重新初始化各个链表头

			head->next = temp_node->next;
			head = head->next;//延长输出结点
		}

		return node.next;
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