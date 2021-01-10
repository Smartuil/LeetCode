#include "iostream"
#include "vector"
#include <algorithm>

using namespace std;

class Solution {
public:
	//https://leetcode-cn.com/problems/increasing-triplet-subsequence/solution/334-di-zeng-de-san-yuan-zi-xu-lie-liang-chong-si-l/
	//动态规划
	bool increasingTriplet(vector<int>& nums) {
		int size = nums.size();
		vector<int> dp(size, 1);
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < i; ++j) {
				if (nums[j] < nums[i]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
				if (dp[i] >= 3) return true;
			}
		}
		return false;
	}

	//双指针
	bool increasingTriplet2(vector<int>& nums) {
		int m1 = INT_MAX, m2 = INT_MAX;
		for (auto a : nums) {
			if (m1 >= a) m1 = a;
			else if (m2 >= a) m2 = a;
			else return true;
		}
		return false;
	}

	//前后遍历
	bool increasingTriplet3(vector<int>& nums) {
		if (nums.size() < 3) return false;
		int size = nums.size();
		vector<int> f(size, nums[0]), b(size, nums.back());
		for (int i = 1; i < size; ++i) {
			f[i] = min(f[i - 1], nums[i]);
		}
		for (int i = size - 2; i >= 0; --i) {
			b[i] = max(b[i + 1], nums[i]);
		}
		for (int i = 0; i < size; ++i) {
			if (f[i] < nums[i] && nums[i] < b[i]) return true;
		}
		return false;
	}
};

int main() {
	Solution* solution = new Solution();
	vector<int> nums = { 1,2,3,4,5 };
	cout << solution->increasingTriplet(nums);
	return 0;
}