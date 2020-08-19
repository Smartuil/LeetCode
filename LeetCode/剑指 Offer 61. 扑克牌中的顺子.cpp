#include "iostream"
#include <sstream>
#include "vector"
#include <set>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <map>
using namespace std;

class Solution {
public:
	//bool isStraight(vector<int>& nums) {
	//	int joker = 0;
	//	sort(nums.begin(), nums.end()); // ��������
	//	for (int i = 0; i < 4; i++) {
	//		if (nums[i] == 0) joker++; // ͳ�ƴ�С������
	//		else if (nums[i] == nums[i + 1]) return false; // �����ظ�����ǰ���� false
	//	}
	//	return nums[4] - nums[joker] < 5; // ����� - ��С�� < 5 ��ɹ���˳��
	//}

	bool isStraight(vector<int>& nums) {
		set<int> s;
		int maxNum = 0, minNum = 14;
		for (int num : nums) {
			if (num == 0) {
				continue;
			}
			maxNum = max(maxNum, num);
			minNum = min(minNum, num);
			if (s.count(num)) return false;
			s.insert(num);
		}
		return maxNum - minNum < 5;
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> nums = { 0,0,1,2,5 };
	cout << solution->isStraight(nums);
	return 0;
}