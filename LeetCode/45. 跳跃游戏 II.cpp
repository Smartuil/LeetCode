#include "iostream"
#include "vector"

using namespace std;

//class Solution {
//public:
//	int jump(vector<int>& nums) {
//		int jumpNumber = 0;
//		int len = nums.size();
//		if (len == 0) {
//			return 0;
//		}
//		int start = 0;
//		while (start < len-1) {
//			//cout << findIndex(start + 1, nums, nums[start]) << endl;
//			int retIndex = findIndex(start + 1, nums, nums[start]);
//			if ((retIndex != 0) && (retIndex - start) <= nums[start]) {
//				start = retIndex;
//				jumpNumber++;
//			}
//			else
//			{
//				if ((nums[start] + start) < (len - 1)) {
//					start = nums[start] + start;
//					jumpNumber++;
//				}
//				else
//				{
//					start = len - 1;
//					jumpNumber++;
//				}
//				
//			}
//
//		}
//		//if (start == len - 1) {
//		//	return jumpNumber;
//		//}
//		return jumpNumber;
//	}
//
//	int findIndex(int start, vector<int>& nums, int target) {
//		bool isFind = false;
//		int ret = 0;
//		for (int i = start; i < nums.size(); i++) {
//			if (nums[i] > target) {
//				isFind = true;
//				ret = i;
//				break;
//			}
//		}
//		if (isFind) {
//			return ret;
//		}
//		return ret;
//	}
//};

class Solution {
public:
	int jump(vector<int>& nums) {
		int steps = 0;
		int start = 0;
		int end = 0;
		while (end < nums.size() - 1) {
			int max = end;
			for (int i = start; i <= end; i++) {
				if (nums[i] + i > max) {
					max = nums[i] + i;
				}
			}
			start = end + 1;
			end = max;
			steps++;
		}
		return steps;
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> nums = { 4,6,2,1,1,3,4,5,1,1,3,2,4 };
	cout << "-----" << solution->jump(nums);
	return 0;
}