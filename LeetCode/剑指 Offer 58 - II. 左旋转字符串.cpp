#include "iostream"
#include <sstream>
#include "vector"
#include <set>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
	string reverseLeftWords(string s, int n) {
		string tmp;
		tmp = s.substr(0, n);
		s.erase(0, n);
		return s + tmp;
	} 
};

int main() {
	Solution *solution = new Solution();
	cout << solution->reverseLeftWords("lrloseumgh", 6);
	return 0;
}