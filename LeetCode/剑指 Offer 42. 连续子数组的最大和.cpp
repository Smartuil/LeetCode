#include "iostream"
#include "vector"
#include <map>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
	//int maxSubArray(vector<int>& nums) {
	//	int max = INT_MIN;
	//	int numsSize = int(nums.size());
	//	for (int i = 0; i < numsSize; i++)
	//	{
	//		int sum = 0;
	//		for (int j = i; j < numsSize; j++)
	//		{
	//			sum += nums[j];
	//			if (sum > max)
	//			{
	//				max = sum;
	//			}
	//		}
	//	}

	//	return max;
	//}
	int maxSubArray1(vector<int>& nums) {
		int ret = INT_MIN;
		int numsSize = int(nums.size());
		int sum = 0;
		for (int i = 0; i < numsSize; i++)
		{
			sum += nums[i];
			ret = std::max(ret, sum);
			if (sum < 0) {//Ã»ÓÐ¹±Ï×Öµ£¬ÉáÆú
				sum = 0;
			}
		}

		return ret;
	}

	int maxSubArray(vector<int>& nums) {
		int ret = nums[0];
		int n = nums.size();
		for (int i = 1; i < n; ++i) {
			nums[i] += max(nums[i - 1], 0);
			ret = max(nums[i], ret);
		}

		return ret;
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
	cout << solution->maxSubArray(nums);
	return 0;
}