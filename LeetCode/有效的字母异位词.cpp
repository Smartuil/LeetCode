#include "iostream"
#include "vector"
#include "algorithm"
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.size() != t.size()) {
			return false;
		}
		unordered_map<char, int> m1;
		unordered_map<char, int> m2;
		for (int i = 0; i < s.size(); ++i) {
			m1[s[i]]++;
			m2[t[i]]++;
		}
		if (m1 == m2) {
			return true;
		}
		else
		{
			return false;
		}
	}
};

int main() {
	Solution* solution = new Solution();
	string s = "anagram";
	string t = "nagarabm";
	cout << solution->isAnagram(s, t);
	return 0;
}