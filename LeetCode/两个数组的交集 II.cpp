#include "iostream"
#include "vector"
#include "algorithm"
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
	//vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
	//	sort(nums1.begin(), nums1.end());
	//	sort(nums2.begin(), nums2.end());
	//	int len1 = nums1.size(), len2 = nums2.size();
	//	vector<int> ret;
	//	int i = 0, j = 0;
	//	while (i < len1&&j < len2) {
	//		if (nums1[i] == nums2[j]) {
	//			ret.push_back(nums1[i]);
	//			i++;
	//			j++;
	//		}
	//		else if (nums1[i] > nums2[j]) {
	//			j++;
	//		}
	//		else {
	//			i++;
	//		}
	//	}
	//	return ret;
	//}

	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> ret;
		unordered_map<int, int> m;
		if (nums1.size() > nums2.size()) {
			return intersect(nums2, nums1);
		}
		for (int i : nums1) {
			m[i]++;
		}
		for (int i : nums2) {
			if (m.count(i)) {
				ret.push_back(i);
				m[i]--;
				if (m[i] == 0) {
					m.erase(i);
				}
			}
		}
		return ret;
	}
};

int main() {
	Solution* solution = new Solution();
	vector<int> nums1 = { 1,2,2,1 };
	vector<int> nums2 = { 2,2 };
	vector<int> ret = solution->intersect(nums1, nums2);
	for(auto i:ret) {
		cout << i << " ";
	}
	return 0;
}