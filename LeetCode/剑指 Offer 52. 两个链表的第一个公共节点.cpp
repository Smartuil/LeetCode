#include "iostream"
#include "vector"
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == nullptr || headB == nullptr) {
			return nullptr;
		}
		ListNode *h1 = headA, *h2 = headB;
		while (h1 != h2) {

			h1 = h1 == nullptr ? headB : h1->next;
			h2 = h2 == nullptr ? headA : h2->next;
		}

		return h1;
	}
};

int main() {
	Solution *solution = new Solution();
	ListNode *headA = new ListNode(4);
	ListNode *a = new ListNode(1);
	ListNode *b = new ListNode(8);
	ListNode *c = new ListNode(4);
	ListNode *d = new ListNode(5);

	ListNode *headB = new ListNode(5);
	ListNode *a1 = new ListNode(0);
	ListNode *b1 = new ListNode(1);

	headA->next = a;
	a->next = b;
	b->next = c;
	c->next = d;

	headB->next = a1;
	a1->next = b1;
	b1->next = b;

	cout << solution->getIntersectionNode(headA, headB);
	return 0;
}