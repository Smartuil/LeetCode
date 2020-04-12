#include "iostream"
#include "vector"
#include <algorithm>

using namespace std;

//class Solution {
//public:
//	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//		return find(candidates, target, {});
//	}
//
//	vector<vector<int>> find(vector<int>& candidates, int target, vector<int> tmp) {
//		vector<vector<int>> ret;
//		if (target == 0) {
//			ret.push_back(tmp);
//			return ret;
//		}
//		if (target < 0) {
//			return { {} };
//		}
//		int n = candidates.size() - 1;
//		for (int i = n; i > 0; i--) {
//			target -= candidates[i];
//			tmp.push_back(candidates[i]);
//			find(candidates, target, tmp);
//		}
//	}
//};

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
			path.push_back(candidates[i]);
			DFS(i, target - candidates[i]);
			path.pop_back();
		}
	}

	vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
		sort(candidates.begin(), candidates.end());
		this->candidates = candidates;
		DFS(0, target);

		return res;
	}

};


int main() {
	Solution *solution = new Solution();
	vector<int> candidates = { 2,3,6,7 };
	vector<vector<int>> ret = solution->combinationSum(candidates, 7);
	cout << "{" << endl;
	for (int i = 0; i < ret.size();i++) {
		cout << "{";
		for (int j = 0; j < ret[i].size(); j++) {
			cout << ret[i][j] << " ";
		}
		cout << "}" << endl;
	}
	cout << "}" << endl;
	return 0;
}