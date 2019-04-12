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
	ListNode* swapPairs(ListNode* head) {
		ListNode **pp = &head, *first, *second;
		//a->b->c->d->e->f
		while ((first = *pp) && (second = first->next))
		{
			first->next = second->next;//*pp/head->a->c->d->e->f     //b->*pp/a->c->e->f
			second->next = first;	   //b->a->c->d->e->f			//d->c->e->f
			*pp = second;			   //*pp/head->b->a->c->d->e->f  //b->*pp/a->d->c->e->f
			pp = &(first->next);	   //b->*pp/a->c->d->e->f			//b->a->d->*pp/c->e->f
		}
		return head;
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
	point = sol.swapPairs(head->next);

	while (point)
	{
		cout << point->val;
		point = point->next;
	}
	cout << endl;
	return 0;
}