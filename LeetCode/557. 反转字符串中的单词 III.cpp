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
	string reverseWords(string s) {
		if (s.empty()) {
			return "";
		}
		string ret;
		reverse(s.begin(), s.end());
		int i = s.size() - 1, j = i;
		while (i >= 0) {
			while (i >= 0 && s[i] != ' ') {
				--i;
			}
			ret.append(s.substr(i + 1, j - i)).append(" ");
			while (i >= 0 && s[i] == ' ') {
				--i;
			}
			j = i;
		}
		ret.substr(0, s.size() - 1);
		return ret;
	}
};

int main() {
	Solution *solution = new Solution();
	cout << solution->reverseWords("Let's take LeetCode contest");
	return 0;
}