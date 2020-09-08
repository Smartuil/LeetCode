#include "iostream"
#include "vector"
#include "algorithm"
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int ret = 0;
		for (int num : nums) {
			ret ^= num;
		}
		return ret;
	}
};

int main() {
	Solution* solution = new Solution();
	vector<int> nums = { 2,2,1 };
	cout << solution->singleNumber(nums);
	return 0;
}