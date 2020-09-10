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
	bool isValidBST(TreeNode* root) {
		if (root->left->val > root->val || root->right->val < root->val) {
			return false;
		}

		return isValidBST(root->left) && isValidBST(root->right);
	}
};

int main() {
	Solution *solution = new Solution();
	TreeNode* root = new TreeNode(2);
	TreeNode* a = new TreeNode(1);
	TreeNode* b = new TreeNode(4);
	TreeNode* c = new TreeNode(3);
	TreeNode* d = new TreeNode(6);
	root->left = a;
	root->right = b;
	//b->left = c;
	//b->right = d;

	cout << solution->isValidBST(root);
	return 0;
}