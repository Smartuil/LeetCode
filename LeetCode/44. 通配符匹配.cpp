#include "iostream"
#include "string"
#include "vector"

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		int sLen = s.size(), pLen = p.size();

		if (p == s || p == "*") {
			return true;
		}
		if (p.empty() || s.empty()) {
			return false;
		}

		vector<vector<bool>> d;
		//d.resize(pLen + 1, sLen + 1);
		d.resize(pLen + 1);
		for (int i = 0; i <= pLen; i++) {
			d[i].resize(sLen + 1);
			for (int j = 0; j <= sLen; j++) {
				d[i][j] = false;
			}
		}
		d[0][0] = true;
		for (int pIdx = 1; pIdx < pLen + 1; pIdx++) {
			if (p[pIdx - 1] == '*') {
				int sIdx = 1;
				while ((!d[pIdx - 1][sIdx - 1]) && (sIdx < sLen + 1)) sIdx++;
				d[pIdx][sIdx - 1] = d[pIdx - 1][sIdx - 1];
				while (sIdx < sLen + 1) d[pIdx][sIdx++] = true;
			}
			else if (p[pIdx - 1] == '?') {
				for (int sIdx = 1; sIdx < sLen + 1; sIdx++)
					d[pIdx][sIdx] = d[pIdx - 1][sIdx - 1];
			}
			else {
				for (int sIdx = 1; sIdx < sLen + 1; sIdx++) {
					d[pIdx][sIdx] = d[pIdx - 1][sIdx - 1] &&
						(p[pIdx - 1] == s[sIdx - 1]);
				}
			}
		}
		return d[pLen][sLen];
	}
};

int main() {
	Solution *solution = new Solution();
	cout << solution->isMatch("aa", "a");
	return 0;
}