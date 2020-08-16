#include "iostream"
#include "vector"
#include <algorithm>
#include <string>
#include <map>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	/*ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *head = new ListNode(0);
		ListNode *root = head;
		while (l1 && l2)
		{
			if (l1->val >= l2->val) {
				head->next = l2;
				l2 = l2->next;
				head = head->next;
			}
			else
			{
				head->next = l1;
				l1 = l1->next;
				head = head->next;
			}
		}

		while (l1) {
			head->next = l1;
			break;
		}

		while (l2) {
			head->next = l2;
			break;
		}

		return root->next;
	}*/

	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *head = new ListNode(0);
		ListNode *root = head;
		while (l1&&l2) {
			if (l1->val <= l2->val) {
				head->next = l1;
				l1 = l1->next;
				head = head->next;
			}
			else {
				head->next = l2;
				l2 = l2->next;
				head = head->next;
			}
		}
		while (l1) {
			head->next = l1;
			break;;
		}
		while (l2) {
			head->next = l2;
			break;;
		}
		return root->next;
	}
};

int main() {
	Solution *solution = new Solution();

	ListNode *a = new ListNode(1);
	ListNode *b = new ListNode(2);
	ListNode *c = new ListNode(3);
	ListNode *d = new ListNode(4);
	ListNode *e = new ListNode(5);
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;

	ListNode *a2 = new ListNode(1);
	ListNode *b2 = new ListNode(3);
	ListNode *c2 = new ListNode(6);
	ListNode *d2 = new ListNode(8);
	ListNode *e2 = new ListNode(9);
	a2->next = b2;
	b2->next = c2;
	c2->next = d2;
	d2->next = e2;
	ListNode *ret = solution->mergeTwoLists(a, a2);
	while (ret) {
		cout << ret->val << endl;
		ret = ret->next;
	}

	return 0;
}