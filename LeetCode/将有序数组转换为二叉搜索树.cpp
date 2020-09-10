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
	TreeNode* sortedArrayToBST(vector<int>& nums) {

	}
};
int main() {
	Solution *solution = new Solution();
	vector<int> nums = { -10,-3,0,5,9 };
	TreeNode* ret = solution->sortedArrayToBST(nums);
	return 0;
}