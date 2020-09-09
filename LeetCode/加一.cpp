#include "iostream"
#include "vector"
#include "algorithm"
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		digits[digits.size() - 1] += 1;
		for (int i = digits.size() - 1; i > 0; --i) {
			if (digits[i] >= 10) {
				int jinwei = digits[i] / 10;
				digits[i] %= 10;
				digits[i - 1] += jinwei;
			}
		}
		vector<int> ret = digits;
		if (digits[0] >= 0) {
			ret.resize(ret.size() + 1, 0);
			ret[0] = 1;
		}
		return ret;
	}
};

int main() {
	Solution* solution = new Solution();
	vector<int> nums = { 1,2,3 };
	vector<int> ret = solution->plusOne(nums);
	for (auto i : ret) {
		cout << i << " ";
	}
	return 0;
}