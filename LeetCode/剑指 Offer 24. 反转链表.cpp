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
	//ListNode* reverseList(ListNode* head) {
	//	ListNode* pre = nullptr;
	//	ListNode* cur = head;

	//	while (cur) {
	//		ListNode* tmp = cur->next;
	//		cur->next = pre;
	//		pre = cur;
	//		cur = tmp;
	//	}
	//	return pre;
	//}

	ListNode* reverseList(ListNode* head) {
		ListNode* pre = nullptr;
		ListNode* cur = head;
		while (head) {
			cur = head->next;
			head->next = pre;
			pre = head;
			head = cur;
		}
		return pre;
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
	ListNode *ret = solution->reverseList(a);
	while (ret) {
		cout << ret->val << endl;
		ret = ret->next;
	}

	return 0;
}