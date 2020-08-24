#include "iostream"
#include <unordered_map>
#include <random>
#include <set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool hasCycle(ListNode *head) {
		//unordered_map<ListNode*, int> tmp;
		//while (head)
		//{
		//	tmp[head] = 1;
		//	head = head->next;
		//	if (tmp[head] == 1) {
		//		return true;
		//	}
		//}
		//return  false;

		//set<ListNode*> s;
		//while (head) {
		//	if (s.count(head)) {
		//		return true;
		//	}
		//	else
		//	{
		//		s.insert(head);
		//	}
		//	head = head->next;
		//}
		//return false;

		if (head == nullptr || head->next == nullptr) {
			return false;
		}
		ListNode *slow = head;
		ListNode *fast = head->next;
		while (slow != fast) {
			if (fast == nullptr || fast->next == nullptr) {
				return false;
			}
			slow = slow->next;
			fast = fast->next->next;
		}
		return true;
	}
};

int main() {
	Solution *solution = new Solution();
	ListNode *a = new ListNode(3);
	ListNode *b = new ListNode(2);
	ListNode *c = new ListNode(0);
	ListNode *d = new ListNode(4);
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = b;
	cout << solution->hasCycle(a);

	return 0;
}