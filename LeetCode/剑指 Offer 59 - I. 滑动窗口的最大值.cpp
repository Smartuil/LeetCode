#include "iostream"
#include <sstream>
#include "vector"
#include <set>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <deque>
using namespace std;

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		//if (nums.size() == 0) {
		//	return { };
		//}
		//int i = 0;
		//int j = i + k;
		//int n;
		//vector<int> tmp;
		//vector<int> ret;
		//while (j<=nums.size()) {
		//	tmp.clear();
		//	n = 0;
		//	while(n<k){
		//		tmp.push_back(nums[i+n]);
		//		n++;
		//	}

		//	sort(tmp.begin(), tmp.end());
		//	ret.push_back(tmp.back());
		//	i++;
		//	j = i + k;
		//}
		//return ret;

		if (nums.size() == 0 || k == 0) {
			return {};
		}
		deque<int> q;
		vector<int> res(nums.size() - k + 1);
		//for (int i = 0; i < k; i++) {// 未形成窗口
		//	while (!q.empty() && q.back() < nums[i]) {
		//		q.pop_back();
		//	}
		//	q.push_back(nums[i]);
		//}
		//res[0] = q.front();
		//for (int i = k; i < nums.size(); i++) {
		//	if (q.front() == nums[i - k]) {
		//		q.pop_front();//滑动窗口后移，将第一个元素移除
		//	}
		//	while (!q.empty() && q.back() < nums[i]) {//以保持 deque 递减
		//		q.pop_back();
		//	}
		//	q.push_back(nums[i]);
		//	res[i - k + 1] = q.front();
		//}

		for (int i = 0; i < k; ++i) {
			while (!q.empty() && q.back() < nums[i]) {
				q.pop_back();
			}
			q.push_back(nums[i]);
		}
		res[0] = q.front();
		for (int i = k; i < nums.size(); ++i) {
			if (nums[i - k] == q.front()) {
				q.pop_front();
			}
			while (!q.empty() && q.back() < nums[i]) {
				q.pop_back();
			}
			q.push_back(nums[i]);
			res[i - k + 1] = q.front();
		}
		return res;


	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> nums = { 1,3,-1,-3,5,3,6,7 };
	vector<int> ret = solution->maxSlidingWindow(nums, 3);
	for (auto i : ret) {
		cout << i << " ";
	}
	return 0;
}