#include "iostream"
#include "vector"
#include <algorithm>
using namespace std;

class Solution {
public:
	int cuttingRope(int n) {
		if (n == 1 || n == 2) {
			return 1;
		}
		if (n == 3) {
			return 2;
		}
		long ret = 1;
		while (n > 5) {
			ret %= 1000000007;
			ret = ret * 3 % 1000000007;
			n -= 3;
		}

		if (n == 5) ret *= 2 * 3;
		else if (n == 4) ret *= 2 * 2;
		else if (n == 3) ret *= 3;
		ret %= 1000000007;
		return ret;
	}
};

int main() {
	Solution *solution = new Solution();
	cout << solution->cuttingRope(15);
	return 0;
}