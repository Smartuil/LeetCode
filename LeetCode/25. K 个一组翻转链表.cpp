#include "iostream"
#include "vector"
#include <algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


//class Solution {
//public:
//	ListNode* reverseKGroup(ListNode* head, int k) {
//		ListNode *i = head;
//		ListNode *j = i;
//		ListNode *m_head = new ListNode(0);
//		ListNode *m = m_head;
//		while (head) {
//			for (int n = 0; n < k - 1; n++) {
//				if (j == NULL)break;
//				j = j->next;
//			}
//			if (j == NULL)break;
//			ListNode *tmp = j->next;
//			j->next = nullptr;
//			
//			while(i) {
//				ListNode *tmp = new ListNode(i->val);
//				tmp->next = m_head->next;
//				if (m->next == NULL)m = tmp;
//				m_head->next = tmp;
//				i = i->next;
//			}
//			//m->next = tmp;
//			i = j = tmp;
//		}
//
//
//		return m_head->next;
//	}
//};

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* p = new ListNode(0);
		p->next = head;
		head = p;
		while (p) {
			ListNode* pi = p;
			for (int i = 0; i < k; i++) {
				pi = pi->next;
				if (!pi)return head->next;
			}
			for (int i = 0; i < k - 1; i++) {
				ListNode* d = p->next;
				p->next = d->next;
				d->next = pi->next;
				pi->next = d;
				//pi=d;
			}
			for (int i = 0; i < k; i++)p = p->next;
		}
		return head->next;
	}
};

int main() {
	Solution *solution = new Solution();
	ListNode *q = new ListNode(1);
	ListNode *w = new ListNode(2);
	ListNode *e = new ListNode(3);
	ListNode *r = new ListNode(4);
	ListNode *t = new ListNode(5);
	q->next = w;
	w->next = e;
	e->next = r;
	r->next = t;
	t->next = nullptr;
	ListNode* ret = solution->reverseKGroup(q, 4);
	while (ret)
	{
		cout << ret->val << endl;
		ret = ret->next;
	}
	return 0;
}
