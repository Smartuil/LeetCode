#include "iostream"
#include "vector"
#include <algorithm>
#include "queue"
using namespace std;

class Solution {
public:
	int integerBreak(int n) {
		vector <int> dp(n + 1);
		for (int i = 2; i <= n; i++) {
			int curMax = 0;
			for (int j = 1; j < i; j++) {
				curMax = max(curMax, max(j * (i - j), j * dp[i - j]));
			}
			dp[i] = curMax;
		}
		return dp[n];
	}
};

int main() {
	Solution *solution = new Solution;
	cout << solution->integerBreak(9);

	return 0;
}