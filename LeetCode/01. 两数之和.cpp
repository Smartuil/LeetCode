#include "iostream"
#include <vector>
#include <unordered_map>
using namespace std;


//class Solution {
//public:
//	vector<int> twoSum(vector<int>& nums, int target) {
//		for (int i = 0; i <= nums.size(); i++) {
//			for (int j = 1; j <= nums.size() - 1; j++) {
//				if ((nums[i] + nums[j]) == target || j > i) {
//					return{ i,j };
//				}
//			}
//		}
//		return {1};
//	}
//	
//};

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ans;
		unordered_map<int, int>hashmap;
		for (int i = 0; i < nums.size(); i++) {
			if (hashmap[target - nums[i]] && hashmap[target - nums[i]] != i + 1) {
				//防止利用同个元素
				ans.push_back(i);
				ans.push_back(hashmap[target - nums[i]] - 1);
				return ans;
			}
			hashmap[nums[i]] = i + 1;
			//将hash表对应下标＋1，防止处理下标为0的情况
		}

		return ans;
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> a = { 2, 7, 11, 15 };
	cout<<solution->twoSum(a, 9)[0]<< solution->twoSum(a, 9)[1];
	return 0;
}