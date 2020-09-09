#include "iostream"
#include "vector"
#include "algorithm"
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
	void reverseString(vector<char>& s) {
		int len = s.size();
		int i = 0, j = len - 1;
		while (i < len / 2) {
			swap(s[i++], s[j--]);
		}
	}
};

int main() {
	Solution* solution = new Solution();
	vector<char> s = { 'h','e','l','l','o' };
	solution->reverseString(s);
	for (auto i : s) {
		cout << i << " ";
	}
	return 0;
}