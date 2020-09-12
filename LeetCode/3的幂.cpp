#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
	bool isPowerOfThree(int n) {
		if (n <= 0) return false;
		double a = log10(n) / log10(3);        //换底
		return  a == floor(a);         //判断换底后的log3n是否为整数，即n是否为3的倍数
	}
};

int main() {
	Solution* solution = new Solution();
	cout << solution->isPowerOfThree(15);
	return 0;
}