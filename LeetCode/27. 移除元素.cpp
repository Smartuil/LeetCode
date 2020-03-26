#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		if (nums.size() == 0) {
			return 0;
		}

		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == val) {
				nums[i] = INT_MAX;
			}
		}
		nums.erase(remove(nums.begin(), nums.end(), INT_MAX), nums.end());
		return nums.size();
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> nums = { 3, 2, 2, 3 };
	int len = solution->removeElement(nums, 3);
	for (int i = 0; i < len; i++) {
		cout << nums[i];
	}
	return 0;
}