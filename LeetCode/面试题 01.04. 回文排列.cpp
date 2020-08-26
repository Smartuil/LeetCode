#include "iostream"
#include "string"
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool canPermutePalindrome(string s) {
		unordered_map<char, int> m;
		for (auto c : s) {
			m[c]++;
		}
		int cnt = 0;
		for (auto i : m) {
			if (i.second % 2 == 1) ++cnt;
		}
		return cnt <= 1;
	}
};

class Solution {
public:
	bool canPermutePalindrome(string s) {
		vector<int> hash(256, 0);
		for (auto c : s) {
			++hash[c];
		}
		int cnt = 0;
		for (int i = 0; i < hash.size(); ++i) {
			if (hash[i] % 2 == 1) ++cnt;
		}
		return cnt <= 1;
	}
};

int main() {
	Solution *solution = new Solution();
	cout << solution->canPermutePalindrome("aab");
	return 0;
}