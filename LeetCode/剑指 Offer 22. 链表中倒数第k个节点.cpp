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
	ListNode* getKthFromEnd(ListNode* head, int k) {
		ListNode *root = head;
		int count = 0;
		while (head) {
			head = head->next;
			count++;
		}
		while (root && count > k) {
			root = root->next;
			count--;
		}
		return root;
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
	ListNode *ret = solution->getKthFromEnd(a, 2);
	while (ret) {
		cout << ret->val << endl;
		ret = ret->next;
	}

	return 0;
}