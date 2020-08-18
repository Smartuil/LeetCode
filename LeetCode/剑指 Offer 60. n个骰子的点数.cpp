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
	//https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof/solution/nge-tou-zi-de-dian-shu-dong-tai-gui-hua-ji-qi-yo-3/
	//vector<double> twoSum(int n) {
	//	int dp[15][70];//全部都是6最大才66
	//	memset(dp, 0, sizeof(dp));
	//	for (int i = 1; i <= 6; i++) {
	//		dp[1][i] = 1;
	//	}
	//	for (int i = 2; i <= n; i++) {
	//		for (int j = i; j <= 6 * i; j++) {
	//			for (int cur = 1; cur <= 6; cur++) {
	//				if (j - cur <= 0) {
	//					break;
	//				}
	//				dp[i][j] += dp[i - 1][j - cur];
	//			}
	//		}
	//	}
	//	int all = pow(6, n);
	//	vector<double> ret;
	//	for (int i = n; i <= 6 * n; i++) {
	//		ret.push_back(dp[n][i] * 1.0 / all);
	//	}
	//	return ret;
	//}

	vector<double> twoSum(int n) {
		vector<vector<int>> dp(15, vector<int>(70, 0));
		for (int i = 1; i <= 6; ++i) {
			dp[1][i] = 1;
		}
		for (int i = 2; i <= n; ++i) {
			for (int j = i; j <= i * 6; ++j) {
				for (int cur = 1; cur <= 6; ++cur) {
					//
					if (j - cur <= 0) {
						break;
					}
					dp[i][j] += dp[i - 1][j - cur];
				}
			}
		}
		int all = pow(6, n);
		vector<double> ret;
		for (int i = n; i <= 6 * n; ++i) {
			ret.push_back((dp[n][i] * 1.0) / all);
		}
		return ret;
	}
};

int main() {
	Solution *solution = new Solution();
	vector<double> ret = solution->twoSum(2);
	for (auto i : ret) {
		cout << i << " ";
	}
	return 0;
}