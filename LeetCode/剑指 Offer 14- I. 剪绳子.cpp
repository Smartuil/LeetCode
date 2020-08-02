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
		int ret = 1;
		while (n > 4) {
			ret *= 3;
			n -= 3;
		}
		if (n) {
			ret *= n;
		}
		
		return ret;
	}
};

int main() {
	Solution *solution = new Solution();
	cout << solution->cuttingRope(15);
	return 0;
}