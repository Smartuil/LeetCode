#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
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
	ListNode* root = new ListNode(4);
	ListNode* a = new ListNode(5);
	ListNode* b = new ListNode(1);
	ListNode* c = new ListNode(9);
	root->next = a;
	a->next = b;
	b->next = c;
	ListNode* ret = solution->reverseList(root);
	while (ret) {
		cout << ret->val;
		ret = ret->next;
	}
	return 0;
}