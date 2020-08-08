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
	char firstUniqChar(string s) {
		if (s.size() == 0) {
			return ' ';
		}

		map<char, int> m;
		for (int i = 0; i < s.size(); i++) {
			m[s[i]]++;
		}
		for (int i = 0; i < s.size(); i++) {
			if (m[s[i]] == 1) {
				return s[i];
			}
		}
		return ' ';
	}
};

int main() {
	Solution *solution = new Solution();
	cout << solution->firstUniqChar("abaccdeff");
	return 0;
}