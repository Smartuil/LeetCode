#include "iostream"
#include "vector"
#include <algorithm>
using namespace std;

class Solution {
public:

	//double fastPow(double x, long long n) {
	//	if (n == 0) {
	//		return 1.0;
	//	}
	//	double half = fastPow(x, n / 2);
	//	if (n % 2 == 0) {
	//		return half * half;
	//	}
	//	else {
	//		return half * half * x;
	//	}
	//}

	//double myPow(double x, int n) {
	//	if (n == 0) {
	//		return 1;
	//	}
	//	double ret = fastPow(x, abs(n));
	//	if (n < 0) {
	//		return 1 / ret;
	//	}
	//	return ret;
	//}

	double fastPow(double x, long n) {
		if (n == 0) {
			return 1;
		}
		double half = fastPow(x, n / 2);
		if (n % 2 == 0) {
			return half * half * x;
		}
		else
		{
			return half * half * x;
		}
	}

	double myPow(double x, int n) {
		double ret = fastPow(x, abs(n));
		if (n > 0) {
			return ret;
		}
		else
		{
			return 1 / ret;
		}
	}
};

int main() {
	Solution *solution = new Solution();
	cout << solution->myPow(2.00000, -2147483648);
	return 0;
}