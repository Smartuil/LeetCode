#include "iostream"
#include "vector"
#include "map"

using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		if (nums.size() == 1 && nums[0] == INT_MAX) {
			return 1;
		}
		int ret = 1;
		int min = INT_MAX;
		int max = 0;
		
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > max) {
				max = nums[i];
			}
		}
		////tmp.resize(max);
		//vector<int> tmp(max);//≥ı ºªØ ß∞‹
		//for (int i = 0; i < nums.size(); i++) {
		//	if (nums[i] > 0) {
		//		tmp[nums[i]-1] = 1;
		//	}
		//}

		map<int, int> tmp;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > 0) {
				tmp.insert(make_pair(nums[i], 1));
			}
		}
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] < min && nums[i] > 0) {
				min = nums[i];
			}
		}

		while(ret <= max) {
			auto iter = tmp.find(ret);
			if (iter != tmp.end()) {
				if (iter->second == 1) {
					ret++;
				}
			}
			else
			{
				return ret;
			}
		}
		return ret;
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> nums = { 7,8,9,11,12 };
	cout << solution->firstMissingPositive(nums);
	return 0;
}