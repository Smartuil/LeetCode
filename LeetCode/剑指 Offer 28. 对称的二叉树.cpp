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
	/*bool order(TreeNode* root1, TreeNode* root2) {
		if (root1 == nullptr&&root2 == nullptr) {
			return true;
		}
		if (root1 == nullptr || root2 == nullptr || root1->val != root2->val) {
			return false;
		}

		return order(root1->left, root2->right) && order(root1->right, root2->left);
	}

	bool isSymmetric(TreeNode* root) {
		return order(root, root);
	}*/

	bool order(TreeNode* root1, TreeNode* root2) {
		if (root1 == nullptr&&root2 == nullptr) {
			return true;
		}
		if (root1 == nullptr || root2 == nullptr || root1->val != root2->val) {
			return false;
		}
		return order(root1->left, root2->right) && order(root1->right, root2->left);
	}

	bool isSymmetric(TreeNode* root) {
		return order(root, root);
	}
};

int main() {
	Solution *solution = new Solution;
	TreeNode* root = new TreeNode(1, nullptr, nullptr);
	TreeNode* a = new TreeNode(2, nullptr, nullptr);
	TreeNode* b = new TreeNode(2, nullptr, nullptr);
	TreeNode* c = new TreeNode(3, nullptr, nullptr);
	TreeNode* d = new TreeNode(3, nullptr, nullptr);
	TreeNode* e = new TreeNode(4, nullptr, nullptr);
	TreeNode* f = new TreeNode(4, nullptr, nullptr);
	root->left = a;
	root->right = b;
	a->left = nullptr;
	a->right = c;
	b->left = nullptr;
	b->right = d;
	cout << solution->isSymmetric(root);

	return 0;
}