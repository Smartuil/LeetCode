#include "iostream"
#include "vector"
#include <algorithm>

using namespace std;

class Solution {
private:
	vector<int> candidates;
	vector<vector<int>> res;
	vector<int> path;

public:
	void DFS(int start, int target) {
		if (target == 0) {
			res.push_back(path);
			return;
		}
		for (int i = start; i < candidates.size() && target - candidates[i] >= 0; i++) {
			if (i > start && candidates[i] == candidates[i - 1])
				continue;
			path.push_back(candidates[i]);
			DFS(i + 1, target - candidates[i]);
			path.pop_back();
		}
	}

	vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
		sort(candidates.begin(), candidates.end());
		this->candidates = candidates;
		DFS(0, target);

		return res;
	}

};


int main() {
	Solution *solution = new Solution();
	vector<int> candidates = {2,2,2,2,5 };
	vector<vector<int>> ret = solution->combinationSum2(candidates, 4);
	cout << "{" << endl;
	for (int i = 0; i < ret.size(); i++) {
		cout << "{";
		for (int j = 0; j < ret[i].size(); j++) {
			cout << ret[i][j] << " ";
		}
		cout << "}" << endl;
	}
	cout << "}" << endl;
	return 0;
}