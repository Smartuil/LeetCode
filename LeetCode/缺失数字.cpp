#include "iostream"
#include "vector"
#include <algorithm>

using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		// �ж� n �Ƿ������ĩλ
		if (nums[nums.size() - 1] != nums.size()) {
			return nums.size();
		}
		// �ж� 0 �Ƿ��������λ
		else if (nums[0] != 0) {
			return 0;
		}

		// ��ʱȱʧ������һ���� (0, n) ��
		for (int i = 1; i < nums.size(); i++) {
			int expectedNum = nums[i - 1] + 1;
			if (nums[i] != expectedNum) {
				return expectedNum;
			}
		}

		// δȱʧ�κ����֣���֤�����з���ֵ��
		return -1;
	}
};

int main() {
	Solution* solution = new Solution();
	vector<int> nums = { 0,1 };
	cout << solution->missingNumber(nums);
	return 0;
}