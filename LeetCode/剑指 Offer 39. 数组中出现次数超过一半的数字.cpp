#include "iostream"
#include "vector"
#include <map>
#include <set>
using namespace std;

class Solution {
public:
	map<int, int> tmp;
	int majorityElement(vector<int>& nums) {

		/*for (int i = 0; i < nums.size(); i++) {
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
		}*/

		int x = 0, vote = 0;
		for (int num : nums) {
			if (vote == 0) {
				x = num;
			}
			vote += (num == x ? 1 : -1);
		}

		return x;
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> nums = { 1,2,3,2,2,2,5,4,2 };
	cout << solution->majorityElement(nums);
	return 0;
}