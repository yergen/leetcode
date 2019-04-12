#include<iostream>
using namespace::std;

class Solution {
public:
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
	};
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *tempList = new ListNode(0);//新建结点
		tempList->next = head;
		ListNode *first = tempList;
		ListNode *second = tempList;
		//Advances first node so that the gap between first and second is n nodes apart
		for (int i = 0; i <= n; i++)
		{
			first = first->next;
		}
		//Move the first to end,maintain the gap
		while (first != NULL)
		{
			first = first->next;
			second = second->next;
		}
		second->next = second->next->next;
		return tempList->next;
	}
};

int main()
{
	Solution::ListNode Node(1), *L1 = &Node, *L2 = L1;
	Solution sol;
	for (int i = 2; i < 6; i++)
	{
		L1->next = new Solution::ListNode(i);
		L1 = L1->next;
	}
	//while (L2->next != NULL)
	//{
	//	cout << L2->val << " ";
	//	L2 = L2->next;
	//}
	//cout << L2->val << endl;
	L2 = sol.removeNthFromEnd(L2, 2);

	while (L2->next != NULL)
	{
		cout << L2->val << " ";
		L2 = L2->next;
	}
	cout << L2->val << endl;

	return 0;
}