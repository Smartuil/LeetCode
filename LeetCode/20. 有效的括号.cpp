#include "iostream"
#include "string"
#include "stack"
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> m_stack;
		m_stack.push('#');
		if (m_stack.empty()) {
			return true;
		}
		char c[150];
		c['('] = ')';
		c['{'] = '}';
		c['['] = ']';
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
				m_stack.push(s[i]);
			}
			else if (c[m_stack.top()] == s[i]) {
				m_stack.pop();
			}
			else
			{
				return false;
			}
		}
		if (m_stack.top() == '#') {
			return true;
		}
		return false;
	}
};

int main() {
	Solution *solution = new Solution();
	cout << solution->isValid("()[]{}");
	return 0;
}