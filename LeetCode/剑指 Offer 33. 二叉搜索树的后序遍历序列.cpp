#include "iostream"
#include "algorithm"
#include "vector"
#include <stack>
using namespace std;

class Solution {
public:
	bool verifyPostorder(vector<int>& postorder) {
		stack<int> s;
		int root = INT_MAX;
		for (int i = postorder.size() - 1; i >= 0; i--) {
			if (postorder[i] > root) {
				return false;
			}
			while (!s.empty() && s.top() > postorder[i])
			{
				root = s.top();
				s.pop();
			}
			s.push(postorder[i]);
		}
		return true;

		//return recur(postorder, 0, postorder.size() - 1);

	}

	//bool recur(vector<int>& postorder, int i, int j) {
	//	if (i >= j)
	//		return true;
	//	int p = i;
	//	while (postorder[p] < postorder[j])
	//		p++;
	//	int m = p;
	//	while (postorder[p] > postorder[j])
	//		p++;
	//	return p == j && recur(postorder, i, m - 1) && recur(postorder, m, j - 1);
	//}
};

int main() {
	Solution *solution = new Solution;
	vector<int> postorder = { 1,6,3,2,5 };
	cout << solution->verifyPostorder(postorder);
	return 0;
}