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
	unordered_set<int> s;
	ListNode* removeDuplicateNodes(ListNode* head) {
		ListNode*pre = nullptr;
		ListNode*root = head;
		while (head) {
			if (s.count(head->val) == 0) {
				s.insert(head->val);
				pre = head;
				head = head->next;
			}
			else
			{
				pre->next = head->next;
				head = head->next;
			}

		}
		return root;
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
	ListNode* ret = solution->removeDuplicateNodes(head);
	while (ret) {
		cout << ret->val << " ";
		ret = ret->next;
	}
	return 0;
}