#include "iostream"

using namespace std;

struct Node {
	int val;
	Node* next;
	Node(int v) :val(v), next(nullptr) {}
};

void getTow(Node* head1, Node* &head2) {
	if (head1 == nullptr || head1->next == nullptr) return;
	Node* l1 = head1;
	head2 = head1->next;
	Node* next = nullptr;
	Node* copyNode = nullptr;
	while (l1) {
		next = l1->next->next;
		copyNode = l1->next;
		l1->next = next;
		copyNode->next = next == nullptr ? nullptr : next->next;
		l1 = next;
	}
}

Node* reverse(Node* root) {
	Node* pre = nullptr;
	Node* cur = root;
	while (root) {
		cur = root->next;
		root->next = pre;
		pre = root;
		root = cur;
	}
	return pre;
}

Node* merge(Node* l1, Node* l2) {
	Node* root = new Node(0);
	Node* p = root;
	while (l1&&l2) {
		if (l1->val <= l2->val) {
			p->next = l1;
			l1 = l1->next;
		}
		else {
			p->next = l2;
			l2 = l2->next;
		}
		p = p->next;
	}
	if (l1)p->next = l1;
	if (l2)p->next = l2;
	return root->next;
}

int main() {
	Node* root = new Node(1);
	Node* a = new Node(4);
	Node* b = new Node(2);
	Node* c = new Node(3);
	root->next = a;
	a->next = b;
	b->next = c;
	Node* l2 = nullptr;
	getTow(root, l2);
	l2 = reverse(l2);
	Node* ret = merge(root, l2);
	while (ret) {
		cout << ret->val << " ";
		ret = ret->next;
	}
	return 0;
}