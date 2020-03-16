#include "iostream"
#include "vector"
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<string> word = { " ","*", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
	vector<string> ret;
	vector<string> letterCombinations(string digits) {
		if (digits == "" || digits.size() == 0) {
			return {};
		}
		backtrack(digits, "", 0);
		return ret;
	}

	void backtrack(string digits, string letter, int index) {
		if (index == digits.size()) {
			ret.push_back(letter);
			return;
		}
		char c = digits.at(index);
		int pos = c - '0';
		string word_ = word[pos];
		for (int i = 0; i < word_.size(); i++) {
			backtrack(digits, letter + word_.at(i), index + 1);
		}
	}
};

int main() {
	Solution *solution = new Solution();
	vector<string> ret = solution->letterCombinations("23");
	for (auto tmp : ret) {
		cout << tmp.c_str() << endl;
	}
	return 0;
}