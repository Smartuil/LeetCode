#include "iostream"
#include "vector"
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int order(TreeNode * root) {
		if (root == nullptr) {
			return 0;
		}
		int left = order(root->left);
		int right = order(root->right);
		int high = left > right ? left : right;
		return high + 1;
	}

	int maxDepth(TreeNode* root) {
		return order(root);
	}
};

int main() {
	Solution *solution = new Solution();
	TreeNode *a = new TreeNode(3);
	TreeNode *b = new TreeNode(1);
	TreeNode *c = new TreeNode(4);
	TreeNode *d = new TreeNode(2);
	a->left = b;
	a->right = c;
	b->right = d;
	cout << solution->maxDepth(a);
	return 0;
}