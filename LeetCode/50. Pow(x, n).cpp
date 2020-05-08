#include "iostream"

using namespace std;

//class Solution {
//public:
//	double myPow(double x, int n) {
//		long long N = n;
//		if (N < 0) {
//			x = 1 / x;
//			N = -N;
//		}
//		double ans = 1;
//		for (long long i = 0; i < N; i++)
//			ans = ans * x;
//		return ans;
//	}
//};

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
		long long N = n;
		if (N < 0) {
			x = 1 / x;
			N = -N;
		}
		return fastPow(x, N);
	}
};

int main() {
	Solution *solution = new Solution;
	cout << solution->myPow(99.99999, INT_MAX - 1);
	return 0;
}