#include "iostream"
#include "algorithm"
#include "vector"
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//class Solution {
//public:
//	queue<TreeNode *> q;
//	void order(TreeNode *root, vector<int> &ret) {
//		TreeNode *tmp = root;
//		if (root) {
//			q.push(root);
//			//q.push(root->left->val);
//			//q.push(root->right->val);
//		}
//		while (!q.empty()) {
//			tmp = q.front();
//			if (tmp->left)
//				q.push(tmp->left);
//			if (tmp->right)
//				q.push(tmp->right);
//			ret.push_back(q.front()->val);
//			q.pop();
//		}
//
//	}
//
//	vector<int> levelOrder(TreeNode* root) {
//		vector<int> ret;
//		order(root, ret);
//		return ret;
//	}
//};

class Solution {
public:
	int high(TreeNode *root) {
		if (root == nullptr) {
			return 0;
		}
		int left = high(root->left);
		int right = high(root->right);
		int max = left > right ? left : right;
		return max + 1;
	}

	vector<vector<int>> levelOrder(TreeNode* root) {
		int root_size = high(root);
		vector<vector<int>> ret(root_size);
		queue < pair<int, TreeNode*> > q;

		TreeNode *tmp = root;
		if (root) {
			q.push({ 0, root });
		}
		while (!q.empty()) {
			tmp = q.front().second;
			if (tmp->left) {
				q.push({ q.front().first + 1, tmp->left });
			}
			if (tmp->right) {
				q.push({ q.front().first + 1, tmp->right });
			}
			ret[q.front().first].push_back(q.front().second->val);
			q.pop();

		}
		for (int i = 0; i < ret.size(); i++) {
			if (i % 2 == 1) {
				reverse(ret[i].begin(), ret[i].end());
			}
		}
		return ret;
	}
};

int main() {
	Solution *solution = new Solution;
	TreeNode* root = new TreeNode(0, nullptr, nullptr);
	TreeNode* a = new TreeNode(2, nullptr, nullptr);
	TreeNode* b = new TreeNode(4, nullptr, nullptr);
	TreeNode* c = new TreeNode(1, nullptr, nullptr);
	TreeNode* d = new TreeNode(3, nullptr, nullptr);
	TreeNode* e = new TreeNode(-1, nullptr, nullptr);
	TreeNode* f = new TreeNode(5, nullptr, nullptr);
	TreeNode* g = new TreeNode(1, nullptr, nullptr);
	TreeNode* h = new TreeNode(6, nullptr, nullptr);
	TreeNode* i = new TreeNode(8, nullptr, nullptr);
	root->left = a;
	root->right = b;
	a->left = c;
	c->left = f;
	c->right = g;
	b->left = d;
	b->right = e;
	d->right = h;
	e->right = i;
	vector<vector<int>> ret = solution->levelOrder(root);
	for (auto i : ret) {
		for (auto j : i) {
			cout << j << endl;
		}
		cout << endl;
	}
	return 0;
}