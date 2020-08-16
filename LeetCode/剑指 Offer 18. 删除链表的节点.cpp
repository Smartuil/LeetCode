#include "iostream"
#include "vector"
#include <algorithm>
#include <string>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

//class Solution {
//public:
//	ListNode* deleteNode(ListNode* head, int val) {
//		
//		ListNode * pre = new ListNode(0);
//		ListNode * root = pre;
//		pre->next = head;
//		while (head) {
//			if (head->val == val) {
//				pre->next = head->next;
//			}
//			pre = head;
//			head = head->next;
//		}
//		root = root->next;
//		return root;
//	}
//};

 class Solution {
 public:
	 ListNode* deleteNode(ListNode* head, int val) {		
		 ListNode* pre = new ListNode(0);
		 ListNode* root = pre;
		 pre->next = head;
		 while (head) {
			 if (head->val == val) {
				 pre->next = head->next;
			 }
			 pre = head;
			 head = head->next;
		 }
		 root = root->next;
		 return root;
	 }
 };

int main() {
	Solution *solution = new Solution();
	ListNode *a = new ListNode(-3);
	ListNode *b = new ListNode(5);
	ListNode *c = new ListNode(-99);
	a->next = b;
	b->next = c;

	ListNode * root = solution->deleteNode(a, -3);

	while (root) {
		cout << root->val;
		root = root->next;
	}
	return 0;
}