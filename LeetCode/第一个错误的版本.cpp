#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include <queue>
using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		int left = 1;
		int right = n;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (isBadVersion(mid)) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}
		return left;
	}
};

int main() {
	Solution *solution = new Solution();
	cout << solution->firstBadVersion(5);
	return 0;
}