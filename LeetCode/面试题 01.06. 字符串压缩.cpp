#include "iostream"
#include <sstream>
#include "vector"
#include <set>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <deque>
using namespace std;

class Solution {
public:
	string compressString(string S) {
		int i = 0, j = 0;
		string ret;
		while (j < S.size()) {
			while (S[i] == S[j]) {
				j++;
			}
			ret.push_back(S[i]);
			ret.append(to_string(j - i));
			i = j;
		}
		return ret.size() >= S.size() ? S : ret;
	}
};

int main() {
	Solution *solution = new Solution();
	cout << solution->compressString("abbccd");
	return 0;
}