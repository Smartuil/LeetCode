#include "iostream"
#include "string"
#include "vector"

using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> ret;
		string tmp;
		tmp.resize(2 * n);
		generateAll(tmp, 0, ret);
		return ret;
	}

	void generateAll(string current, int pos, vector<string> &result) {
		if (pos == current.size()) {
			if (valid(current)) {
				result.push_back(current);
			}
		}
		else
		{
			current[pos] = '(';
			generateAll(current, pos + 1, result);
			current[pos] = ')';
			generateAll(current, pos + 1, result);
		}
	}

	bool valid(string current) {
		int balance = 0;
		for (char c : current) {
			if (c == '(')balance++;
			else balance--;
			if (balance < 0)return false;
		}
		return (balance == 0);
	}
};

int main() {
	Solution *solution = new Solution();
	vector<string> ret = solution->generateParenthesis(1);
	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << endl;
	}
	return 0;
}