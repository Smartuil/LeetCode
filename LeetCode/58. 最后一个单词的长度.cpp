#include "iostream"
#include "vector"
#include <algorithm>
using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		if (s.size() == 0) {
			return 0;
		}
		int index = s.rfind(' ');
		string ret;
		bool insert = false;
		if (index+1 == s.size()) {
			while (index > 0) {
				if (s[index - 1] != ' ') {
					ret.push_back(s[index - 1]);
					insert = true;				
				}
				if (insert == true && s[index - 1] == ' ') {
					return ret.size();
				}
				index--;
			}
			return ret.size();
		}
		
		while (s[index++ + 1]) {
			ret.push_back(s[index + 1]);
		}
		return ret.size();
	}
};

int main() {
	Solution *solution = new Solution;
	string s= "      ";
	cout << solution->lengthOfLastWord(s);
	return 0;
}