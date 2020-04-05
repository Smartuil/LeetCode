#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
	//vector<int> searchRange(vector<int>& nums, int target) {
	//	vector<int> ret;
	//	vector<int> mark(nums.size(), 0);
	//	int tmp1 = findIndex(nums, mark, target, 0, nums.size()-1);
	//	ret.push_back(tmp1);
	//	int tmp2 = findIndex(nums, mark, target, 0, nums.size()-1);
	//	ret.push_back(tmp2);
	//	return ret;
	//}

	//int findIndex(vector<int>& nums, vector<int>& mark, int target, int left, int right) {
	//	if (left == right) {
	//		if (nums[left] == target && mark[left] == 0) {
	//			return left;
	//		}
	//		else
	//		{
	//			return -1;
	//		}
	//	}
	//	while (left < right) {
	//		int middle = (left + right) / 2;
	//		if (nums[middle] == target) {
	//			if (mark[middle] == 0) {
	//				mark[middle] = 1;
	//				return middle;
	//			}
	//			else
	//			{
	//				int ret = findIndex(nums, mark, target, left, middle - 1);
	//				findIndex(nums, mark, target, middle + 1, right);
	//			}
	//		}
	//		else 
	//		{
	//			if (nums[middle] > target) {
	//				right = middle - 1;
	//			}
	//			else
	//			{
	//				left = middle + 1;
	//			}
	//		}
	//	}
	//}

	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> targetRange = { -1, -1 };

		int leftIdx = extremeInsertionIndex(nums, target, true);

		if (leftIdx == nums.size() || nums[leftIdx] != target) {
			return targetRange;
		}

		targetRange[0] = leftIdx;
		targetRange[1] = extremeInsertionIndex(nums, target, false) - 1;

		return targetRange;
	}

	int extremeInsertionIndex(vector<int> nums, int target, bool left) {
		int lo = 0;
		int hi = nums.size();

		while (lo < hi) {
			int mid = (lo + hi) / 2;
			if (nums[mid] > target || (left && target == nums[mid])) {
				hi = mid;
			}
			else {
				lo = mid + 1;
			}
		}

		return lo;
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> nums = { 5,7,7,8,8,10 };
	vector<int> ret = solution->searchRange(nums, 8);
	for (auto i : ret) {
		cout << i;
	}
	return 0;
}