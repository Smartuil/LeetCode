#include "iostream"
#include "vector"
#include <algorithm>
#include <stack>

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
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> stk;
		while (root != nullptr || !stk.empty()) {
			while (root != nullptr) {
				stk.push(root);
				root = root->left;
			}
			root = stk.top();
			stk.pop();
			res.push_back(root->val);
			root = root->right;
		}
		return res;
	}
};

int main() {
	Solution* solution = new Solution();
	TreeNode* a = new TreeNode(1);
	TreeNode* b = new TreeNode(2);
	TreeNode* c = new TreeNode(3);
	a->left = b;
	a->right = c;
	vector<int> ret = solution->inorderTraversal(a);
	for (auto i : ret) {
		cout << i << " ";
	}
	return 0;
}