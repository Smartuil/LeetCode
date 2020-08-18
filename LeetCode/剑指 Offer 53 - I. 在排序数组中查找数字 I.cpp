#include "iostream"
#include "vector"
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
	int recursion(vector<int>& nums, int target) {
		int i = 0;
		int j = nums.size() - 1;
		while (i <= j) {
			int mid = (i + j) / 2;
			if (nums[mid] <= target) {
				i = mid + 1;
			}
			else
			{
				j = mid - 1;
			}
		}
		return i;
	}

	int search(vector<int>& nums, int target) {
		//return recursion(nums, target) - recursion(nums, target - 1);
	//	if (nums.size() == 0) {
	//		return 0;
	//	}
	//	map<int, int> m;
	//	int count = 0;
	//	for (int i = 0; i < nums.size(); i++) {
	//		m[nums[i]]++;
	//	}
	//	auto index = m.find(target);
	//	if (index != m.end()) {
	//		return index->second;
	//	}
	//	else
	//	{
	//		return 0;
	//	}
		
		// 搜索右边界 right
		int i = 0, j = nums.size() - 1;
		while (i <= j) {
			int m = (i + j) / 2;
			if (nums[m] <= target) i = m + 1;
			else j = m - 1;
		}
		int right = i;
		// 若数组中无 target ，则提前返回
		if (j >= 0 && nums[j] != target) return 0;
		// 搜索左边界 right
		i = 0; j = nums.size() - 1;
		while (i <= j) {
			int m = (i + j) / 2;
			if (nums[m] < target) i = m + 1;
			else j = m - 1;
		}
		int left = j;
		return right - left - 1;

		//map<int, int> m;
		//for (int i : nums) {
		//	m[i]++;
		//}
		//return m[target];
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> nums = { 5,7,7,8,8,10 };
	cout << solution->search(nums, 8);
	return 0;
}