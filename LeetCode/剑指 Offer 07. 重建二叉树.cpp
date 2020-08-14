#include "iostream"
#include "string"
#include "vector"
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/solution/cjian-dan-shi-xian-di-gui-by-theowu/
class Solution {
public:
	//TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	//	return digui(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
	//}

	//TreeNode* digui(vector<int>::iterator preBegin, vector<int>::iterator preEnd, vector<int>::iterator inBegin, vector<int>::iterator inEnd) {
	//	if (inBegin == inEnd) {
	//		return nullptr;
	//	}
	//	TreeNode *cur = new TreeNode(*preBegin);
	//	auto root = find(inBegin, inEnd, *preBegin);
	//	cur->left = digui(preBegin + 1, preBegin + 1 + (root - inBegin), inBegin, root);
	//	cur->right = digui(preBegin + 1 + (root - inBegin), preEnd, root + 1, inEnd);
	//	return cur;
	//}

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return recursion(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
	}

	TreeNode* recursion(
		vector<int>::iterator preBegin,
		vector<int>::iterator preEnd,
		vector<int>::iterator inBegin,
		vector<int>::iterator inEnd) {
		if (inBegin == inEnd) {
			return nullptr;
		}
		TreeNode* cur = new TreeNode(*preBegin);
		auto root = find(inBegin, inEnd, *preBegin);
		cur->left = recursion(preBegin + 1, preBegin + 1 + (root - inBegin), inBegin, root);
		cur->right = recursion(preBegin + 1 + (root - inBegin), preEnd, root + 1, inEnd);
		return cur;
	}
};

int main() {
	Solution *soulution = new Solution();
	vector<int> preorder = { 3,9,20,15,7 };
	vector<int> inorder = { 9,3,15,20,7 };
	soulution->buildTree(preorder, inorder);
}