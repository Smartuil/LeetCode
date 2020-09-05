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
	bool isPalindrome(ListNode* head) {
		if (!head) return true;
		ListNode* newHead = new ListNode(head->val);
		ListNode* root = newHead;
		ListNode* tmp = head;
		while (tmp) {
			tmp = tmp->next;
			if(tmp)
				newHead->next = new ListNode(tmp->val);
			newHead = newHead->next;
		}

		ListNode* pre = nullptr;
		ListNode* cur = head;
		
		while (head) {
			cur = head->next;
			head->next = pre;
			pre = head;
			head = cur;
		}
		bool ret = true;
		while (pre&&root) {
			if (pre->val != root->val) {
				ret = false;
				break;
			}
			pre = pre->next;
			root = root->next;
		}
		if (pre || root) ret = false;
		return ret;
	}
};

int main() {
	Solution *solution = new Solution();
	ListNode* head = new ListNode(1);
	ListNode* a = new ListNode(2);
	ListNode* b = new ListNode(2);
	ListNode* c = new ListNode(1);
	head->next = a;
	a->next = b;
	b->next = c;
	cout << solution->isPalindrome(head);
	return 0;
}