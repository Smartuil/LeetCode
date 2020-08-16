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
	queue<TreeNode *> q;
	void order(TreeNode *root, vector<int> &ret) {
		TreeNode *tmp = root;
		if (root) {
			q.push(root);
			//q.push(root->left->val);
			//q.push(root->right->val);
		}
		while (!q.empty()) {
			tmp = q.front();
			if(tmp->left)
				q.push(tmp->left);
			if (tmp->right)
				q.push(tmp->right);
			ret.push_back(q.front()->val);
			q.pop();		
		}
		
	}

	vector<int> levelOrder(TreeNode* root) {
		vector<int> ret;
		order(root, ret);
		return ret; 
	}
};

int main() {
	Solution *solution = new Solution;
	TreeNode* root = new TreeNode(3, nullptr, nullptr);
	TreeNode* a = new TreeNode(9, nullptr, nullptr);
	TreeNode* b = new TreeNode(20, nullptr, nullptr);
	TreeNode* c = new TreeNode(15, nullptr, nullptr);
	TreeNode* d = new TreeNode(7, nullptr, nullptr);
	root->left = a;
	root->right = b;
	b->left = c;
	b->right = d;
	vector<int> ret = solution->levelOrder(root);
	for (auto i : ret) {
		cout << i << endl;
	}
	return 0;
}