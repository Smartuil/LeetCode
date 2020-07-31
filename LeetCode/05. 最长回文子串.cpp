#include "iostream"
#include "string"
#include "vector"
#include <Windows.h>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s)
	{
		if (s.length() < 1)
		{
			return "";
		}
		int start = 0, end = 0;
		for (int i = 0; i < s.length(); i++)
		{
			int len1 = expandAroundCenter(s, i, i);
			int len2 = expandAroundCenter(s, i, i + 1);
			int len = max(len1, len2);
			if (len > end - start)
			{
				start = i - (len - 1) / 2;
				end = i + len / 2;
			}
		}
		return s.substr(start, end - start + 1);
	}

	int expandAroundCenter(string s, int left, int right)
	{
		int L = left, R = right;
		while (L >= 0 && R < s.length() && s[L] == s[R])
		{
			L--;
			R++;
		}
		return R - L - 1;
	}
};

//class Solution {
//public:
//	string longestPalindrome(string s) {
//		int n = s.size();
//		vector<vector<int>> dp(n, vector<int>(n));
//		string ans;
//		for (int l = 0; l < n; ++l) {
//			for (int i = 0; i + l < n; ++i) {
//				int j = i + l;
//				if (l == 0) {
//					dp[i][j] = 1;
//				}
//				else if (l == 1) {
//					dp[i][j] = (s[i] == s[j]);
//				}
//				else {
//					dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
//				}
//				if (dp[i][j] && l + 1 > ans.size()) {
//					ans = s.substr(i, l + 1);
//				}
//			}
//		}
//		return ans;
//	}
//};

int main() {
	Solution *solution = new Solution();
	cout << solution->longestPalindrome("asbbsa");
	return 0;
}