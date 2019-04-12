#include<string>
#include<iostream>

using namespace::std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode l3_head = ListNode(0);
		ListNode *l3_temp = &l3_head;

		while (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				l3_temp->next = l1;
				l1 = l1->next;
			}
			else
			{
				l3_temp->next = l2;
				l2 = l2->next;
			}
			l3_temp = l3_temp->next;
		}
		l3_temp->next = l1 == NULL ? l2 : l1;

		return l3_head.next;
	}
};

int main()
{
	int a[3] = { 1, 2, 4 };
	int b[3] = { 1, 3, 4 };
	ListNode *l1 = new ListNode(0), *l2 = new ListNode(0);
	ListNode *temp_l1 = l1, *temp_l2 = l2;
	for (int i = 0; i < 3; i++)
	{
		ListNode *temp_node1 = new ListNode(a[i]);
		ListNode *temp_node2 = new ListNode(b[i]);
		temp_l1->next = temp_node1;
		temp_l2->next = temp_node2;
		temp_l1 = temp_l1->next;
		temp_l2 = temp_l2->next;
	}
	Solution sol;
	temp_l1 = sol.mergeTwoLists(l1->next, l2->next);
	while (temp_l1 != NULL)
	{
		cout << temp_l1->val << " ";
		temp_l1 = temp_l1->next;
	}
	cout << endl;

	return 0;
}