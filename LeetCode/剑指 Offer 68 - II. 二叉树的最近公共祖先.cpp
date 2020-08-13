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

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr || root == p || root == q) return root;
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		if (left == nullptr && right == nullptr) return nullptr; // 1.
		if (left == nullptr) return right; // 3.
		if (right == nullptr) return left; // 4.
		return root; // 2. if(left != null and right != null)
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