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
		tempList -> next =head;
		int ListNums = 0;
		ListNode *first = head;//指向ListNode结点的指针
		while (first != NULL)
		{
			ListNums++;
			first = first->next;
		}
		ListNums -= n;
		first = tempList;
		while (ListNums > 0)
		{
			ListNums--;
			first = first->next;
		}
		first->next = first->next->next;

		return tempList->next;
	}
};

int main()
{
	Solution::ListNode Node(1), *L1 = &Node, *L2=L1;
	Solution sol;
	for (int i = 2; i < 6;i++)
	{
		L1->next=new Solution::ListNode(i);
		L1 = L1->next;
	}
	//while (L2->next != NULL)
	//{
	//	cout << L2->val << " ";
	//	L2 = L2->next;
	//}
	//cout << L2->val << endl;
	L2 = sol.removeNthFromEnd(L2,2);

	while (L2->next != NULL)
	{
		cout << L2->val << " ";
		L2 = L2->next;
	}
	cout << L2->val << endl;

	return 0;
}