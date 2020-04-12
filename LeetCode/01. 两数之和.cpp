#include "iostream"
#include <vector>
using namespace std;


class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		for (int i = 0; i <= nums.size(); i++) {
			for (int j = 1; j <= nums.size() - 1; j++) {
				if ((nums[i] + nums[j]) == target || j > i) {
					return{ i,j };
				}
			}
		}
		return {1};
	}
	
};

int main() {
	Solution *solution = new Solution();
	vector<int> a = { 3,3 };
	cout<<solution->twoSum(a, 6)[0]<< solution->twoSum(a, 6)[1];
	return 0;
}