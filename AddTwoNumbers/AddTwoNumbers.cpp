#include"Nodes.h"
#include<malloc.h>

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode Node(0) ,*l3 = &Node;
		int value = 0;
		while (l1 || l2 || value)
		{
			int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + value;
			value = sum / 10;
			l3->next = new ListNode(sum%10);
			l3 = l3->next;
			l1 = l1 ? l1->next : l1;
			l2 = l2 ? l2->next : l2;
		}
		return Node.next;
	}
};