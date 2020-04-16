#include "iostream"
#include "vector"
#include "windows.h"
#include "stack"
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
	
	//1
	//int trap(vector<int>& height)
	//{
	//	int ans = 0;
	//	int size = height.size();
	//	for (int i = 1; i < size - 1; i++) {
	//		int max_left = 0, max_right = 0;
	//		for (int j = i; j >= 0; j--) { //Search the left part for max bar size
	//			max_left = max(max_left, height[j]);
	//		}
	//		for (int j = i; j < size; j++) { //Search the right part for max bar size
	//			max_right = max(max_right, height[j]);
	//		}
	//		ans += min(max_left, max_right) - height[i];
	//	}
	//	return ans;
	//}

	//2
	//int trap(vector<int>& height)
	//{
	//	if (height.size() == 0)
	//		return 0;
	//	int ans = 0;
	//	int size = height.size();
	//	vector<int> left_max(size), right_max(size);
	//	left_max[0] = height[0];
	//	for (int i = 1; i < size; i++) {
	//		left_max[i] = max(height[i], left_max[i - 1]);
	//	}
	//	right_max[size - 1] = height[size - 1];
	//	for (int i = size - 2; i >= 0; i--) {
	//		right_max[i] = max(height[i], right_max[i + 1]);
	//	}
	//	for (int i = 1; i < size - 1; i++) {
	//		ans += min(left_max[i], right_max[i]) - height[i];
	//	}
	//	return ans;
	//}

	//3
	//int trap(vector<int>& height)
	//{
	//	int ans = 0, current = 0;
	//	stack<int> st;
	//	while (current < height.size()) {
	//		while (!st.empty() && height[current] > height[st.top()]) {
	//			int top = st.top();
	//			st.pop();
	//			if (st.empty())
	//				break;
	//			int distance = current - st.top() - 1;
	//			int bounded_height = min(height[current], height[st.top()]) - height[top];
	//			ans += distance * bounded_height;
	//		}
	//		st.push(current++);
	//	}
	//	return ans;
	//}

	//4
	int trap(vector<int>& height)
	{
		int left = 0, right = height.size() - 1;
		int ans = 0;
		int left_max = 0, right_max = 0;
		while (left < right) {
			if (height[left] < height[right]) {
				height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
				++left;
			}
			else {
				height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
				--right;
			}
		}
		return ans;
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> nums = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	cout << solution->trap(nums);
	return 0;
}