#include "iostream"
#include "string"
#include "windows.h"
#include "stack"
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		int maxlen = 0;
		for (int i = 0; i < s.size(); i++) {
			for (int j = 2; j <= s.size(); j += 2) {
				if ((i + j) > s.size()) {
					break;
				}
				if (isValid(s.substr(i, j))) {
					maxlen = max(maxlen, j);
				}
			}
		}
		return maxlen;
	}

	bool isValid(string s) {
		stack<char> m_stack;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				m_stack.push('(');
			}
			else if (!m_stack.empty() && m_stack.top() == '(') {
				m_stack.pop();
			}
			else {
				return false;
			}
		}
		return m_stack.empty();
	}
};

int main() {
	Solution *solution = new Solution();
	cout << solution->longestValidParentheses("()(()");
	return 0;
}