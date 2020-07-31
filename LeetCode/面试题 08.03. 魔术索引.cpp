#include "iostream"
#include "string"
#include "vector"
#include <Windows.h>
using namespace std;

class Solution {
public:
	int findMagicIndex(vector<int>& nums) {
		int ret = 0;
		vector<int> tmp(nums.size(), 0);
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == i) {
				return i;
			}
		}
		return -1;
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> nums = { 1,1,1};
	cout << solution->findMagicIndex(nums);
	return 0;
}