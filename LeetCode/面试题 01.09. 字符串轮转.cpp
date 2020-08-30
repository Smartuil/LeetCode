#include "iostream"
#include <sstream>
#include "vector"
#include <set>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <deque>
using namespace std;

//class Solution {
//public:
//	bool isFlipedString(string s1, string s2) {
//		if (s1.empty() && s2.empty()) return true;
//		if (s2.empty()) return false;
//		int i = 0;
//		int j = 0;
//		while (s2[0] != s1[i]) {
//			++i;
//		}
//		string tmp = s1.substr(i);
//		auto index = s2.find_first_not_of(tmp);
//		string s1tmp = s1.substr(0, i);
//		string s2tmp = s2.substr(index == s2.npos ? s2.size() : index);
//
//		return s1tmp == s2tmp;
//	}
//};

class Solution2 {
public:
	bool isFlipedString(string s1, string s2) {
		int m = s1.size(), n = s2.size();
		if (m != n) return false;
		if (m == 0) return true;
		for (int i = 0; i < m; i++) {
			if (s1[i] == s2[0]) {
				if (s1.substr(0, i) == s2.substr(m - i) && s1.substr(i) == s2.substr(0, m - i))
					return true;
			}
		}
		return false;
	}
};

//如果 s2 由 s1 轮转而成，那么 s1 + s1 一定包含 s2
class Solution {
public:
	bool isFlipedString(string s1, string s2) {
		auto index = (s1 + s1).find(s2);
		return s1.size() == s2.size() && (s1 + s1).find(s2) != -1;
	}
};

int main() {
	Solution *solution = new Solution();
	cout << solution->isFlipedString("aa",
		"aba");
	return 0;
}