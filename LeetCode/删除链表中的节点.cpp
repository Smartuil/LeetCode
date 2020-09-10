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
	void deleteNode(ListNode* node) {
		ListNode* pre = nullptr;
		while (node->next) {
			node->val = node->next->val;
			if (node->next->next == nullptr) {
				node->next = nullptr;
				break;
			}
			node = node->next;
		}
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
	solution->deleteNode(root);
	while (root) {
		cout << root->val;
		root = root->next;
	}
	return 0;
}