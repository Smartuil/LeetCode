#include "iostream"
#include "vector"
#include <map>
#include <set>
#include <queue>
#include <stdlib.h>
using namespace std;

//class Solution {
//public:
//	vector<int> getLeastNumbers(vector<int>& arr, int k) {
//		vector<int> ret;
//		vector<int> tmp(arr.size(), 0);
//		int i = 0;
//		while (i < k) {
//			ret.push_back(arr[i]);
//			tmp[i] = 1;
//			i++;
//		}
//
//		for (i = 0; i < arr.size(); i++) {
//			for (int j = 0; j < ret.size(); j++) {
//				if (arr[i] < ret[j] && tmp[i] != 1) {
//					swap(arr[i], ret[j]);
//				}
//			}
//		}
//
//		return ret;
//	}
//};

//class Solution {
//public:
//	vector<int> getLeastNumbers(vector<int>& arr, int k) {
//		vector<int> vec(k, 0);
//		sort(arr.begin(), arr.end());
//		for (int i = 0; i < k; ++i) vec[i] = arr[i];
//		return vec;
//	}
//};

//class Solution {
//public:
//	vector<int> getLeastNumbers(vector<int>& arr, int k) {
//		vector<int>vec(k, 0);
//		if (k == 0) return vec; // 排除 0 的情况
//		priority_queue<int>Q;//构造一个空的优先队列（此优先队列默认为大顶堆）
//		for (int i = 0; i < k; ++i) 
//			Q.push(arr[i]);
//		for (int i = k; i < (int)arr.size(); ++i) {
//			if (Q.top() > arr[i]) {
//				Q.pop();
//				Q.push(arr[i]);
//			}
//		}
//		for (int i = 0; i < k; ++i) {
//			vec[i] = Q.top();
//			Q.pop();
//		}
//		return vec;
//	}
//};

class Solution {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		int n = arr.size();
		if (n == k) return arr;
		if (n < k || k <= 0 || n == 0) return vector<int>();
		int l = 0, r = n - 1;
		int index = partition(arr, l, r);
		while (index != k - 1) {
			if (index > k - 1) r = index - 1;
			else l = index + 1;
			index = partition(arr, l, r);
		}
		return vector<int>(arr.begin(), arr.begin() + k);
	}

	int partition(vector<int>&arr, int l, int r) {
		int key = arr[l];
		while (l < r) {
			while (l < r && arr[r] >= key) r--;
			arr[l] = arr[r];
			while (l < r && arr[l] <= key) l++;
			arr[r] = arr[l];
		}
		arr[l] = key;
		return l;
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> nums = { 0,0,1,2,4,2,2,3,1,4 };
	vector<int> ret = solution->getLeastNumbers(nums, 8);
	for (auto i : ret) {
		cout << i << endl;
	}
	return 0;
}