#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include <queue>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}
		int size = nums.size();
		if (size == 1) {
			return nums[0];
		}
		vector<int> dp = vector<int>(size, 0);
		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
		for (int i = 2; i < size; i++) {
			dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
		}
		return dp[size - 1];
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> nums = { 1,2,3,1 };
	cout << solution->rob(nums);
	return 0;
}