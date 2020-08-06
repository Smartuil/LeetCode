#include "iostream"
#include "vector"
#include <map>
#include <set>
using namespace std;

class Solution {
public:
	map<int, int> tmp;
	int majorityElement(vector<int>& nums) {

		for (int i = 0; i < nums.size(); i++) {
			if (tmp.find(nums[i]) != tmp.end()) {
				tmp.insert({ nums[i], tmp[nums[i]]++ });
			}
			else
			{
				tmp.insert({ nums[i], 1 });
			}
			
		}
		for (int i = 0; i < nums.size(); i++) {
			if (tmp[nums[i]] > nums.size() / 2) {
				return nums[i];
			}
		}
		return 0;
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> nums = { 8,8,7,7,7 };
	cout << solution->majorityElement(nums);
	return 0;
}