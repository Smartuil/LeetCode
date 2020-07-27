#include "iostream"
#include "vector"
#include <algorithm>
using namespace std;

//class Solution {
//public:
//	vector<vector<int>> merge(vector<vector<int>>& intervals) {
//		vector<vector<int>> ret;
//		int i = 0, j = 1;
//		int left = 0, right = 0;
//		while (i < intervals.size()-1) {
//			left = intervals[i][0];
//			right = intervals[i][1];
//			while (j < intervals.size()) {
//				
//				
//				if (right >= intervals[j][0]) {
//					right = intervals[j][1];
//					j++;
//				}
//				else {
//					ret.push_back({ left,right });
//					i = j;
//					j += 1;
//					break;
//				}
//				if (j == intervals.size()) {
//					ret.push_back({ left,right });
//					return ret;
//				}
//			}
//			//else
//			//{
//			//	ret.push_back({ left,right });
//			//	i = j;
//			//	j += 1;
//			//}
//		}
//		if (ret.size() == intervals.size()) {
//			return ret;
//		}
//		if (i < intervals.size()) {
//			ret.push_back({ intervals[i][0], intervals[i][1] });
//		}
//		return ret;
//	}
//};

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
};

int main() {
	Solution *solution = new Solution;
	vector<vector<int>> intervals = { {1,3},{2,6},{8,10} ,{15,18} };
	vector<vector<int>> ret = solution->merge(intervals);
	for (auto i : ret) {
		for (auto j : i) {
			cout << j << endl;
		}
	}
	return 0;
}