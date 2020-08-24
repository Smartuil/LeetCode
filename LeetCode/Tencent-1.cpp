#include "iostream"

using namespace std;

struct Node {
	int val;
	Node* next;
	Node(int v) :val(v), next(nullptr) {};
};

int main() {
	int n, k;
	Node *head = new Node(0);
	Node *tmp = head;
	while (cin >> n >> k) {
		for (int i = 0; i < n; ++i) {
			int tmpNum;
			cin >> tmpNum;
			tmp->next = new Node(tmpNum);
			tmp = tmp->next;
		}

		tmp = head;
		Node *pre = tmp;
		while (k > 0) {
			pre = tmp;
			tmp = tmp->next;
			k--;
		}

		pre->next = tmp->next;

		while (head->next) {
			cout << head->next->val << " ";
			head = head->next;
		}
	}
	return 0;
}