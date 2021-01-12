#include "iostream"
#include "vector"
#include <algorithm>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		if (head == nullptr) {
			return head;
		}
		ListNode* evenHead = head->next;
		ListNode* odd = head;
		ListNode* even = evenHead;
		while (even != nullptr && even->next != nullptr) {
			odd->next = even->next;
			odd = odd->next;
			even->next = odd->next;
			even = even->next;
		}
		odd->next = evenHead;
		return head;
	}
};

int main() {
	Solution* solution = new Solution();
	ListNode* a = new ListNode(1);
	ListNode* b = new ListNode(2);
	ListNode* c = new ListNode(3);
	ListNode* d = new ListNode(4);
	ListNode* e = new ListNode(5);
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	e->next = nullptr;
	ListNode* ret = solution->oddEvenList(a);
	while (ret) {
		cout << ret->val << " ";
		ret = ret->next;
	}
	return 0;
}