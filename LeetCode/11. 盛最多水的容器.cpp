#include "iostream"
#include "windows.h"
#include "vector"
using namespace std;

//class Solution {
//public:
//	int maxArea(vector<int>& height) {
//		int area = 0;
//		for (int i = 0; i < height.size(); i++) {
//			for (int j = i + 1; j < height.size(); j++) {
//				int tmp = (j - i)*min(height[i], height[j]);
//				if (tmp > area) {
//					area = tmp;
//				}
//			}
//		}
//		return area;
//	}
//};

class Solution {
public:
	int maxArea(vector<int>& height) {
		int maxarea = 0, l = 0, r = height.size() - 1;
		while (l < r) {
			maxarea = max(maxarea, min(height[l], height[r]) * (r - l));
			if (height[l] < height[r])
				l++;
			else
				r--;
		}
		return maxarea;
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> height = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	cout << solution->maxArea(height);
	return 0;
}