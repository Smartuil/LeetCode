#include "iostream"
#include "vector"
#include <algorithm>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
	//vector<int> exchange(vector<int>& nums) {
	//	if (nums.size() == 0) {
	//		return {};
	//	}
	//	vector<int> ret;
	//	int i = 0;
	//	int j = nums.size() - 1;
	//	while (i < j) {
	//		if (nums[i] % 2 == 0 && nums[j] % 2 != 0) {
	//			swap(nums[i], nums[j]);
	//		}
	//		if (nums[i] % 2 != 0 && nums[j] % 2 != 0) {
	//			i++;
	//		}
	//		if (nums[i] % 2 == 0 && nums[j] % 2 == 0) {
	//			j--;
	//		}
	//		if (nums[i] % 2 != 0 && nums[j] % 2 == 0) {
	//			j--;
	//			i++;
	//		}
	//	}
	//	return nums;
	//}

	//vector<int> exchange(vector<int>& nums) {
	//	int i = 0;
	//	for (int j = 1; j < nums.size(); j++) {
	//		if (nums[j] % 2 == 1) {
	//			swap(nums[i], nums[j]);			
	//		}
	//		i++;
	//	}
	//	return nums;
	//}
	
	vector<int> exchange(vector<int>& nums) {
		int i = 0;
		int j = nums.size() - 1;
		while (i < j) {
			if (nums[i] % 2 == 0 && nums[j] % 2 == 1) {
				swap(nums[i], nums[j]);
			}
			else if (nums[i] % 2 == 1) {
				++i;
			}
			else
			{
				--j;
			}
		}
		return nums;
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> nums = {1,2,3,4 };
	vector<int> ret = solution->exchange(nums);
	for (auto i : ret) {
		cout << i << endl;
	}
	return 0;
}