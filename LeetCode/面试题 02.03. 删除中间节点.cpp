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
	void deleteNode(ListNode* node) {
		node->val = node->next->val;
		node->next = node->next->next;
	}
};

int main() {
	Solution *solution = new Solution();
	ListNode* head = new ListNode(1);
	ListNode* a = new ListNode(2);
	ListNode* b = new ListNode(3);
	ListNode* c = new ListNode(3);
	ListNode* d = new ListNode(2);
	ListNode* e = new ListNode(1);
	head->next = a;
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	solution->deleteNode(head);
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
	return 0;
}