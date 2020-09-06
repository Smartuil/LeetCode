#include "iostream"
#include "vector"
#include "algorithm"
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		auto levelOrder = vector<vector<int>>();
		if (!root) {
			return levelOrder;
		}
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			auto level = vector<int>();
			int size = q.size();
			for (int i = 0; i < size; ++i) {
				auto node = q.front();
				q.pop();
				level.push_back(node->val);
				if (node->left) {
					q.push(node->left);
				}
				if (node->right) {
					q.push(node->right);
				}
			}
			levelOrder.push_back(level);
		}
		reverse(levelOrder.begin(), levelOrder.end());
		return levelOrder;
	}
};

int main() {
	Solution* solution = new Solution();
	TreeNode* root = new TreeNode(3);
	TreeNode* a = new TreeNode(9);
	TreeNode* b = new TreeNode(20);
	TreeNode* c = new TreeNode(15);
	TreeNode* d = new TreeNode(7);
	root->left = a;
	root->right = b;
	b->left = c;
	b->right = d;
	vector<vector<int>> ret = solution->levelOrderBottom(root);
	return 0;
}