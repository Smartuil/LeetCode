#include "iostream"
#include "string"
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
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (root == nullptr) {
			return {};
		}
		vector<vector<int>> ret;
		queue<TreeNode*> q;
		q.push(root);
		int level = 0;
		while (!q.empty()) {
			int len = q.size();
			vector<int> tmpVec;
			tmpVec.clear();
			while (len > 0) {
				TreeNode* tmp = q.front();
				q.pop();
				if (tmp->left) {
					q.push(tmp->left);
				}
				if (tmp->right) {
					q.push(tmp->right);
				}
				tmpVec.push_back(tmp->val);
				len--;
			}
			ret.push_back(tmpVec);
		}
		return ret;
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
	b->left = c;
	b->right = f;
	a->left = e;
	a->right = d;

	vector<vector<int>> ret = solution->levelOrder(root);
	for (auto i : ret) {
		for (int j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	return 0;
}