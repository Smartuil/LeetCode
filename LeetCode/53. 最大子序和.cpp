#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int ret = 0;
		int max = INT_MIN;
		if (nums.size() == 1) {
			return nums[0];
		}
		for (int i = 0; i < nums.size() - 1; i++) {
			if (nums[i] > max) {
				max = nums[i];
			}
			int tmp = nums[i];
			for (int j = i + 1; j < nums.size(); j++) {
				
				tmp += nums[j];
				if (tmp > max) {
					max = tmp;
				}
				if (nums[j] > max) {
					max = nums[j];
				}
			}
		}

		return max;
	}
};

int main() {
	Solution *solution = new Solution;
	vector<int> nums = {-2, 1};
	int ret = solution->maxSubArray(nums);
	cout << ret;
}