#include "iostream"
#include "vector"
#include <algorithm>
#include "MyLinkList.h"

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode* ret = new ListNode(NULL);
		ListNode* head = ret;
		vector<int> tmp;
		for (auto i : lists) {
			while (i) {
				tmp.push_back(i->val);
				i = i->next;
			}
		}
		sort(tmp.begin(), tmp.end());
		for (auto i : tmp) {
			ret->next = new ListNode(i);
			ret = ret->next;
		}
		return head->next;
	}
};
