#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int len1 = nums1.size();
		int len2 = nums2.size();
		vector<int> com;
		int i = 0, j = 0;
		while (!nums1.empty() && !nums2.empty()) {
			if (nums1[i] < nums2[j]) {
				com.push_back(nums1[i]);
				del(nums1, nums1[i]);
			}
			else if (nums1[i] > nums2[j]) {
				com.push_back(nums2[j]);
				del(nums2, nums2[j]);
			}
			else
			{
				com.push_back(nums1[i]);
				del(nums1, nums1[i]);
			}
		}
		if (!nums1.empty()) {
			while (i < nums1.size())
			{
				com.push_back(nums1[i]);
				i++;
			}
		}
		if (!nums2.empty()) {
			while (j < nums2.size())
			{
				com.push_back(nums2[j]);
				j++;
			}
		}
		int len3 = com.size();
		if (len3 % 2 == 0) {
			return (com[len3 / 2] + com[len3 / 2 - 1]) / 2.0;
		}
		else
		{
			return com[len3 / 2];
		}
	}

	void del(vector<int>& num, int k) {
		for (auto iter = num.begin(); iter != num.end(); iter++) {
			if (*iter == k) {
				num.erase(iter);
				break;
			}
		}
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> nums1 = { 1,2 };
	vector<int> nums2 = { 3,4 };
	cout << solution->findMedianSortedArrays(nums1, nums2);
	return 0;
}