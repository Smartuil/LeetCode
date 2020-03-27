#include "iostream"
#include "string"
#include "algorithm"

using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		int ret = 0;
		if (needle.size() == 0) {
			return 0;
		}
		ret = haystack.find(needle);
		return ret;
	}
};

int main() {
	Solution *solution = new Solution();
	int len = solution->strStr("aaaaa", "bba");
	cout << len;
	return 0;
}