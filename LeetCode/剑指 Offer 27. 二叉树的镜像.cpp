#include "iostream"
#include "string"
#include "algorithm"
#include "vector"
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	//void order(TreeNode *root, TreeNode *ret) {
	//	if (root) {
	//		order(root->left, ret->right);
	//		ret = root;
	//		order(root->right, ret->left);
	//		ret = root;
	//	}
	//}

	TreeNode* mirrorTree(TreeNode* root) {
		if (root == nullptr) {
			return nullptr;
		}
		TreeNode* tmp = root->left;
		root->left = mirrorTree(root->right);
		root->right = mirrorTree(tmp);
		return root;
	}
};

int main() {
	Solution *solution = new Solution;
	TreeNode* root = new TreeNode(4, nullptr, nullptr);
	TreeNode* a = new TreeNode(2, nullptr, nullptr);
	TreeNode* b = new TreeNode(7, nullptr, nullptr);
	TreeNode* c = new TreeNode(1, nullptr, nullptr);
	TreeNode* d = new TreeNode(3, nullptr, nullptr);
	TreeNode* e = new TreeNode(6, nullptr, nullptr);
	TreeNode* f = new TreeNode(9, nullptr, nullptr);
	root->left = a;
	root->right = b;
	//a->left = c;
	//a->right = d;
	//b->left = e;
	//b->right = f;
	solution->mirrorTree(root);

	return 0;
}