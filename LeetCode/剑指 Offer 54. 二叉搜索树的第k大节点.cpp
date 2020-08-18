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
	int ret = 0;
	//void order(TreeNode * root, int& k) {
	//	if (root == nullptr) {
	//		return;
	//	}
	//	order(root->right, k);
	//	if (k == 0) {
	//		return;
	//	}
	//	if (--k == 0) {
	//		ret = root->val;
	//	}
	//	order(root->left, k);
	//}

	void order(TreeNode* root, int &k) {
		if (root) {
			order(root->right, k);
			if (k>0) {
				ret = root->val;
				--k;
			}	
			order(root->left, k);
		}
	}

	int kthLargest(TreeNode* root, int k) {
		order(root, k);
		return ret;
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
	cout << solution->kthLargest(a, 1);
	return 0;
}