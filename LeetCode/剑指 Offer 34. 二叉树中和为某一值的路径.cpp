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
	//void order(TreeNode *root, vector<vector<int>>& ret, vector<int>& path, int &inSum, int sum) {
	//	
	//	if (root) {
	//		inSum += root->val;
	//		path.push_back(root->val);
	//		//if (inSum > sum) {
	//		//	return;
	//		//}
	//		if (inSum == sum) {
	//			
	//			if (!root->left&&!root->right) {
	//				ret.push_back(path);
	//				leaf.push_back(1);
	//			}
	//		}
	//		order(root->left, ret, path, inSum, sum);
	//		if (root->left) {
	//			inSum -= root->left->val;
	//			path.pop_back();
	//		}

	//		order(root->right, ret, path, inSum, sum);
	//		if (root->right) {
	//			inSum -= root->right->val;
	//			path.pop_back();
	//		}
	//			
	//	}
	//}

	void order(TreeNode* root, vector<vector<int>>& ret, vector<int>& paths, int& inSum, int sum) {
		/*if (root) {
			inSum += root->val;
			paths.push_back(root->val);
			if (inSum == sum) {
				if(!root->left && !root->right)
					ret.push_back(paths);
			}

			order(root->left, ret, paths, inSum, sum);
			if (root->left) {
				inSum -= root->left->val;
				paths.pop_back();
			}

			order(root->right, ret, paths, inSum, sum);
			if (root->right) {
				inSum -= root->right->val;
				paths.pop_back();
			}
		}*/

		if (root == nullptr) {
			return;
		}
		paths.push_back(root->val);
		sum -= root->val;
		if (sum == 0 && root->left == nullptr&&root->right == nullptr) {
			ret.push_back(paths);
		}
		order(root->left, ret, paths, inSum, sum);
		order(root->right, ret, paths, inSum, sum);
		paths.pop_back();
	}

	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> ret;
		vector<int> paths;
		int inSum = 0;
		order(root, ret, paths, inSum, sum);
		//for (int i = 0; i < leaf.size(); i++) {
		//	if (leaf.size() == 0) {
		//		return {};
		//	}
		//	if (leaf[i] != 1) {
		//		return {};
		//	}
		//}
		return ret;
	}
};

int main() {
	Solution *solution = new Solution;
	TreeNode* root = new TreeNode(5, nullptr, nullptr);
	TreeNode* a = new TreeNode(4, nullptr, nullptr);
	TreeNode* b = new TreeNode(8, nullptr, nullptr);
	TreeNode* c = new TreeNode(11, nullptr, nullptr);
	TreeNode* d = new TreeNode(13, nullptr, nullptr);
	TreeNode* e = new TreeNode(4, nullptr, nullptr);
	TreeNode* f = new TreeNode(7, nullptr, nullptr);
	TreeNode* g = new TreeNode(2, nullptr, nullptr);
	TreeNode* h = new TreeNode(5, nullptr, nullptr);
	TreeNode* i = new TreeNode(1, nullptr, nullptr);
	root->left = a;
	root->right = b;
	a->left = c;
	c->left = f;
	c->right = g;
	b->left = d;
	b->right = e;
	e->left = h;
	e->right = i;
	vector<vector<int>> ret = solution->pathSum(root,22);
	for (auto i : ret) {
		for (auto j : i) {
			cout << j << endl;
		}
		cout << endl;
	}
	return 0;
}