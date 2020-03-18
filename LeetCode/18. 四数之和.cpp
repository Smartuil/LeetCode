#include "iostream"
#include "vector"
#include <algorithm>

using namespace std;

//class Solution {
//public:
//	vector<vector<int>> fourSum(vector<int>& nums, int target) {
//		if (nums.size() < 4) {
//			return {};
//		}
//
//		sort(nums.begin(), nums.end());
//		vector<vector<int>> ret;
//		vector<int> tmp;
//		int i = 0;
//		int j = nums.size() - 1;
//		int sum = 0;
//		while (i < j) {
//			int m = i + 1;
//			int n = j - 1;
//			while (m < n) {
//				 sum = nums[i] + nums[j] + nums[m] + nums[n] - target;
//				if (sum == 0) {
//					tmp.clear();
//					tmp.push_back(nums[i]);
//					tmp.push_back(nums[m]);
//					tmp.push_back(nums[n]);
//					tmp.push_back(nums[j]);
//					ret.push_back(tmp);
//					while (m < n &&nums[m] == nums[m + 1]) m++;
//					while (m < n &&nums[n] == nums[n - 1]) n--;
//					m++;
//					n--;
//				}
//				else if (sum < 0)m++;
//				else if (sum > 0)n--;
//			}
//			if (sum < 0)i++;
//			else if (sum > 0)j--;
//			else { i++; j--; }
//		}
//		return ret;
//	}
//};

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		int size = nums.size();
		for (int a = 0; a < size - 3; ++a)
		{
			if (a > 0 && nums[a] == nums[a - 1])continue;
			for (int b = a + 1; b < size - 2; ++b)
			{
				if (b > a + 1 && nums[b] == nums[b - 1])continue;
				int i = b + 1, j = size - 1;
				while (i < j)
				{
					int sum = nums[a] + nums[b] + nums[i] + nums[j];
					if (sum < target)
						//while (i < j&&nums[i] == nums[++i]);
						i++;
					else if (sum > target)
						//while (i < j&&nums[j] == nums[--j]);
						j--;
					else {
						result.push_back(vector<int>{nums[a], nums[b], nums[i], nums[j]});
						while (i < j&&nums[i] == nums[++i]);
						while (i < j&&nums[j] == nums[--j]);
					}
				}
			}
		}
		return result;
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> nums = { -3,-1,0,2,4,5 };
	vector<vector<int>>ret = solution->fourSum(nums, 2);
	cout << "[" << endl;
	for (int i = 0; i < ret.size(); i++) {
		cout << "[";
		for (int j = 0; j < ret[i].size(); j++) {
			cout << ret[i][j] << " ";
		}
		cout << "]" << endl;
	}
	cout << "]";
	return 0;
}