#include<iostream>
#include<string>

using namespace::std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL || head->next == NULL ) return head;

		int n = 1;
		ListNode *tail = head;
		//计算链表的结点数。
		while (tail->next)
		{
			n++;
			tail = tail->next;
		}
		//将链表连接成一个环
		tail->next = head;
		//转换从开始数第k个结点
		k = n - k%n;
		
		//查找新的链表头的上一个结点。
		for (int i = 0; i < k; i++)
		{
			tail = tail->next;
		}
		//重新组织链表
		head = tail->next;
		tail->next = NULL;

		return head;
	}
};

int main()
{
	for (int k = 0; k < 6; k++)
	{
		ListNode *head = new ListNode(0), *node = head;
		for (int i = 1; i < 5; i++)
		{
			node->next = new ListNode(i);
			node = node->next;
		}

		Solution sol;
		ListNode *res = sol.rotateRight(head->next, k);
		ListNode *h = res;
		while (h)
		{
			cout << h->val << "->";
			h = h->next;
		}
		cout << "NULL" << endl;
	}

	return 0;
}