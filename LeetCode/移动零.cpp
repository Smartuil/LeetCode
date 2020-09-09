#include "iostream"
#include "vector"
#include "algorithm"
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int i = 0, j = 0;
		while ( j < nums.size()) {
			if (nums[j] != 0) {
				swap(nums[i++], nums[j]);
			}
			j++;
		}
	}
};

int main() {
	Solution* solution = new Solution();
	vector<int> nums = { 0,1,0,3,12 };
	solution->moveZeroes(nums);
	for (auto i : nums) {
		cout << i << " ";
	}
	return 0;
}