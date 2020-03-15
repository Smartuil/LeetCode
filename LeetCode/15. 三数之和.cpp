#include "iostream"
#include "vector"
#include <windows.h>
#include <algorithm>
using namespace std;

//class Solution {
//public:
//	vector<vector<int>> threeSum(vector<int>& nums) {
//		vector<vector<int>> ret;
//		vector<int> tmp;
//		int arr[3];
//		if (nums.size() < 3) {
//			return {};
//		}
//		for (int i = 0; i < nums.size(); i++) {
//			if (nums[i] == 0) {
//				if (i == nums.size() - 1) {
//					return { {0, 0, 0} };
//				}
//				continue;
//			}
//			else
//			{
//				break;
//			}
//		}
//		for (int i = 0; i < nums.size(); i++)
//			for (int j = i + 1; j < nums.size(); j++)
//				for (int k = j + 1; k < nums.size(); k++) {
//					if (nums[i] + nums[j] + nums[k] == 0) {
//						tmp.clear();
//						arr[0] = nums[i];
//						arr[1] = nums[j];
//						arr[2] = nums[k];
//						sort(arr, arr+3);
//						tmp.push_back(arr[0]);
//						tmp.push_back(arr[1]);
//						tmp.push_back(arr[2]);
//
//						if (ret.empty()) {
//							ret.push_back(tmp);
//						}
//						else if (findHave(ret, tmp))
//						{
//							ret.push_back(tmp);
//						}
//					}
//				}
//		if (ret.size() > 0)
//			return ret;
//		else
//			return {};
//	}
//
//	bool findHave(vector<vector<int>>& ret, vector<int>& nums) {
//		int count = 0;
//		for (int i = 0; i < ret.size(); i++) {
//			count = 0;
//			for (int j = 0; j < ret[i].size(); j++) {
//				if (nums[j] == ret[i][j]) {
//					count++;
//				}
//			}
//			if (count == 3) {
//				return false;
//			}
//		}
//		return true;
//	}
//};

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ret;
		vector<int> tmp;
		if (nums.size() < 3) {
			return {};
		}
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 0) {
				if (i == nums.size() - 1) {
					return { {0, 0, 0} };
				}
				continue;
			}
			else
			{
				break;
			}
		}
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++) {
			if(nums[i]>0)
				break;
			if(i>0 && nums[i]==nums[i-1])
				continue;
			int L = i + 1;
			int R = nums.size() - 1;
			while (L < R) {
				int sum = nums[i] + nums[L] + nums[R];
				if (sum == 0) {
					tmp.clear();
					tmp.push_back(nums[i]);
					tmp.push_back(nums[L]);
					tmp.push_back(nums[R]);
					ret.push_back(tmp);
					while (L < R && nums[L] == nums[L + 1])L++;
					while (L < R && nums[R] == nums[R - 1])R--;
					L++;
					R--;
				}
				else if (sum < 0)L++;
				else if (sum > 0)R--;
			}
		}
		return ret;
	}
};


int main() {
	Solution *solution = new Solution();
	vector<int> nums = { -1, 0, 1, 2, -1, -4 };
	vector<vector<int>> ret = solution->threeSum(nums);
	for (int i = 0; i < ret.size(); i++) {
		cout << "[";
		for (int j = 0; j < ret[i].size(); j++) {
			cout << ret[i][j] << ", ";
		}
		cout << "]" << endl;

	}
	return 0;
}