#include "iostream"
#include "vector"
#include <algorithm>

using namespace std;

class Solution {
public:
	int findLength(vector<int>& A, vector<int>& B) {
		//int lenA = A.size();
		//int lenB = B.size();
		//int ret = 0;
		//for (int i = 0; i < lenA; ++i) {
		//	for (int j = 0; j < lenB; ++j) {
		//		if (A[i] == B[j]) {
		//			int subLen = 1;
		//			while (i + subLen < lenA && j + subLen < lenB && A[i + subLen] == B[j + subLen]) {
		//				subLen++;
		//			}
		//			ret = max(subLen, ret);
		//		}
		//	}
		//}
		//return ret;

		int lenA = A.size();
		int lenB = B.size();
		int ret = 0;
		vector<vector<int>> dp(lenA+1, vector<int>(lenB+1, 0));
		for (int i = 0; i < lenA; ++i) {
			for (int j = 0; j < lenB;  ++j) {
				if (A[i] == B[j]) {
					dp[i+1][j+1] = dp[i][j] + 1;
				}
				ret = max(ret, dp[i+1][j+1]);
			}
		}
		return ret;
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> A = { 1,2,3,2,1 };
	vector<int> B = { 3,2,1,4,7 };
	cout << solution->findLength(A, B);
	return 0;
}
