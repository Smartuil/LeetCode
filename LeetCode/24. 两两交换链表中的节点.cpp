#include "iostream"
#include "vector"
#include <algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == nullptr) {
			return nullptr;
		}
		if (!head->next) {
			return head;
		}
		ListNode *i = head;
		ListNode *j = i->next;
		ListNode *ret = new ListNode(0);
		ListNode *m_head = ret;

		while (i && j) {
			ret->next = j;
			ret = ret->next;
			if (!j)break;
			i->next = j->next;
			ret->next = i;
			ret = ret->next;
			i = i->next;
			if (!i)break;
			j = i->next;
		}
		return m_head->next;
	}
};

int main() {
	Solution *solution = new Solution();
	ListNode *q = new ListNode(1);
	ListNode *w = new ListNode(2);
	ListNode *e = new ListNode(3);
	ListNode *r = new ListNode(4);
	q->next = w;
	w->next = e;
	e->next = nullptr;
	r->next = nullptr;


	ListNode* ret = solution->swapPairs(q);
	while (ret)
	{
		cout << ret->val << endl;
		ret = ret->next;
	}
	return 0;
}
