#include "iostream"
#include <sstream>
#include "vector"
#include <set>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <deque>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		if (!head || !head->next)  return head;
		ListNode* h1 = new ListNode(0), *t1 = h1;
		ListNode* h2 = new ListNode(0), *t2 = h2;
		t1->next = NULL; t2->next = NULL;
		while (head) {
			if (head->val < x) {
				t1->next = head;
				t1 = t1->next;
			}
			else {
				t2->next = head;
				t2 = t2->next;
			}
			head = head->next;
		}
		t1->next = h2->next;
		t2->next = NULL;
		return h1->next;
	}
};

int main() {
	Solution *solution = new Solution();
	ListNode* head = new ListNode(3);
	ListNode* a = new ListNode(5);
	ListNode* b = new ListNode(8);
	ListNode* c = new ListNode(5);
	ListNode* d = new ListNode(10);
	ListNode* e = new ListNode(2);
	head->next = a;
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	solution->partition(head, 5);
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
	return 0;
}