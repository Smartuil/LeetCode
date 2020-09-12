#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<double> averageOfLevels(TreeNode* root) {
		if (root == nullptr) {
			return {};
		}
		vector<double> ret;
		queue<TreeNode*> q;
		double sum = 0;
		q.push(root);
		while (!q.empty()) {
			int len = q.size();
			int size = len;
			sum = 0;
			while (len > 0) {
				TreeNode* tmp = q.front();
				q.pop();
				sum += tmp->val;
				if (tmp->left) {
					q.push(tmp->left);
				}
				if (tmp->right) {
					q.push(tmp->right);
				}
				len--;
			}
			sum /= size;
			ret.push_back(sum);
		}
		return ret;
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

	vector<double> ret = solution->averageOfLevels(root);
	for (double d : ret) {
		cout << d << " ";
	}
	return 0;
}