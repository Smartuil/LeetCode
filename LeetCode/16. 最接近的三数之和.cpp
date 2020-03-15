#include "iostream"
#include "vector"
#include <algorithm>

using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int distance = abs(nums[0] + nums[1] + nums[nums.size() - 1] - target);
		int ret = nums[0] + nums[1] + nums[nums.size() - 1];
		for (int i = 0; i < nums.size() - 2; i++) {
			int L = i + 1;
			int R = nums.size() - 1;
			while (L < R) {
				if (abs(nums[i] + nums[L] + nums[R] - target) < distance) {
					distance = abs(nums[i] + nums[L] + nums[R] - target);
					ret = nums[i] + nums[L] + nums[R];
				}
				if ((nums[i] + nums[L] + nums[R] - target) < 0) {
					L++;
				}
				else
				{
					R--;
				}
			}
		}
		return ret;
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> nums = { 0,2,1,-3 };
	cout << solution->threeSumClosest(nums, 1);
	return 0;
}