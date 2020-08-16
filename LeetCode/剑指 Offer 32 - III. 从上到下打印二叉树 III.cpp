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

//class Solution {
//public:
//	int high(TreeNode *root) {
//		if (root == nullptr) {
//			return 0;
//		}
//		int left = high(root->left);
//		int right = high(root->right);
//		int max = left > right ? left : right;
//		return max + 1;
//	}
//
//	vector<vector<int>> levelOrder(TreeNode* root) {
//		int root_size = high(root);
//		vector<vector<int>> ret(root_size);
//		queue < pair<int, TreeNode*> > q;
//
//		TreeNode *tmp = root;
//		if (root) {
//			q.push({ 0, root });
//		}
//		while (!q.empty()) {
//			tmp = q.front().second;
//			if (tmp->left) {
//				q.push({ q.front().first + 1, tmp->left });
//			}
//			if (tmp->right) {
//				q.push({ q.front().first + 1, tmp->right });
//			}
//			ret[q.front().first].push_back(q.front().second->val);
//			q.pop();
//
//		}
//		for (int i = 0; i < ret.size(); i++) {
//			if (i % 2 == 1) {
//				reverse(ret[i].begin(), ret[i].end());
//			}
//		}
//		return ret;
//	}
//};

//class Solution {
//public:
//	void bfs(TreeNode* root, vector<vector<int>> &ret, int level) {
//		if (root == nullptr) {
//			return;
//		}
//		if (level >= ret.size())
//			ret.push_back(vector<int>());
//		ret[level].push_back(root->val);
//		bfs(root->left, ret, level + 1);
//		bfs(root->right, ret, level + 1);
//	}
//
//	vector<vector<int>> levelOrder(TreeNode* root) {
//		vector<vector<int>> ret;
//		bfs(root, ret, 0);
//		for (int i = 0; i < ret.size(); i++) {
//			if (i % 2 == 1) {
//				reverse(ret[i].begin(), ret[i].end());
//			}
//		}
//		return ret;
//	}
//};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ret;
		if (root == nullptr) {
			return ret;
		}
		bool flag = true;
		deque<TreeNode*> dq;
		dq.push_back(root);
		while (!dq.empty()) {
			int n = dq.size();
			TreeNode* tmp;
			vector<int> out;
			while (n > 0) {
				if (flag) {
					tmp = dq.front();
					dq.pop_front();
					if (tmp->left)
						dq.push_back(tmp->left);
					if (tmp->right)
						dq.push_back(tmp->right);
				}
				else
				{
					tmp = dq.back();
					dq.pop_back();
					if (tmp->right)
						dq.push_front(tmp->right);
					if (tmp->left)
						dq.push_front(tmp->left);
				}
				out.push_back(tmp->val);
				--n;
			}
			flag = !flag;
			ret.push_back(out);
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