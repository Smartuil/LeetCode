#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0) {
			return -1;
		}
		if (nums.size() == 1) {
			return nums[0] == target ? 0 : -1;
		}
		int left = 0, right = nums.size(), middle;
		int rotate_index = find_rotate_index(nums, left, right - 1);
		if (nums[rotate_index] == target)
			return rotate_index;
		if (rotate_index == 0)
			return search2(nums, 0, right - 1, target);
		if (target < nums[0])
			return search2(nums, rotate_index, right - 1, target);
		return search2(nums, 0, rotate_index, target);
	}

	int find_rotate_index(vector<int>& nums, int left, int right) {
		if (nums[left] < nums[right]) {
			return 0;
		}
		while (left <= right) {
			int pivot = (left + right) / 2;
			if (nums[pivot] > nums[pivot + 1]) {
				return pivot + 1;
			}
			else
			{
				if (nums[pivot] < nums[left]) {
					right = pivot - 1;
				}
				else
				{
					left = pivot + 1;
				}
			}
		}
		return 0;
	}

	int search2(vector<int>& nums, int left, int right, int target) {
		while (left <= right) {
			int pivot = (left + right) / 2;
			if (nums[pivot] == target)
				return pivot;
			else {
				if (target < nums[pivot])
					right = pivot - 1;
				else
					left = pivot + 1;
			}
		}
		return -1;
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> nums = { 7, 0,1,2 };
	cout << solution->search(nums, 8);
	return 0;
}