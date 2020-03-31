#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int pos = nums.size() - 1;
		while (pos > 0 && nums[pos] <= nums[pos - 1])
			pos--;
		reverse(nums.begin() + pos, nums.end());
		if (pos > 0) {
			int start = pos;
			for (; start < nums.size(); start++) {
				if (nums[start] > nums[pos - 1]) {
					swap(nums[start], nums[pos - 1]);
					break;
				}
			}
		}
	}
};

int main() {
	Solution *soulution = new Solution();
	vector<int> nums = { 7,2,4,3 };
	soulution->nextPermutation(nums);
	for (auto i : nums) {
		cout << i;
	}
	return 0;
}