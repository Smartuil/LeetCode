#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		int res = 1;
		int flag = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] == flag)
				nums[i] = INT_MAX;
			else
			{
				flag = nums[i];
			}

		}
		nums.erase(remove(nums.begin(), nums.end(), INT_MAX), nums.end());
		return nums.size();
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> nums = {1, 1, 2};
	int len = solution->removeDuplicates(nums);
	for (int i = 0; i < len; i++) {
		cout << nums[i];
	}
	return 0;
}