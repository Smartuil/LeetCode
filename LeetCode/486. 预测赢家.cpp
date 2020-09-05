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
	//dp[i][j] ��ʾ������ʣ�µĲ���Ϊ�±� i ���±� j ʱ����ǰ�������һ����ҵķ���֮������ֵ��ע�⵱ǰ��Ҳ�һ�������֡�
public:
	bool PredictTheWinner(vector<int>& nums) {
		int length = nums.size();
		auto dp = vector<vector<int>>(length, vector<int>(length));
		for (int i = 0; i < length; i++) {
			dp[i][i] = nums[i];
		}
		for (int i = length - 2; i >= 0; i--) {
			for (int j = i + 1; j < length; j++) {
				dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
			}
		}
		return dp[0][length - 1] >= 0;
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> nums = { 1,5,2 };
	cout << solution->PredictTheWinner(nums);
	return 0;
}