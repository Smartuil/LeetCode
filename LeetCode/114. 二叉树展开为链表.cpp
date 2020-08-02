#include "iostream"
#include "vector"
#include <algorithm>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//class Solution {
//public:
//	void order(TreeNode* root) {
//		if (root) {
//			cout << root->val;
//			order(root->left);
//			if (root->left) {
//				TreeNode* p = root;
//				while (p->left) {
//					p = p->left;
//				}
//				p->left = root->right;
//				root->right = nullptr;
//			}
//		}
//
//	}
//
//	void flatten(TreeNode* root) {
//		if (root == nullptr) {
//			return;
//		}
//		order(root);
//		TreeNode*p = root;
//		while (!root->right) {
//			root->right = root->left;
//			root->left = nullptr;
//			root = root->right;
//		}
//		root = p;
//	}
//};

class Solution {
public:
	//void flatten(TreeNode* root) {
	//	vector<TreeNode*> l;
	//	preorderTraversal(root, l);
	//	int n = l.size();
	//	for (int i = 1; i < n; i++) {
	//		TreeNode *prev = l.at(i - 1), *curr = l.at(i);
	//		prev->left = nullptr;
	//		prev->right = curr;
	//	}
	//}

	//void preorderTraversal(TreeNode* root, vector<TreeNode*> &l) {
	//	if (root != NULL) {
	//		l.push_back(root);
	//		preorderTraversal(root->left, l);
	//		preorderTraversal(root->right, l);
	//	}
	//}

	TreeNode* last = nullptr;
	void flatten(TreeNode* root) {
		if (root == nullptr) return;
		flatten(root->right);
		flatten(root->left);
		root->right = last;
		root->left = nullptr;
		last = root;
	}
};

int main() {
	Solution *solution = new Solution();
	TreeNode* root = new TreeNode(1, nullptr, nullptr);
	TreeNode* a = new TreeNode(2, nullptr, nullptr);
	TreeNode* b = new TreeNode(3, nullptr, nullptr);
	TreeNode* c = new TreeNode(4, nullptr, nullptr);
	TreeNode* d = new TreeNode(5, nullptr, nullptr);
	TreeNode* e = new TreeNode(6, nullptr, nullptr);
	root->left = a;
	root->right = d;
	a->left = b;
	a->right = c;
	d->right = e;
	solution->flatten(root);
	return 0;
}