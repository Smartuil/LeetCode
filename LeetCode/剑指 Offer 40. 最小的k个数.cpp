#include "iostream"
#include "vector"
#include <map>
#include <set>
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

class Solution {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		vector<int> vec(k, 0);
		sort(arr.begin(), arr.end());
		for (int i = 0; i < k; ++i) vec[i] = arr[i];
		return vec;
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