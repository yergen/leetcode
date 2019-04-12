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
	ListNode* swapPairs(ListNode* head) {//µÝ¹éµÄË¼Ïë
		if (head == NULL) return NULL;
		if (head->next == NULL) return head;

		ListNode *temp = head->next;
		head->next = swapPairs(temp->next);
		temp->next = head;

		return temp;
	}
};

int main()
{
	int a[4] = {1,2,3,4};
	ListNode *head = new ListNode(0), *point = head;
	for (int i = 0; i < 4; i++)
	{
		point->next = new ListNode(a[i]);
		point = point->next;
	}
	Solution sol;
	point = sol.swapPairs(head->next);

	while (point)
	{
		cout << point->val;
		point = point->next;
	}
	cout << endl;
	return 0;
}