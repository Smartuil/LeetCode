#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		return findIndex(nums, target);
	}

	int findIndex(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		if (target > nums[right]) {
			return right + 1;
		}
		if (target < nums[left]) {
			return 0;
		}
		if (target == nums[right]) {
			return right;
		}
		if (target == nums[left]) {
			return 0;
		}
		while (left < right)
		{
			int middle = (left + right) / 2;
			if (nums[middle] == target) {
				return middle;
			}
			else
			{
				if (nums[middle] > target) {
					if (target > nums[middle - 1]) {
						return middle;
					}
					if (target == nums[middle - 1]) {
						return middle - 1;
					}
					right = middle - 1;
				}
				else
				{
					if (target < nums[middle + 1]) {
						return middle + 1;
					}
					if (target == nums[middle]) {
						return middle + 1;
					}
					left = middle + 1;
				}
			}
		}
		return 0;
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> nums = { 1,2,3,4,5,10 };
	cout << solution->searchInsert(nums, 4);
	return 0;
}