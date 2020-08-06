#include "iostream"
#include "vector"
#include <unordered_map>
using namespace std;

class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};

//class Solution {
//public:
//	Node* copyRandomList(Node* head) {
//		vector<pair<Node*, Node*>> tmp;
//		int i = 0;
//		Node* ret = new Node(0);
//		Node* retHead = ret;
//		Node* tmpHaed = head;
//		while (head) {
//			tmp.push_back({ head->next,head->random });
//			head = head->next;
//		}
//
//		i = 0;
//		while (tmpHaed) {
//			Node* inRet = new Node(tmpHaed->val);
//			inRet->next = tmp[i].first;
//			inRet->random = tmp[i].second;
//			ret->next = inRet;
//			tmpHaed = tmpHaed->next;
//			ret = ret->next;
//			i++;
//		}
//
//		return retHead->next;
//	}
//};

class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (head == NULL)  return head;
		unordered_map<Node*, Node*>mp;
		Node *t = head;
		while (t != NULL) {
			mp[t] = new Node(t->val);
			t = t->next;
		}
		t = head;
		while (t != NULL) {
			if (t->next) {
				mp[t]->next = mp[t->next];
			}
			if (t->random) {
				mp[t]->random = mp[t->random];
			}
			t = t->next;
		}
		return mp[head];
	}
};

int main() {
	Solution *solution = new Solution();
	Node *a = new Node(3);
	Node *b = new Node(3);
	Node *c = new Node(3);
	a->next = b;
	a->random = nullptr;
	b->next = c;
	b->random = a;
	c->random = nullptr;

	solution->copyRandomList(a);
}