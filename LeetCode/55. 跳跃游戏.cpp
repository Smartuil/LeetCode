#include "iostream"
#include "vector"
#include <algorithm>
using namespace std;

class Solution {
public:

	//int findMax(vector<int>& nums, int &index, vector<bool>& isUse) {
	//	int maxNumber = -1;
	//	for (int i = 1; i < nums.size() - 1; i++) {
	//		if (maxNumber < nums[i]) {
	//			if (!isUse[i]) {
	//				maxNumber = nums[i];
	//				index = i;
	//			}
	//		}
	//	}
	//	
	//	return maxNumber;
	//}

	//bool canJump(vector<int>& nums) {
	//	bool ret = false;
	//	int index = 0;
	//	int currentIndex = 0;
	//	vector<bool> isUse(nums.size(), 0);
	//	int i = 0;
	//	while (i < nums.size()) {
	//		//cout << findMax(nums, index, isUse) << endl;
	//		//cout << index << endl;
	//		findMax(nums, index, isUse);
	//		//isUse[index] = 1;
	//		if ((index - currentIndex) <= nums[currentIndex]) {
	//			if (nums[currentIndex] < nums[index]) {
	//				isUse[currentIndex] = 1;
	//				currentIndex = index;
	//			}
	//			else
	//			{
	//				isUse[currentIndex] = 1;
	//				currentIndex = currentIndex + nums[currentIndex];
	//			}
	//		}
	//		else
	//		{
	//			isUse[currentIndex] = 1;
	//			currentIndex = currentIndex + nums[currentIndex];
	//		}
	//		if ((nums[currentIndex] + currentIndex) >= (nums.size() -1 - currentIndex)) {
	//			ret = true;
	//			break;
	//		}
	//		i = currentIndex;
	//	}
	//	return ret;
	//}

	bool canJump2(vector<int>& nums) {
		int n = nums.size();
		int rightmost = 0;
		for (int i = 0; i < n; ++i) {
			if (i <= rightmost) {
				rightmost = max(rightmost, i + nums[i]);
				if (rightmost >= n - 1) {
					return true;
				}
			}
		}
		return false;
	}

	bool canJump3(vector<int>& nums) {
		int n = nums.size();
		int rightmost = 0;
		for (int i = 0; i < n; ++i) {
			if (i > rightmost) {
				return false;
			}
			rightmost = max(i + nums[i], rightmost);
		}
		
	}

	bool canJump(vector<int>& nums) {
		int n = nums.size();
		int last = n - 1;
		for (int i = n - 2; i >= 0; --i)
			if (i + nums[i] >= last) {
				last = i;
			}
			return last == 0;
	}
};
int main() {
	Solution *solution = new Solution;
	vector<int> matrix = { /*2,3,1,1,4*/3,2,1,0,4 };
	bool ret = solution->canJump(matrix);
	cout << ret;
	return 0;
}