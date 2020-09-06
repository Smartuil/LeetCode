#include "iostream"
#include "vector"
#include "algorithm"
#include <queue>
using namespace std;

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		//int index = nums.size() - 1;
		//while (k > 0) {
		//	int tmp = nums[index];
		//	for (int i = nums.size() - 1; i > 0; --i) {
		//		nums[i] = nums[i - 1];
		//	}
		//	nums[0] = tmp;
		//	k--;
		//}
		k = k % nums.size();
		int count = 0;
		for (int start = 0; count < nums.size(); start++) {
			int current = start;
			int prev = nums[start];
			do {
				int next = (current + k) % nums.size();
				int temp = nums[next];
				nums[next] = prev;
				prev = temp;
				current = next;
				count++;
			} while (start != current);
		}
	}
};

int main() {
	Solution* solution = new Solution();
	vector<int> nums = { 1,2,3,4,5,6 };
	int k = 2;
	solution->rotate(nums, k);
	for (auto i : nums) {
		cout << i << endl;
	}
	return 0;
}