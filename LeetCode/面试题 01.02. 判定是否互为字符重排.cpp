#include "iostream"
#include "string"
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool CheckPermutation(string s1, string s2) {
		unordered_map<char, int>m1;
		unordered_map<char, int>m2;
		for (char c : s1) {
			m1[c]++;
		}
		for (char c : s2) {
			m2[c]++;
		}
		string s = s1.size() > s2.size() ? s1 : s2;
		for (char c : s) {
			if (m1[c] != m2[c]) {
				return false;
			}
		}
		return true;
	}
};

int main() {
	Solution *solution = new Solution();
	cout << solution->CheckPermutation("a", "ad");
	return 0;
}