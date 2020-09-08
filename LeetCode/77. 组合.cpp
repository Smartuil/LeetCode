#include "iostream"
#include "vector"
#include "algorithm"
#include <queue>
using namespace std;

class Solution {
public:
	vector<int> temp;
	vector<vector<int>> ans;

	void dfs(int cur, int n, int k) {
		if (n - cur + 1 + temp.size() < k) {
			return;
		}
		if (temp.size() == k) {
			ans.push_back(temp);
			return;
		}
		temp.push_back(cur);
		dfs(cur + 1, n, k);
		temp.pop_back();
		dfs(cur + 1, n, k);
	}

	vector<vector<int>> combine(int n, int k) {
		dfs(1, n, k);
		return ans;
	}
};

int main() {
	Solution* solution = new Solution();
	vector<vector<int>> ret = solution->combine(4, 2);
	for (auto i : ret) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout <<  endl;
	}
	return 0;
}