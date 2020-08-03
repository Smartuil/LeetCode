#include "iostream"
#include "vector"
#include <algorithm>
#include <string>
#include <map>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

	//TreeNode* order(TreeNode *root, int val) {
	//	TreeNode* tmp = nullptr;
	//	if (root && root->val != val) {
	//		tmp = order(root->left, val);
	//		
	//		tmp = order(root->right, val);
	//		//return tmp;
	//	}
	//	return tmp;
	//}
	
	bool recur(TreeNode* A, TreeNode* B) {
		if (B == nullptr) return true;
		if (A == nullptr || A->val != B->val) return false;
		return recur(A->left, B->left) && recur(A->right, B->right);
	}

	bool isSubStructure(TreeNode* A, TreeNode* B) {
		return (A != nullptr&&B != nullptr) && (recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B));

	}
};

int main() {
	Solution *solution = new Solution();
	TreeNode *a = new TreeNode(3);
	TreeNode *b = new TreeNode(4);
	TreeNode *c = new TreeNode(5);
	TreeNode *d = new TreeNode(1);
	TreeNode *e = new TreeNode(2);
	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;

	TreeNode *f = new TreeNode(4);
	TreeNode *g = new TreeNode(1);
	f->left = g;
	cout << solution->isSubStructure(a, f);
	return 0;
}