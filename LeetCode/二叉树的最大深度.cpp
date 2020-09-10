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
	int maxDepth(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		int left = maxDepth(root->left);
		int right = maxDepth(root->right);
		return left > right ? left : right + 1;
	}
};

int main() {
	Solution *solution = new Solution();
	TreeNode* root = new TreeNode(3);
	TreeNode* a = new TreeNode(9);
	TreeNode* b = new TreeNode(20);
	TreeNode* c = new TreeNode(15);
	TreeNode* d = new TreeNode(7);
	root->left = a;
	root->right = b;
	b->left = c;
	b->right = d;

	cout << solution->maxDepth(root);
	return 0;
}