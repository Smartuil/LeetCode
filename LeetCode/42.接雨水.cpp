#include "iostream"
#include "vector"
#include "windows.h"
using namespace std;

class Solution {
public:
	//int trap(vector<int>& height) {
	//	if (height.size() == 0 && height.size() == 1) {
	//		return 0;
	//	}
	//	int max = 0;
	//	int cap = 0;
	//	int tmp = 0;
	//	int j = 0;
	//	while (j < height.size()) {
	//		if (height[j] == 0 && j == 0) {
	//			j++;
	//			continue;
	//		}
	//		int k = j + 1;
	//		while (k < height.size()) {
	//			if (height[j] <= height[k]) {
	//				int h = min(height[j], height[k]);
	//				int tmp = h * (k - j - 1);
	//				int left = j, right = k;
	//				while (left < right - 1) {
	//					if (height[left + 1] != 0) {
	//						tmp -= height[left + 1];
	//					}
	//					left++;
	//				}
	//				cap += tmp;
	//			}
	//			if (height[j] > height[k]) {
	//				k++;
	//			}
	//			else
	//			{
	//				j = k;
	//				k = j + 1;
	//			}
	//		}
	//		if (j < height.size()) {//越过最高点时会有遗漏
	//			j++;
	//		}
	//	}
	//	return cap;
	//}

	int trap(vector<int>& height)
	{
		int ans = 0;
		int size = height.size();
		for (int i = 1; i < size - 1; i++) {
			int max_left = 0, max_right = 0;
			for (int j = i; j >= 0; j--) { //Search the left part for max bar size
				max_left = max(max_left, height[j]);
			}
			for (int j = i; j < size; j++) { //Search the right part for max bar size
				max_right = max(max_right, height[j]);
			}
			ans += min(max_left, max_right) - height[i];
		}
		return ans;
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> nums = { 4,2,3 };
	cout << solution->trap(nums);
	return 0;
}