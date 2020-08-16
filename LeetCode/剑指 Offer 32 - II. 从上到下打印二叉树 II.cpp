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
	//int high(TreeNode *root) {
	//	if (root == nullptr) {
	//		return 0;
	//	}
	//	int left = high(root->left);
	//	int right = high(root->right);
	//	int max = left > right ? left : right;
	//	return max + 1;
	//}

	//vector<vector<int>> levelOrder(TreeNode* root) {
	//	int root_size = high(root);
	//	vector<vector<int>> ret(root_size);
	//	//queue<TreeNode *> q;
	//	//vector<int> level(10000);
	//	queue < pair<int, TreeNode*> > q;
	//	int i = 0;
	//	TreeNode *tmp = root;
	//	if (root) {
	//		q.push({0, root});
	//		//level[root->val] = i;
	//	}
	//	while (!q.empty()) {
	//		tmp = q.front().second;
	//		if (tmp->left) {
	//			q.push({q.front().first+1, tmp->left});
	//			//level[tmp->left->val] = level[tmp->val]+1;
	//		}	
	//		if (tmp->right) {
	//			q.push({ q.front().first + 1, tmp->right });
	//			//level[tmp->right->val] = level[tmp->val]+1;
	//		}
	//		
	//		ret[q.front().first].push_back(q.front().second->val);
	//		q.pop();
	//		i++;
	//	}
	//	return ret;
	//}

	//int high(TreeNode* root) {
	//	if (!root) {
	//		return 0;
	//	}
	//	int left = high(root->left);
	//	int right = high(root->right);
	//	int max = left > right ? left : right;
	//	return max + 1;
	//}

	//vector<vector<int>> levelOrder(TreeNode* root) {
	//	vector<vector<int>> ret;
	//	int len = high(root);
	//	ret.resize(len);
	//	queue<pair<TreeNode*, int>> level;
	//	TreeNode* tmp;
	//	int i = 0;
	//	if (root) {
	//		level.push({ root, i });
	//		++i;
	//	}
	//	while (!level.empty()) {
	//		tmp = level.front().first;
	//		if (tmp->left)
	//			level.push({ tmp->left, level.front().second+1});
	//		if(tmp->right)
	//			level.push({ tmp->right,level.front().second + 1 });
	//		ret[level.front().second].push_back(tmp->val);
	//		level.pop();
	//	}
	//	return ret;
	//}

public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		dfs(root, res, 0);
		return res;
	}

	void dfs(TreeNode* root, vector<vector<int>>& res, int level)
	{
		if (!root) return;
		if (level >= res.size()) 
			res.emplace_back(vector<int>());
		res[level].emplace_back(root->val);
		dfs(root->left, res, level + 1);
		dfs(root->right, res, level + 1);
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