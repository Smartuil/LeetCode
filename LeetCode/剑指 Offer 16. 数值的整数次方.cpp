#include "iostream"
#include "vector"
#include <algorithm>
using namespace std;

class Solution {
public:

	double fastPow(double x, long long n) {
		if (n == 0) {
			return 1.0;
		}
		double half = fastPow(x, n / 2);
		if (n % 2 == 0) {
			return half * half;
		}
		else {
			return half * half * x;
		}
	}

	double myPow(double x, int n) {
		if (n == 0) {
			return 1;
		}
		double ret = fastPow(x, abs(n));
		if (n < 0) {
			return 1 / ret;
		}
		return ret;
	}
};

int main() {
	Solution *solution = new Solution();
	cout << solution->myPow(2.100000, 3);
	return 0;
}