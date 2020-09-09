#include "iostream"
#include "vector"
#include "algorithm"
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// class Solution {
// public:
// 	bool isPalindrome(string s) {
// 		if (s.size() == 1 || s[0] == ' ' || s.empty()) {
// 			return true;
// 		}
// 		int i = 0;
// 		int j = s.size()-1;
// 
// 		while (i < j) {
// 
// 			while (!isalnum(s[i]) && i < j) {
// 				++i;
// 			}
// 			while (!isalnum(s[j]) && i < j) {
// 				--j;
// 			}
// 			s[i] = tolower(s[i]);
// 			s[j] = tolower(s[j]);
// 			if (i < j) {
// 				if (s[i] != s[j]) {
// 					return false;
// 				}
// 				++i;
// 				--j;
// 			}
// 		}
// 		return false;
// 	}
// };

class Solution {
public:
	bool isPalindrome(string s) {
		int n = s.size();
		int left = 0, right = n - 1;
		while (left < right) {
			while (left < right && !isalnum(s[left])) {
				++left;
			}
			while (left < right && !isalnum(s[right])) {
				--right;
			}
			if (left < right) {
				if (tolower(s[left]) != tolower(s[right])) {
					return false;
				}
				++left;
				--right;
			}
		}
		return true;
	}
};

int main() {
	Solution* solution = new Solution();
	string s = "aaa";
	cout << solution->isPalindrome(s);
	return 0;
}