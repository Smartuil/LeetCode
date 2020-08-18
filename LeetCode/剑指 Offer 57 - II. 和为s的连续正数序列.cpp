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
		for (int i = 1, j = 2; i < j;) {
			sum = (i + j)*(j - i + 1) / 2;
			if (sum == target) {
				res.clear();
				for (int m = i; m <= j; m++) {
					res.push_back(m);
				}
				vec.push_back(res);
				j++;
			}
			else if (sum > target) {
				i++;
			}
			else
			{
				j++;
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