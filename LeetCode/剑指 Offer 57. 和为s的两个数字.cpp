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
	vector<int> twoSum(vector<int>& nums, int target) {
		//int i = 0;
		//int len = nums.size() - 1;
		//int tmp = 0;
		//while (i < len) {
		//	int mid = (i + len) / 2;
		//	if (nums[mid] < target) {
		//		i = mid + 1;
		//	}
		//	if (nums[mid] > target) {
		//		i = mid - 1;
		//		break;
		//	}
		//}
		//for (int j = 0; j < i; j++) {
		//	for (int k = j + 1; k <= i; k++) {
		//		if ((nums[j] + nums[k]) == target) {
		//			return{ nums[j], nums[k] };
		//		}
		//	}
		//}
		//return {};
		int i = 0;
		int j = nums.size()-1;
		int sum = 0;
		while (i < j) {
			sum = nums[i] + nums[j];
			if (sum > target) {
				j -= 1;
			}
			else if(sum < target)
			{
				i += 1;
			}
			else
			{
				return{ nums[i], nums[j] };
			}
		}
		return{};
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> arr = { 10,26,30,31,47,60 };
	vector<int> ret = solution->twoSum(arr, 40);
	for (int i : ret) {
		cout << i << " ";
	}
	return 0;
}