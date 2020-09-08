#include "iostream"
#include "vector"
#include "algorithm"
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> s;
		for (int num : nums) {
			if (!s.insert(num).second) {
				return true;
			}
		}
		return false;
	}
};

int main() {
	Solution* solution = new Solution();
	vector<int> nums = { 1,2,3,1 };
	cout << solution->containsDuplicate(nums);
	return 0;
}