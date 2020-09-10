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
	bool isPalindrome(ListNode* head) {
		ListNode* q = head; //快指针
		ListNode* cur = head, *pre = NULL; //反转链表的模板
		while (q && q->next) {
			q = q->next->next; //2倍慢指针的速度
			ListNode* temp = cur->next; //反转链表的模板
			cur->next = pre;
			pre = cur;
			cur = temp;
		}
		if (q) cur = cur->next; //奇数链表处理
		while (pre) { //开始对比
			if (pre->val != cur->val) return false;
			pre = pre->next;
			cur = cur->next;
		}
		return true;
	}
};

int main() {
	Solution *solution = new Solution();
	ListNode* root = new ListNode(1);
	ListNode* a = new ListNode(1);
	ListNode* b = new ListNode(2);
	ListNode* c = new ListNode(1);
	root->next = a;
	a->next = b;
	b->next = c;
	cout << solution->isPalindrome(root);
	return 0;
}