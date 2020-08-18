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

	int missingNumber(vector<int>& nums) {
		//int i = 0;
		//int j = nums.size() - 1;
		//while (i <= j)
		//{
		//	int mid = (i + j) / 2;
		//	if (mid == nums[mid]) {
		//		i = mid + 1;
		//	}
		//	else
		//	{
		//		j = mid - 1;
		//	}
		//}
		//return i;
		int i = 0;
		int j = nums.size() - 1;
		while (i <= j) {
			int mid = (i + j) / 2;
			if (nums[mid] == mid) {
				i = mid + 1;
			}
			else
			{
				j = mid - 1;
			}
		}
		return i;
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> nums = { 0,2 };
	cout << solution->missingNumber(nums);
	return 0;
}