#include "iostream"
#include "vector"
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
	string letters = "abcdefghijklmnopqrstuvwxyz";
	bool canConvertString(string s, string t, int k) {
		int count = 0;
		while (count < k) {
			for (int i = 0; i < s.size(); i++) {
				if (s[i] != t[i]) {
					int index = letters.find(s[i]);
					s[i] = letters[(index + 1)%25];
				}
			}
			count++;
		}
		if (s == t) {
			return true;
		}
		else
		{
			return false;
		}
		
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> arr = { 1,13,18 };
	cout << solution->canConvertString("abc", "bcd", 10);
	return 0;
}