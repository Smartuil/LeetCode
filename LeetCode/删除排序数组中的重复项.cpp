#include "iostream"
#include "vector"
#include <algorithm>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0) {
			return 0;
		}

		int j = 0;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[j] != nums[i]) {
				j++;
				nums[j] = nums[i];
				
			}
		}
		return j + 1;
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> board = { 0,0,1,1,1,2,2,3,3,4 };

	cout << solution->removeDuplicates(board);
	return 0;
}