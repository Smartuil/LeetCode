#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include <queue>
using namespace std;

class Solution {
private:
	vector<int> data;
public:
	Solution(vector<int>& nums) {
		data = nums;
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return data;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		vector<int> res(data);
		for (int i = 0; i < res.size(); i++)
		{
			swap(res[i], res[rand() % (i + 1)]);
		}
		return res;
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

int main() {
	vector<int> nums = { 1,2,3 };
	Solution *solution = new Solution(nums);
	vector<int> param_1 = solution->reset();
	vector<int> param_2 = solution->shuffle();
	return 0;
}