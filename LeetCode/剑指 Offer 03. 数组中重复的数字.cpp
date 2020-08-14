#include "iostream"
#include "vector"
#include <algorithm>
#include "queue"
#include "set"
#include <unordered_set>
using namespace std;

class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		if (nums.size() == 0) {
			return 0;
		}
		//vector<int> count(nums.size(), 1);
		//for (int i = 0; i < nums.size(); i++) {
		//	for (int j = i + 1; j < nums.size(); j++) {
		//		if (nums[i] == nums[j] && count[j] == 1) {
		//			count[i]++;
		//			count[j]++;
		//			return nums[i];
		//		}
		//	}
		//}
		//set<int> s;
		//int repeat = -1;
		//for (int num : nums) {
		//	if (!s.insert(num).second) {
		//		repeat = num;
		//		break;
		//	}
		//}
		//return repeat;

		//vector<int> arr(nums.size(), 0);
		//int ans;

		//for (int i = 0; i < nums.size(); ++i) {
		//	arr[nums[i]]++;
		//	if (arr[nums[i]] > 1) {
		//		ans = nums[i];
		//		break;
		//	}
		//}
		//return ans;


		unordered_set<int> s;
		for (int i = 0; i < nums.size(); ++i) {
			if (!s.insert(nums[i]).second) {
				return nums[i];
			}
		}
		return -1;
	}
};

int main() {
	Solution *solution = new Solution;
	vector<int> nums = { 0, 1, 2, 3, 4, 11, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	cout << solution->findRepeatNumber(nums);

	return 0;
}