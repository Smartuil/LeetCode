#include "iostream"
#include "vector"
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		vector<vector<int>>vec;
		vector<int> res;
		int sum = 0;
		for (int l = 1, r = 2; l < r;) {
			sum = (l + r)*(r - l + 1) / 2;
			if (sum == target) {
				res.clear();
				for (int i = l; i <= r; i++) {
					res.push_back(i);
				}
				vec.push_back(res);
				l++;
			}
			else if (sum < target) {
				r++;
			}
			else
			{
				l++;
			}
		}
		return vec;
	}
};

int main() {
	Solution *solution = new Solution();
	vector<vector<int>> ret = solution->findContinuousSequence(9);
	for (auto i : ret) {
		for (int j : i)
			cout << j << " ";
		cout << endl;
	}
	return 0;
}