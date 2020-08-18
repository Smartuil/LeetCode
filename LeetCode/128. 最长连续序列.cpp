#include "iostream"
#include <sstream>
#include "vector"
#include <set>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <deque>
using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_set<int> num_set;
		for (const int& num : nums) {
			num_set.insert(num);
		}

		int longestStreak = 0;
		int countStreak = 0;
		int currentNum = 0;
		for (int num : nums) {
			if (!num_set.count(num - 1)) {
				currentNum = num;
				countStreak = 1;
				while (num_set.count(currentNum + 1)) {
					countStreak += 1;
					currentNum += 1;
				}
			}
			longestStreak = max(longestStreak, countStreak);
		}
		return longestStreak;
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> nums = { 100, 4, 200, 1, 3, 2 };
	cout << solution->longestConsecutive(nums);
	return 0;
}