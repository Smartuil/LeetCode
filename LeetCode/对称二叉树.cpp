#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool order(TreeNode* root1, TreeNode* root2) {
		if (root1 == nullptr&&root2 == nullptr) {
			return true;
		}
		if (root1 == nullptr || root2 == nullptr || root1->val != root2->val ) {
			return false;
		}
		return order(root1->left, root2->right) && order(root1->right, root2->left);
	}

	bool isSymmetric(TreeNode* root) {
		return order(root, root);
	}
};

int main() {
	Solution *solution = new Solution();
	TreeNode* root = new TreeNode(1);
	TreeNode* a = new TreeNode(2);
	TreeNode* b = new TreeNode(2);
	TreeNode* c = new TreeNode(3);
	TreeNode* d = new TreeNode(3);
	TreeNode* e = new TreeNode(4);
	TreeNode* f = new TreeNode(4);
	root->left = a;
	root->right = b;
	b->right = c;
	//b->right = f;
	//a->left = e;
	a->right = d;

	cout << solution->isSymmetric(root);
	return 0;
}