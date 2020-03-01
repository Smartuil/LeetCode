#include "iostream"
#include "string"
using namespace std;


class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int len = 0;
		int tmp = 0;
		string current_s;
		for (int i = 0; i < s.length(); i++) {
			current_s = s[i];
			if (i == s.length() - 1) {
				tmp = 1;
				break;
			}
			for (int j = i + 1; j <= s.length(); j++) {
				if (j == s.length()) {
					break;
				}
				string::size_type idx = current_s.find(s[j]);
				if (idx == string::npos) {
					tmp = j - i + 1;
					if (tmp > len) {
						len = tmp;
					}
					current_s += s[j];
				}
				else {
					tmp = 1;
					break;
				}
			}
		}
		return tmp > len ? tmp : len;
	}
};

void main() {
	Solution *solution = new Solution();
	string s = "pwwkew";
	int len = solution->lengthOfLongestSubstring(s);
	cout << len;
}