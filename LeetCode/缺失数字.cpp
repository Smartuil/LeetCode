#include "iostream"
#include "vector"
#include <algorithm>

using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		// 判断 n 是否出现在末位
		if (nums[nums.size() - 1] != nums.size()) {
			return nums.size();
		}
		// 判断 0 是否出现在首位
		else if (nums[0] != 0) {
			return 0;
		}

		// 此时缺失的数字一定在 (0, n) 中
		for (int i = 1; i < nums.size(); i++) {
			int expectedNum = nums[i - 1] + 1;
			if (nums[i] != expectedNum) {
				return expectedNum;
			}
		}

		// 未缺失任何数字（保证函数有返回值）
		return -1;
	}
};

int main() {
	Solution* solution = new Solution();
	vector<int> nums = { 0,1 };
	cout << solution->missingNumber(nums);
	return 0;
}