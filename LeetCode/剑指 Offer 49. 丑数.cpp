#include "iostream"
#include "vector"
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
	int nthUglyNumber(int n) {
		int a = 0, b = 0, c = 0;
		vector<int> dp(n);
		dp[0] = 1;
		for (int i = 1; i < n; i++) {
			int n2 = dp[a] * 2, n3 = dp[b] * 3, n5 = dp[c] * 5;
			dp[i] = min(min(n2, n3), n5);
			if (dp[i] == n2)a++;
			if (dp[i] == n3)b++;
			if (dp[i] == n5)c++;
		}
		return dp[n - 1];
	}
};

int main() {
	Solution *solution = new Solution();
	cout << solution->nthUglyNumber(10);
	return 0;
}