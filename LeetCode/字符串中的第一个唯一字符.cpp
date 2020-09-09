#include "iostream"
#include "vector"
#include "algorithm"
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// class Solution {
// public:
// 	int firstUniqChar(string s) {
// 		for (int i = 0; i < s.size(); i++) {
// 			if (s.find(s[i]) == s.rfind(s[i]))
// 				return i;
// 		}
// 		return -1;
// 	}
// };

class Solution {
public:
	int firstUniqChar(string s) {
		unordered_map<char, int> m;
		for (char c : s) m[c] ++;
		for (int i = 0; i < s.size(); i++)
			if (m[s[i]] == 1) return i;
		return -1;
	}
};

int main() {
	Solution* solution = new Solution();
	string s = "leetcode";
	cout << solution->firstUniqChar(s);
	return 0;
}