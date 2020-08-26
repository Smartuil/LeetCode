#include "iostream"
#include "string"
#include <unordered_map>
using namespace std;

class Solution {
public:
	string replaceSpaces(string S, int length) {
		S = S.substr(0, length);
		string ret;
		for (char c : S) {
			if (c == ' ') {
				ret.push_back('%');
				ret.push_back('2');
				ret.push_back('0');
			}
			else
			{
				ret.push_back(c);
			}
		}
		return ret;
	}
};

int main() {
	Solution *solution = new Solution();
	cout << solution->replaceSpaces("Mr John Smith    ", 13);
	return 0;
}