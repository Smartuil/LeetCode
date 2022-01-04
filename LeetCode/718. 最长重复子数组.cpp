#include "iostream"
#include "vector"
#include <algorithm>

using namespace std;

class Solution {
public:

	//暴力
	int findLength(vector<int>& A, vector<int>& B) {
		int lenA = A.size();
		int lenB = B.size();
		int ret = 0;
		for (int i = 0; i < lenA; ++i) {
			for (int j = 0; j < lenB; ++j) {
				if (A[i] == B[j]) {
					int subLen = 1;
					while (i + subLen < lenA && j + subLen < lenB && A[i + subLen] == B[j + subLen]) {
						subLen++;
					}
					ret = max(subLen, ret);
				}
			}
		}
		return ret;
	}
	 
	//动态规划
	int findLength2(vector<int>& A, vector<int>& B) {
		int lenA = A.size();
		int lenB = B.size();
		int ret = 0;
		vector<vector<int>> dp(lenA + 1, vector<int>(lenB + 1, 0));
		for (int i = 0; i < lenA; ++i) {
			for (int j = 0; j < lenB; ++j) {
				if (A[i] == B[j]) {
					dp[i + 1][j + 1] = dp[i][j] + 1;
				}
				ret = max(ret, dp[i + 1][j + 1]);
			}
		}

		vector<int> dp2(lenA + 1, 0);
		for (int i = 1; i <= lenA; i++) {
			for (int j = lenB; j >= 1; j--) {
				if (A[i - 1] == B[j - 1]) {
					dp2[j] = dp2[j - 1] + 1;
				}
				else {
					dp2[j] = 0;
				}
				ret = max(ret, dp2[j]);
			}
		}

		return ret;
	}

	//滑动窗口
	int maxLength(vector<int>& A, vector<int>& B, int addA, int addB, int len) {
		int ret = 0, k = 0;
		for (int i = 0; i < len; i++) {
			if (A[addA + i] == B[addB + i]) {
				k++;
			}
			else {
				k = 0;
			}
			ret = max(ret, k);
		}
		return ret;
	}
	int findLength3(vector<int>& A, vector<int>& B) {
		int n = A.size(), m = B.size();
		int ret = 0;
		for (int i = 0; i < n; i++) {

			//i = 0
			//1 2 3 2 1
			//3 2 1 4 7

			//i = 1
			//1 2 3 2 1
			//  3 2 1 4 7

			//i = 2
			//1 2 3 2 1
			//	3 2 1 4 7

			//i = 3
			//1 2 3 2 1
			//	  3 2 1 4 7

			//i = 4
			//1 2 3 2 1
			//		3 2 1 4 7
			int len = min(m, n - i);
			int maxlen = maxLength(A, B, i, 0, len);
			ret = max(ret, maxlen);
		}
		for (int i = 0; i < m; i++) {
			int len = min(n, m - i);
			int maxlen = maxLength(A, B, 0, i, len);
			ret = max(ret, maxlen);
		}
		return ret;
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> A = { 1,2,3,2,1 };
	vector<int> B = { 3,2,1,4,7 };
	cout << solution->findLength3(A, B);
	return 0;
}
