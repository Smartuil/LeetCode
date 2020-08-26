#include "iostream"
#include "string"
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool oneEditAway(string first, string second) {
		if (first == second) {
			return true;
		}
		int len1 = first.size();
		int len2 = second.size();
		if (abs(len2 - len1) > 1) {
			return false;
		}
		int i = 0;
		int j = len1 - 1;
		int k = len2 - 1;
		while (i < len1 && i < len2 && first[i] == second[i]) {
			++i;
		}
		while (j >= 0 && k >= 0 && first[j] == second[k]) {
			--j;
			--k;
		}
		return j - i < 1 && k - i < 1;
	}
};

int main() {
	Solution *solution = new Solution();
	cout << solution->oneEditAway("pale", "ple");
	return 0;
}