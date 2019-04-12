#include<iostream>

using namespace::std;

struct ListNode {     
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (LengthOfListNode(head) < k) return head;

		ListNode *cur = head;
		ListNode *prev = NULL, *next = NULL;
		for (int i = 0; i < k; i++)
		{
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}//��תǰk����
		//�ݹ鷭ת��k���㣬
		//ǰk�ת�Ľ������һ��������һ�����ָ���k���ź���ĵ�һ����㡣
		head->next = reverseKGroup(cur, k);

		return prev;
	}
	
	int LengthOfListNode(ListNode* head)
	{
		int n = 0;
		while (head)
		{
			n++;
			head = head->next;
		}
		return n;
	}
};

int main()
{
	int a[4] = { 1, 2, 3, 4 };
	ListNode *head = new ListNode(0), *point = head;
	for (int i = 0; i < 4; i++)
	{
		point->next = new ListNode(a[i]);
		point = point->next;
	}
	Solution sol;
	int k = 3;
	point = sol.reverseKGroup(head->next,k);

	while (point)
	{
		cout << point->val;
		point = point->next;
	}
	cout << endl;
	return 0;
}