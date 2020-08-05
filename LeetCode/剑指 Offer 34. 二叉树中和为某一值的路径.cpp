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

class Solution {
public:
	vector<int> leaf;

	void order(TreeNode *root, vector<vector<int>>& ret, vector<int>& path, int &inSum, int sum) {
		
		if (root) {
			inSum += root->val;
			path.push_back(root->val);
			//if (inSum > sum) {
			//	return;
			//}
			if (inSum == sum) {
				
				if (!root->left&&!root->right) {
					ret.push_back(path);
					leaf.push_back(1);
				}
			}
			order(root->left, ret, path, inSum, sum);
			if (root->left) {
				inSum -= root->left->val;
				path.pop_back();
			}

			order(root->right, ret, path, inSum, sum);
			if (root->right) {
				inSum -= root->right->val;
				path.pop_back();
			}
				
		}
	}

	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> ret;
		vector<int> paths;
		int inSum = 0;
		order(root, ret, paths, inSum, sum);
		for (int i = 0; i < leaf.size(); i++) {
			if (leaf.size() == 0) {
				return {};
			}
			if (leaf[i] != 1) {
				return {};
			}
		}
		return ret;
	}
};

int main() {
	Solution *solution = new Solution;
	TreeNode* root = new TreeNode(1, nullptr, nullptr);
	TreeNode* a = new TreeNode(-2, nullptr, nullptr);
	TreeNode* b = new TreeNode(-3, nullptr, nullptr);
	TreeNode* c = new TreeNode(1, nullptr, nullptr);
	TreeNode* d = new TreeNode(3, nullptr, nullptr);
	TreeNode* e = new TreeNode(-2, nullptr, nullptr);
	TreeNode* f = new TreeNode(-1, nullptr, nullptr);
	TreeNode* g = new TreeNode(2, nullptr, nullptr);
	TreeNode* h = new TreeNode(5, nullptr, nullptr);
	TreeNode* i = new TreeNode(1, nullptr, nullptr);
	root->left = a;
 	root->right = b;
 	a->left = c;
 	a->right = d;
 	c->left = f;
	//c->right = g;
	b->left = e;
	//b->right = e;
	//e->left = h;
	//e->right = i;
	vector<vector<int>> ret = solution->pathSum(root, -1);
	for (auto i : ret) {
		for (auto j : i) {
			cout << j << endl;
		}
		cout << endl;
	}
	return 0;
}