#include "iostream"
#include "vector"
#include <map>
#include <set>
#include <queue>
#include <stdlib.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool flag = true;
	int order(TreeNode* root) {
		if (!root)
			return 0;

		int left = order(root->left);
		int right = order(root->right);
		int dif = abs(left - right);
		if (dif > 1) {
			flag = false;
		}
		return (left > right ? left : right) + 1;
				
	}

	bool isBalanced(TreeNode* root) {
		order(root);
		return flag;
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
	b->left = d;
	d->left = c;
	cout << solution->isBalanced(root);
	return 0;
}