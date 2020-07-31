#include "iostream"
#include "string"
#include "vector"
#include <Windows.h>
using namespace std;

struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	vector<int> reversePrint(ListNode* head) {
		vector<int> ret;
		ListNode* pre = nullptr;
		ListNode* cur = head;
		ListNode* tmp = nullptr;
		while (cur) {
			tmp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = tmp;
		}

		while (pre) {
			ret.push_back(pre->val);
			pre = pre->next;
		}
		return ret;
	}
};

int main() {
	Solution *solution = new Solution();
	ListNode *a = new ListNode(5);
	ListNode *b = new ListNode(6);
	ListNode *c = new ListNode(7);
	a->next = b;
	b->next = c;
	c->next = nullptr;
	vector<int> ret = solution->reversePrint(a);
	for (auto i : ret) {
		cout << i << endl;
	}
	return 0;
}