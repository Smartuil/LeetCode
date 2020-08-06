#include "iostream"
#include "vector"
#include <unordered_map>
using namespace std;

class Node {
public:
	int val;
	Node* left;
	Node* right;

	Node() {}

	Node(int _val) {
		val = _val;
		left = NULL;
		right = NULL;
	}

	Node(int _val, Node* _left, Node* _right) {
		val = _val;
		left = _left;
		right = _right;
	}
};

class Solution {
public:
	void order(Node* root, Node* &head, Node* &pre) {
		if (!root) return;
		order(root->left, head, pre);
		if (!head) {
			head = root;
			pre = root;
		}
		else
		{
			pre->right = root;
			root->left = pre;
			pre = root;
		}
		order(root->right, head, pre);
	}

	Node* treeToDoublyList(Node* root) {
		if (!root) return nullptr;
		Node* head = nullptr, *pre = nullptr;
		order(root, head, pre);
		head->left = pre;
		pre->right = head;
		return head;
	}
};

int main() {
	Solution *solution = new Solution();
	Node *a = new Node(1);
	Node *b = new Node(2);
	Node *c = new Node(3);
	Node *d = new Node(4);
	Node *e = new Node(5);
	d->left = b;
	d->right = e;
	b->left = a;
	b->right = c;

	solution->treeToDoublyList(d);
}