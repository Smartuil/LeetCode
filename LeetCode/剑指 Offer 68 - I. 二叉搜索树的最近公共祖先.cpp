#include "iostream"
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//class Solution {
//public:
//	TreeNode *parent = nullptr;
//	void order(TreeNode* root, TreeNode* p, TreeNode* q) {
//		if (root) {
//			if ((root->left == p & root->right == q) 
//				|| (root->left == q & root->right == p)
//				|| (root == p && root->right == q) 
//				|| (root == p && root->left == q)
//				|| (root == q && root->right == p)
//				|| (root == q && root->left == p)) {
//				parent = root;
//			}
//			order(root->left, p, q);
//			order(root->right, p, q);
//		}
//	}
//
//	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//		order(root, p, q);
//		return parent;
//	}
//};

class Solution {
public:
	//TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	//	if (p->val > q->val) {
	//		TreeNode* tmp = p;
	//		p = q;
	//		q = tmp;
	//	}
	//	while (root != nullptr) {
	//		if (root->val < p->val) {
	//			root = root->right;
	//		}
	//		else if (root->val > q->val) {
	//			root = root->left;
	//		}
	//		else
	//		{
	//			break;
	//		}
	//	}
	//	return root;
	//}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (p->val > q->val) {
			TreeNode* tmp = p;
			p = q;
			q = tmp;
		}
		while (!root) {
			if (root->val < p->val) {
				root = root->right;
			}
			else if (root->val > q->val) {
				root = root->left;
			}
			else
			{
				break;
			}
		}
		return root;
	}
};

int main() {
	Solution *solution = new Solution();
	TreeNode* a = new TreeNode(6);
	TreeNode* b = new TreeNode(2);
	TreeNode* c = new TreeNode(8);
	TreeNode* d = new TreeNode(0);
	TreeNode* e = new TreeNode(4);
	TreeNode* f = new TreeNode(7);
	TreeNode* g = new TreeNode(9);
	TreeNode* h = new TreeNode(3);
	TreeNode* i = new TreeNode(5);

	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	e->left = h;
	e->right = i;
	c->left = f;
	c->right = g;
	TreeNode* ret = solution->lowestCommonAncestor(a, h, g);
	cout << ret->val;
	return 0;
}