#include "iostream"
#include "vector"
#include <map>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
	int findNthDigit(int n) {
		int digit = 1;
		long start = 1;
		long count = 9;
		while (n > count) { // 1.
			n -= count;
			digit += 1;
			start *= 10;
			count = digit * start * 9;
		}
		long num = start + (n - 1) / digit; // 2.
		return to_string(num).at((n - 1) % digit) - '0'; // 3.
	}
};

int main() {
	Solution *solution = new Solution();
	cout << solution->findNthDigit(11);
	return 0;
}