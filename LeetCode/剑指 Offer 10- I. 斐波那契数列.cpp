#include "iostream"

using namespace std;

class Solution {
public:
	/*int fib(int n) {
		if (n == 0)return 0;
		if (n == 1)return 1;
		int a = 1, b = 0;
		for (int i = 1; i < n; i++) {
			a = a + b;
			b = a - b;
			a %= 1000000007;
		}
		return a;
	}*/

	int fib(int n) {
		int a = 0, b = 1, sum;
		for (int i = 0; i < n; i++) {
			sum = (a + b) % 1000000007;
			a = b;
			b = sum;
		}
		return a;
	}
};

int main() {
	Solution *solution = new Solution();
	cout << solution->fib(100);
	return 0;
}