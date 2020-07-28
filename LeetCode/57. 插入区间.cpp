#include "iostream"
#include "vector"
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		if (intervals.size() == 0) {
			return {};
		}
		sort(intervals.begin(), intervals.end());
		vector<vector<int>> merged;
		for (int i = 0; i < intervals.size(); ++i) {
			int L = intervals[i][0], R = intervals[i][1];
			if (!merged.size() || merged.back()[1] < L) {
				merged.push_back({ L, R });
			}
			else {
				merged.back()[1] = max(merged.back()[1], R);
			}
		}
		return merged;
	}

	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		if (newInterval.size() == 0) {
			return intervals;
		}
		if (intervals.size() == 0) {
			return { newInterval };
		}
		//sort(intervals.begin(), intervals.end());

		intervals.push_back(newInterval);
		return merge(intervals);

	}
};

int main() {
	Solution *solution = new Solution;
	vector<vector<int>> intervals = { {1,2}, {3,5},{6,7},{8,10},{12,16} };
	vector<int> newInterval = {4,8};
	vector<vector<int>> ret = solution->insert(intervals, newInterval);
	for (auto i : ret) {
		for (auto j : i) {
			cout << j << endl;
		}
	}
	return 0;
}