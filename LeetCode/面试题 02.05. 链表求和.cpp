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

//class Solution {
//public:
//	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//		ListNode* root = new ListNode(0);
//		ListNode* head = root;
//		int jinwei = 0;
//		while (l1&&l2) {
//			ListNode* tmp = new ListNode(l1->val + l2->val);
//			root->next = tmp;
//			root = root->next;
//			l1 = l1->next;
//			l2 = l2->next;
//		}
//		ListNode* pre = head->next;
//		while (pre) {		
//			if (pre->val > 9) {
//				jinwei = pre->val / 10;
//				pre->val %= 10;
//				if (pre->next) {
//					pre->next->val += jinwei;
//				}
//				else
//				{
//					pre->next = new ListNode(jinwei);
//				}				
//			}
//			else {
//				//jinwei = 0;
//
//				//µ±l2»òl1·Ç¿Õ
//				if (pre->next == nullptr) {
//					if (l1) {
//						if (jinwei) {
//							pre->val = l1->val + pre->val;
//							pre->next = l1->next;
//						}
//						else {
//							pre->next = l1;
//						}
//						l1 = nullptr;
//
//					}
//					else if (l2) {
//						if (jinwei) {
//							pre->val = l2->val + pre->val;
//							pre->next = l2->next;
//						}
//						else
//						{
//							pre->next = l2;
//						}
//						l2 = nullptr;
//					}
//
//					if (pre->val > 9) {
//						jinwei = pre->val / 10;
//						pre->val %= 10;
//						if (pre->next) {
//							pre->next->val += jinwei;
//						}
//						else
//						{
//							pre->next = new ListNode(jinwei);
//						}
//					}
//
//				}
//				if (!pre) break;
//				pre = pre->next;
//			}
//		}
//		return head->next;
//	}
//};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* head = new ListNode(0);
		ListNode* res = head;
		int sum = 0, add = 0;
		while (!(l1 == nullptr && l2 == nullptr)) {
			if (l1 != nullptr && l2 != nullptr) {
				sum = l1->val + l2->val + add;
				l1 = l1->next;
				l2 = l2->next;
			}
			else if (l1 == nullptr && l2 != nullptr) {
				sum = l2->val + add;
				l2 = l2->next;
			}
			else {
				sum = l1->val + add;
				l1 = l1->next;
			}
			if (sum > 9) {
				sum -= 10;
				add = 1;
			}
			else {
				add = 0;
			}
			ListNode* tmp = new ListNode(sum);
			res->next = tmp;
			res = tmp;
		}
		if (add == 1) {
			ListNode* tmp = new ListNode(1);
			res->next = tmp;
			res = tmp;
			res->next = nullptr;
		}
		else {
			res->next = nullptr;
		}
		return head->next;
	}
};

int main() {
	Solution *solution = new Solution();
	ListNode* head = new ListNode(9);
	ListNode* a = new ListNode(8);
	ListNode* b = new ListNode(3);
	ListNode* c = new ListNode(1);
	ListNode* d = new ListNode(9);
	ListNode* e = new ListNode(4);
	head->next = a;
	a->next = b;
	c->next = d;
	d->next = e;
	ListNode* ret = solution->addTwoNumbers(head, c);
	while (ret) {
		cout << ret->val << " ";
		ret = ret->next;
	}
	return 0;
}